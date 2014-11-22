#include <string>
#include <iostream>
#include <cmath>
#include <Character.hpp>
#include <Equipment.hpp>
#include <Potions.hpp>

Character::Character(string Name){
alias = Name;
HP = 100;
MP = 100;
XP = 1;

//Logica para os pontos: Ha 4 Rands() seguidos, que puxam de um total de 97 pontos cumulativos.
//O algoritmo foi feito para que sempre ao menos sobre 1 ponto, para evitar a divisao por 0.
//Desse modo, ha na verdade, 96 pontos disponiveis, ja que o minimo de cada um dos quatro atributos e 1.

int limite = 97;
strenght = ((rand()/double(RAND_MAX))*limite)+1;
limite -= (strenght-1);
basespeed = speed = ((rand()/double(RAND_MAX))*limite)+1;
limite -= (speed-1);
dexterity = ((rand()/double(RAND_MAX))*limite)+1;
limite -= (dexterity-1);
constitution = limite;
}

//Getters

string Character::getName(){
return alias;
}

int Character::getHP(){
return HP;
}

int Character::getMP(){
return MP;
}

//Setters
void Character::addXP(int Amount){
if((XP+Amount)>99) XP = 100;
else XP += Amount;
}

//Setters

void Character::addHP(int Amount){
if((HP+Amount)<0) HP = 0; //HP não negativo.
else HP += Amount;
}

void Character::addMP(int Amount){
if((MP+Amount)<0) MP = 0; //MP não negativo.
else MP += Amount;
}

void Character::setStrenght(int Amount){
if(Amount>0&&Amount<101) strenght = Amount;
}

void Character::setSpeed(int Amount){
if(Amount>0&&Amount<101) speed = Amount;
}

void Character::setDexterity(int Amount){
if(Amount>0&&Amount<101) dexterity = Amount;
}

void Character::setConstitution(int Amount){
if(Amount>0&&Amount<101) constitution = Amount;
}

void Character::PrintInfo(){ //Debug Print
string S = " "; //String Macro de espaco para escrever menos.
cout
<< "Alias: " << alias << endl
<< "HP/XP/Str/Spd/Dex/Con: " << HP <<S<< XP <<S<< strenght <<S<< speed <<S<< dexterity <<S<< constitution <<S<< endl;
myitems.PrintInfo();
cout << "Atk/Def: " << getAttackPoints() <<S<< getDefensePoints() << endl << endl;
}

void Character::getItem(Item* New){
myitems.insertItem(New);  //Colocar um item no inventario.
}

void Character::equipWeapon(Item* Select){
//Weapon* Select2 = (Weapon*) Select;
//cout << Select2->getName() << " " << Select2->getRange() << endl; //Debug Print
myitems.equipWeapon(Select/*2*/->getName());
}

void Character::equipArmor(Item* Select){
Armor* Select2 = (Armor*) Select; //Sabendo que eu vou apenas passar armaduras para essa funcao, uso esse cast.
//cout << Select2->getName() << " " << Select2->getWeight() << endl; //Debug Print
setSpeed(basespeed*(sqrt(Select2->getWeight())/10)); //Formula estranha de velocidade que aumenta velocidade com armadura mais pesada.
myitems.equipArmor(Select2->getName());
}

void Character::useItem(Item* Use){
if(myitems.searchItem(Use->getName())==NULL) return; //Se esse item estiver no inventorio
else if(Use->getType()!=0){ //Health or Mana Potion
	Potion* Pot = (Potion*) Use;
	Pot->setOwner(this);  //Se colocar como usuario
	Pot->use(); //Usar pocao
	myitems.removeItem(Use->getName()); //Remover do inventorio
	}
}

//Em ambas as contas, os numeros fracionados foram simplificados como fator comum de 10.
//Devido a fracoes, ha duas operacoes de truncamento que podem influenciar as contas finais.

int Character::getDefensePoints(){
int BaseDef = (int) (((constitution*5)+(dexterity*3)+(speed*2))/10);
return (int) ((BaseDef+myitems.itemDefPts())*XP)/6;
}

int Character::getAttackPoints(){
int BaseAtk = (int) (((strenght*5)+(dexterity*3)+(speed*2))/10);
return (int) ((BaseAtk+myitems.itemAtkPts())*XP)/2;
}
