#include <string>
#include <iostream>
#include <Classes.hpp>
#include <Character.hpp>

Knight::Knight(string Name) : Character(Name){
	power = (rand()/double(RAND_MAX))*6;
	skillcost = 20;
}

Knight::Knight(string Name, int Power, int Strength, int Speed, int Dexterity, int Constitution) : Character(Name,Strength,Speed,Dexterity,Constitution){
	atkspeed = 1;
	accuracy = 90;
	skillcost = 20;
	power = Power;
}

Character* Knight::clone(){
	Character* clone = new Knight(getName(),power,strenght,speed,dexterity,constitution);
	return clone;
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

void Knight::specialAttack(Character* Enemy){ //Sol
	int RanNum, CritNum, Damage;

	int EnemyDodge = Enemy->getSpeed();

	cout << getName() << " attempts a Sol Slash on " << Enemy->getName() << "!" << endl;

	for(int i = 0; i < atkspeed; i++){
		RanNum = (rand()/double(RAND_MAX))*1000;
		CritNum = (rand()/double(RAND_MAX))*100;
		Damage = (int)((this->getAttackPoints()-Enemy->getDefensePoints()) + ((rand()%11) - 5) + power);
		if(Damage < 1) {Damage = 1;}
		if(CritNum < (dexterity)) {Damage *= 2;}
		if(RanNum > (accuracy - EnemyDodge)) {Damage = 0;}
		cout << Damage << " damage!" << endl;
		cout << getName() << " recovers " << Damage/2 << " HP!" << endl;
		Enemy->addHP(-Damage); //Tirar o dano da vida do oponente.
		addHP(Damage/2); //Suga vida
		}

	physiqueDown();
}

//

Wizard::Wizard(string Name) : Character(Name){
	wisdom = (rand()/double(RAND_MAX))*6;
	skillcost = 25;
}

Wizard::Wizard(string Name, int Wisdom, int Strength, int Speed, int Dexterity, int Constitution) : Character(Name,Strength,Speed,Dexterity,Constitution){
	atkspeed=1;
	accuracy=90;
	wisdom = Wisdom;
	skillcost = 25;
}

Character* Wizard::clone(){
	Character* clone = new Wizard(getName(),wisdom,strenght,speed,dexterity,constitution);
	return clone;
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

void Wizard::specialAttack(Character* Enemy){ //Thunder Jolt
	int RanNum, CritNum, StatusNum, Damage;

	int EnemyDodge = Enemy->getSpeed();

	for(int i = 0; i < atkspeed; i++){
		RanNum = (rand()/double(RAND_MAX))*1000;
		CritNum = (rand()/double(RAND_MAX))*100;
		StatusNum = (rand()/double(RAND_MAX))*100;
		Damage = (int)(wisdom*3);
		if(CritNum < 15) {Damage *= 2;}
		if(RanNum > (accuracy - EnemyDodge)) {Damage = 0;}
		cout << getName() << " fires a Thunder Jolt at " << Enemy->getName() << " ! " << Damage << " damage!" << endl;
		if(StatusNum < 50) {
			Enemy->setStatus(Paralyze, true);
			cout << Enemy->getName() << " has become paralyzed!" << endl;
		}
		Enemy->addHP(-Damage); //Tirar o dano da vida do oponente.
		}
}

//

Thief::Thief(string Name) : Character(Name){
	stealth = (rand()/double(RAND_MAX))*6;
	skillcost = 10;
}

Thief::Thief(string Name, int Stealth, int Strength, int Speed, int Dexterity, int Constitution) : Character(Name,Strength,Speed,Dexterity,Constitution){
	atkspeed=2;
	accuracy=70;
	stealth = Stealth;
	skillcost = 10;
}

Character* Thief::clone(){
	Character* clone = new Thief(getName(),stealth,strenght,speed,dexterity,constitution);
	return clone;
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

void Thief::specialAttack(Character* Enemy){ //Venom Strike
	int RanNum, CritNum, Damage;

	int EnemyDodge = Enemy->getSpeed();

	for(int i = 0; i < atkspeed; i++){
		RanNum = (rand()/double(RAND_MAX))*100;
		CritNum = (rand()/double(RAND_MAX))*100;
		cout << getName() << " poisons " << Enemy->getName() << "!";

		if(RanNum > 10*stealth) {
			cout << "But " << Enemy->getName() << " dodged!";
		}

		else{
			Enemy->setStatus(Poison,true);
			if(CritNum < 25) {
				Damage = 10;
				cout << "The slash inflicts " << Damage << " points of damage!";
			}
			Enemy->addHP(-Damage); //Tirar o dano da vida do oponente.
		}

	}
}

//

Duelist::Duelist(string Name) : Character(Name){
	proficiency = (rand()/double(RAND_MAX))*6;
	skillcost = 33;
}

Duelist::Duelist(string Name, int Proficiency, int Strength, int Speed, int Dexterity, int Constitution) : Character(Name,Strength,Speed,Dexterity,Constitution){
	atkspeed=3;
	accuracy=70;
	proficiency = Proficiency;
	skillcost = 33;
}

Character* Duelist::clone(){
	Character* clone = new Duelist(getName(),proficiency,strenght,speed,dexterity,constitution);
	return clone;
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

void Duelist::specialAttack(Character* Enemy){ //Astra
	int RanNum, CritNum, Damage;

	int EnemyDodge = Enemy->getSpeed();

	cout << getName() << " activates Astra Strike!" << endl;

	for(int i = 0; i < 5; i++){
		RanNum = (rand()/double(RAND_MAX))*1000;
		CritNum = (rand()/double(RAND_MAX))*100;
		Damage = (int)((this->getAttackPoints()-Enemy->getDefensePoints()) + ((rand()%11) - 5));
		if(Damage < 1) {Damage = 1;}
		if(CritNum < (dexterity)) {Damage *= 2;}
		if(RanNum > (accuracy - EnemyDodge - 10)) {Damage = 0;}
		cout << Enemy->getName() << " takes " << Damage << " damage!" << endl; //Debug Print
		Enemy->addHP(-Damage); //Tirar o dano da vida do oponente.
		}
}

//

Paladin::Paladin(string Name) : Character(Name){
	holy = (rand()/double(RAND_MAX))*6;
	skillcost = 15;
}

Paladin::Paladin(string Name, int Holy, int Strength, int Speed, int Dexterity, int Constitution) : Character(Name,Strength,Speed,Dexterity,Constitution){
	atkspeed=1;
	accuracy=80;
	holy = Holy;
	skillcost = 15;
}

Character* Paladin::clone(){
	Character* clone = new Paladin(getName(),holy,strenght,speed,dexterity,constitution);
	return clone;
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

void Paladin::specialAttack(Character* Enemy){ //Holy Retribution
	int Damage;
	for(int i = 0; i < atkspeed; i++){
		Damage = holy*2;
		if(status & 1) {
			setStatus(Poison,0);
			Damage *= 2;
			}
		if(status & 2) {
			setStatus(Paralyze,0);
			Damage *= 2;
			}
		cout << getName() << " retributes his status towards " << Enemy->getName() << " dealing " << Damage << " damage!" << endl;
		Enemy->addHP(-Damage); //Tirar o dano da vida do oponente.
		}
}

