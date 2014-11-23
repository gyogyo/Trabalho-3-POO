#include <string>
#include <iostream>
#include <cmath>
#include <Character.hpp>
#include <Equipment.hpp>
#include <Item.hpp>

using namespace std;

Character::Character(string Name){
	alias = Name;
	HP = 100;
	MP = 100;
	willpower=1;
	randomGenerate();
}

Character::Character(string Name,int Strength,int Speed,int Dexterity,int Constitution){
	alias=Name;
	strenght = Strength;
	basespeed = speed = Speed;
	dexterity  = Dexterity;
	constitution = Constitution;
}


void Character::randomGenerate(){

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
	atkspeed = (rand()/double(RAND_MAX))*3;
	accuracy = ((rand()/double(RAND_MAX))*50) + 50;

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

int Character::getSpeed(){
	return speed;
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

void Character::setAttackSpeed(int Amount){
	if(Amount>0&&Amount<6) atkspeed = Amount;
}


void Character::physiqueUp(){
	if(willpower==1)
		willpower=2;
	else if(willpower==2)
		willpower=5;
}

void Character::physiqueDown(){
	willpower=1;
}

void Character::PrintInfo(){ //Debug Print
	string S = " "; //String Macro de espaco para escrever menos.
	cout
	<< "Alias: " << alias << endl
	<< "HP/Str/Spd/Dex/Con: " << HP <<S<< strenght <<S<< speed <<S<< dexterity <<S<< constitution <<S<< endl;
	myitems.PrintInfo();
	cout << "Atk/Def: " << getAttackPoints() <<S<< getDefensePoints() << endl << endl;
}

void Character::PrintItemsInfo(){ //Debug Print
	myitems.PrintInfo();
}

double Character::getTotalGold(){
	return myitems.getTotalGold();  
}

void Character::getItem(Item* New){
	myitems.insertItem(New);  //Colocar um item no inventario.
}

void Character::equipWeapon(Item* Select){
	//cout << Select2->getName() << " " << Select2->getRange() << endl; //Debug Print
	myitems.equipWeapon(Select->getName());
}

void Character::equipArmor(Item* Select){
	//cout << Select2->getName() << " " << Select2->getWeight() << endl; //Debug Print
	//setSpeed(basespeed*(sqrt(Select->getWeight())/10)); //Formula estranha de velocidade que aumenta velocidade com armadura mais pesada.
	myitems.equipArmor(Select->getName());
}

void Character::useItem(Item* Use){
	if(myitems.searchItem(Use->getName())==NULL) return; //Se esse item estiver no inventorio
	Use->use();
}

void Character::useItem(int Select){
	Item* Selected = myitems.searchItem(Select);
	if(Selected==NULL) return; //Se esse item estiver no inventorio
	Selected->use();
}

//Em ambas as contas, os numeros fracionados foram simplificados como fator comum de 10.
//Devido a fracoes, ha duas operacoes de truncamento que podem influenciar as contas finais.

int Character::getDefensePoints(){
	int BaseDef = (int) (((constitution*5)+(dexterity*2)+(speed*4))/10);
	return (int) (BaseDef+myitems.itemDefPts())/6;
}

int Character::getAttackPoints(){
	int BaseAtk = (int) (((strenght*5)+(dexterity*4)+(speed*2))/10);
	return (int) (BaseAtk+myitems.itemAtkPts())/2;
}

//O gerador de numeros aleatorios dessa funcao ja calcula em porcentagem. (De 0 a 100)
//A escolha de evitar numeros fracionados foi feita para simplificacao.
//A chance de ataque critico e 0.02 * (XP/2) = 0.01 * XP = XP%
//A chance de erro e 0.1/XP = (10/XP)%
//Essas chances serao ativadas se o RNG gerar um numero porcentual menor que as formulas.

void Character::attack(Character* Enemy){
	int RanNum, CritNum, Damage;

	int EnemyDodge = Enemy->getSpeed();

	for(int i = 0; i < atkspeed; i++){
		RanNum = (rand()/double(RAND_MAX))*1000;
		CritNum = (rand()/double(RAND_MAX))*100;
		Damage = (int)((this->getAttackPoints()-Enemy->getDefensePoints()) + ((rand()%11) - 5));
		if(Damage < 1) {Damage = 1;}
		if(CritNum < (dexterity)) {Damage *= 2;}
		if(RanNum > (accuracy - EnemyDodge)) {Damage = 0;}
		//cout << alias << " attacks " << Enemy->getName() << " ! " << Damage << " damage!" << endl; //Debug Print
		Enemy->addHP(-Damage); //Tirar o dano da vida do oponente.
		}

	physiqueDown();
	}
