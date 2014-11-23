#include <string>
#include <iostream>
#include <Classes.hpp>
#include <Character.hpp>

Knight::Knight(string Name) : Character(Name){
	power = (rand()/double(RAND_MAX))*6;
}

Knight::Knight(string Name, int Power, int Strength, int Speed, int Dexterity, int Constitution) : Character(Name,Strength,Speed,Dexterity,Constitution){
	atkspeed = 1;
	accuracy = 90;
	power = Power;
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
	int Base = Character::getAttackPoints();
	return Base+(willpower*power);
}

//

Wizard::Wizard(string Name) : Character(Name){
	wisdom = (rand()/double(RAND_MAX))*6;
}

Wizard::Wizard(string Name, int Wisdom, int Strength, int Speed, int Dexterity, int Constitution) : Character(Name,Strength,Speed,Dexterity,Constitution){
	atkspeed=1;
	accuracy=90;
	wisdom = Wisdom;
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
	int Base = Character::getAttackPoints();
	return Base + (willpower*(2*wisdom));
}

//

Thief::Thief(string Name) : Character(Name){
	stealth = (rand()/double(RAND_MAX))*6;
}

Thief::Thief(string Name, int Stealth, int Strength, int Speed, int Dexterity, int Constitution) : Character(Name,Strength,Speed,Dexterity,Constitution){
	atkspeed=2;
	accuracy=70;
	stealth = Stealth;
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
	return (Base + ((willpower * stealth)/ 2)); //Somar stealth no ataque. Mas essa soma faria mais sentido se fosse Assassin, não thief. :v
}

//

Duelist::Duelist(string Name) : Character(Name){
	proficiency = (rand()/double(RAND_MAX))*6;
}

Duelist::Duelist(string Name, int Proficiency, int Strength, int Speed, int Dexterity, int Constitution) : Character(Name,Strength,Speed,Dexterity,Constitution){
	atkspeed=3;
	accuracy=70;
	proficiency = Proficiency;
}


void Duelist::addProficiency(int Amount){
	if((proficiency+Amount)>99) proficiency = 100;
	else proficiency += Amount;
}

int Duelist::getDefensePoints(){
	return Character::getDefensePoints();
}

int Duelist::getAttackPoints(){
	int Base = Character::getAttackPoints();
	return Base + (willpower*proficiency);
}

//

Paladin::Paladin(string Name) : Character(Name){
	holy = (rand()/double(RAND_MAX))*6;
}

Paladin::Paladin(string Name, int Holy, int Strength, int Speed, int Dexterity, int Constitution) : Character(Name,Strength,Speed,Dexterity,Constitution){
	atkspeed=1;
	accuracy=80;
	holy = Holy;
}

void Paladin::addHoly(int Amount){
	if((holy+Amount)>99) holy = 100;
	else holy += Amount;
}

int Paladin::getDefensePoints(){
	int Base = Character::getDefensePoints();
	return Base+(2*holy);
}

int Paladin::getAttackPoints(){
	int Base = Character::getAttackPoints();
	return Base + (willpower*holy);
}

