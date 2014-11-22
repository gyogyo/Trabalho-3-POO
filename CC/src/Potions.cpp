#include <string>
#include <iostream>
#include <Item.hpp>
#include <Potions.hpp>
using namespace std;

Potion::Potion(string Name, double Price, int Restore) : Item(Name, Price){
restorepts = Restore;
}

Potion::Potion(Potion& Source) : Item(Source){
this->restorepts = Source.getRestorePts();
}

Potion::~Potion(){}

//Getters

int Potion::getAttackPts(){
return 0;
}

int Potion::getDefensePts(){
return restorepts;
}

int Potion::getRestorePts(){
return restorepts;
}

Character* Potion::getOwner(){
return owner;
}

//Setter

void Potion::setOwner(Character* User){
owner = User;
}

//Health Potion

HealthPotion::HealthPotion(string Name, double Price, int Health) : Potion(Name, Price, Health){
type = 1; //Indicar que esse item e do tipo Health Potion
}

HealthPotion::~HealthPotion(){}

void HealthPotion::use(){
// << "Health Potion HP/Restore/Total: " << getOwner()->getHP() << " " << getRestorePts() << " "; //Debug Print
getOwner()->addHP(getRestorePts());
//cout << getOwner()->getHP() << endl; //Debug Print
return;
}

//Mana Potion

ManaPotion::ManaPotion(string Name, double Price, int Mana) : Potion(Name, Price, Mana){
type = 2; //Indicar que esse item e do tipo Mana Potion
}

ManaPotion::~ManaPotion(){}

void ManaPotion::use(){
//cout << "Mana Potion MP/Restore/Total: " << getOwner()->getMP() << " " << getRestorePts() << " "; //Debug Print
getOwner()->addMP(getRestorePts());
//cout << getOwner()->getMP() << endl; //Debug Print
return;
}
