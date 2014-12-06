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
	status = 0;
	skillcost = 0;
	randomGenerate();
}

Character::Character(string Name,int Strength,int Speed,int Dexterity,int Constitution){
	alias=Name;
	HP = 100;
	MP = 100;
	willpower=1;
	status = 0;
	skillcost = 0;
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
	accuracy = ((rand()/double(RAND_MAX))*70) + 30;

}

Character* Character::clone(){
	Character* clone = new Character(alias,strenght,speed,dexterity,constitution);
	return clone;
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

int Character::getStatus(){
	return status;
}

int Character::getSkillCost(){
	return skillcost;
}

int Character::getSkillPts(){
	return skillpts;
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

void Character::setStrenght(int Amount, bool Add){
	if(Add){
	if((strenght+Amount)>0&&(strenght+Amount)<101) strenght += Amount;
	}
	else if(Amount>0&&Amount<101) strenght = Amount;
}

void Character::setSpeed(int Amount, bool Add){
	if(Add){
	if((basespeed+Amount)>0&&(basespeed+Amount)<101) basespeed += Amount;
	}
	else if(Amount>0&&Amount<101) basespeed = Amount;
}

void Character::setDexterity(int Amount, bool Add){
	if(Add){
	if((dexterity+Amount)>0&&(dexterity+Amount)<101) dexterity += Amount;
	}
	else if(Amount>0&&Amount<101) dexterity = Amount;
}

void Character::setConstitution(int Amount, bool Add){
	if(Add){
	if((constitution+Amount)>0&&(constitution+Amount)<101) constitution += Amount;
	}
	else if(Amount>0&&Amount<101) constitution = Amount;
}

void Character::setAttackSpeed(int Amount){
	if(Amount>0&&Amount<6) atkspeed = Amount;
}


void Character::physiqueUp(){
	if(willpower==1){
		willpower=2;
		cout << alias << " gathers strenght! " << willpower << " units of power boost!" << endl;
	}

	else if(willpower==2){
		willpower=5;
		cout << alias << " gathers strenght! " << willpower << " units of power boost!" << endl;
	}
	else{
		cout << alias << " tries to gather strenght, but fails!" << endl << alias << "is already at max power!" <<endl;
	}
}

void Character::physiqueDown(){
	willpower=1;
}

void Character::setStatus(int Which, bool Flag){ //Flag é um bool, Which é o bit de qual status modificar
	if(Flag && !(status & Which))
		status += Which;
	else if(!Flag && (status & Which))
		status -= Which;
}

void Character::addSkillPts(int Amount){
	skillpts += Amount;
}

void Character::PrintInfo(){ //Debug Print
	string S = " "; //String Macro de espaco para escrever menos.
	cout
	<< "Nome: " << alias << endl
	<< "HP: " << HP << "\nStr: " << strenght << "\nSpd: " << speed << "\nDex: " << dexterity << "\nCon: " << constitution << S << endl;
	cout << "Atk: " << getAttackPoints() <<"\nDef: "<< getDefensePoints() << endl << endl;
	cout << endl << "Pontos de status remanescentes: " << skillpts << endl;
}

void Character::PrintItemsInfo(){ //Debug Print
	myitems.PrintInfo();
}

double Character::getTotalGold(){
	return myitems.getTotalGold();  
}

void Character::spendGold(double a){
	myitems.spendGold(a);  
}

void Character::earnGold(double a){
	myitems.earnGold(a);  
}

int Character::size(){
	return myitems.size();  
}

void Character::getItem(Item* New){
	New->setOwner(this);
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

template<>
void Character::useItem<Item*>(Item* Use){
	if(myitems.searchItem(Use->getName())==NULL) return; //Se esse item estiver no inventorio
	Use->use();
}

template<>
void Character::useItem<int>(int Select){
	Item* Selected = myitems.searchItem(Select);
	if(Selected==NULL) return; //Se esse item estiver no inventorio
	Selected->use();
}

void Character::equipItem(int Select){
	Item* Selected = myitems.searchItem(Select);
	if(Selected==NULL) return; //Se esse item estiver no inventorio
	Selected->equip();
}

template<>
double Character::removeItem<int>(int Select){
	return myitems.removeItem(Select);
}

template<>
double Character::removeItem<Item*>(Item* Select){
	return myitems.removeItem(Select->getName());
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


void Character::block(bool Guard){
	if(Guard) cout << alias << " assumed a defensive stance!" << endl;
	else cout << alias << " has left his guard down!" << endl;
	guard = Guard;
}

bool Character::isBlocking(){
	return guard;
}

//O gerador de numeros aleatorios dessa funcao ja calcula em porcentagem. (De 0 a 100)
//A escolha de evitar numeros fracionados foi feita para simplificacao.
//A chance de ataque critico e 0.02 * (XP/2) = 0.01 * XP = XP%
//A chance de erro e 0.1/XP = (10/XP)%
//Essas chances serao ativadas se o RNG gerar um numero porcentual menor que as formulas.

void Character::attack(Character* Enemy){
	int RanNum, CritNum, Damage;

	int EnemyDodge = Enemy->getSpeed()/2;

	cout << alias << " attacks " << Enemy->getName() << "!" << endl;

	for(int i = 0; i < atkspeed; i++)
	{
		RanNum = (rand()/double(RAND_MAX))*100;
		CritNum = (rand()/double(RAND_MAX))*100;
		Damage = (int)((this->getAttackPoints()-Enemy->getDefensePoints()) + ((rand()%11) - 5));
		if(Damage < 1) {Damage = 1;}
		if(CritNum < (dexterity)) {Damage *= 2;}
		if(Enemy->isBlocking()) Damage /= 2;
		if(RanNum > (accuracy - EnemyDodge))
		{
			Damage = 0;
			cout << Enemy->getName() << " dodged!" << endl;
		}
		else
		{
			cout << Damage << " damage!" << endl; //Debug Print
		}
		Enemy->addHP(-Damage); //Tirar o dano da vida do oponente.
	}

	physiqueDown();
}

void Character::specialAttack(Character* Target){cout << "Default Special??" << endl;}
