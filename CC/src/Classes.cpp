#include <string>
#include <iostream>
#include <Classes.hpp>
#include <Character.hpp>

Knight::Knight(string Name, int Power) : Character(Name){
power = Power;
}

//O gerador de numeros aleatorios dessa funcao ja calcula em porcentagem. (De 0 a 100)
//A escolha de evitar numeros fracionados foi feita para simplificacao.
//A chance de ataque critico e 0.02 * (XP/2) = 0.01 * XP = XP%
//A chance de erro e 0.1/XP = (10/XP)%
//Essas chances serao ativadas se o RNG gerar um numero porcentual menor que as formulas.

void Knight::attack(Character* Enemy){
int RanNum = (rand()/double(RAND_MAX))*1000;
int CritNum = (rand()/double(RAND_MAX))*100;
int Damage;
Damage = (int)((getAttackPoints()-Enemy->getDefensePoints()) + ((rand()%11) - 5));
if(Damage < 1) {Damage = 1;}
if(CritNum < (XP)) {Damage *= 2;}
if(RanNum < (100/XP)) {Damage = 0;}
//cout << alias << " attacks " << Enemy->getName() << " ! " << Damage << " damage!" << endl; //Debug Print
Enemy->addHP(-Damage); //Tirar o dano da vida do oponente.
}


void Knight::addPower(int Amount){
if((power+Amount)>99) power = 100;
else power += Amount;
}

int Knight::getDefensePoints(){
int Base = Character::getDefensePoints();
return Base+power; //Somar power no total de defesa.
}

int Knight::getAttackPoints(){
return Character::getAttackPoints();
}

//

Wizard::Wizard(string Name, int Wisdom) : Character(Name){
wisdom = Wisdom;
}

void Wizard::attack(Character* Enemy){
int RanNum = (rand()/double(RAND_MAX))*1000;
int CritNum = (rand()/double(RAND_MAX))*100;
int Damage;
Damage = (int)((getAttackPoints()-Enemy->getDefensePoints()) + ((rand()%11) - 5));
if(Damage < 1) {Damage = 1;}
if(CritNum < (XP)) {Damage *= 2;}
if(RanNum < (100/XP)) {Damage = 0;}
//cout << alias << " attacks " << Enemy->getName() << " ! " << Damage << " damage!" << endl; //Debug Print
Enemy->addHP(-Damage);
}


void Wizard::addWisdom(int Amount){
if((wisdom+Amount)>99) wisdom = 100;
else wisdom += Amount;
}

int Wizard::getDefensePoints(){
int Base = Character::getDefensePoints();
return Base+(wisdom/2); //Somar metade de wisdom na defesa.
}

int Wizard::getAttackPoints(){
return Character::getAttackPoints();
}

//

Thief::Thief(string Name, int Stealth) : Character(Name){
stealth = Stealth;
}

void Thief::attack(Character* Enemy){
int RanNum = (rand()/double(RAND_MAX))*1000;
int CritNum = (rand()/double(RAND_MAX))*100;
int Damage;
Damage = (int)((getAttackPoints()-Enemy->getDefensePoints()) + ((rand()%11) - 5));
if(Damage < 1) {Damage = 1;}
if(CritNum < (XP)) {Damage *= 2;}
if(RanNum < (100/XP)) {Damage = 0;}
//cout << alias << " attacks " << Enemy->getName() << " ! " << Damage << " damage!" << endl; //Debug Print
Enemy->addHP(-Damage);
}


void Thief::addStealth(int Amount){
if((stealth+Amount)>99) stealth = 100;
else stealth += Amount;
}

int Thief::getDefensePoints(){
return Character::getDefensePoints();
}

int Thief::getAttackPoints(){
int Base = Character::getAttackPoints();
return Base + stealth; //Somar stealth no ataque. Mas essa soma faria mais sentido se fosse Assassin, não thief. :v
}

