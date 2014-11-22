#include <string>
#include <Item.hpp>
#include <Equipment.hpp>
using namespace std;

//Weapon class

Weapon::Weapon(string Name, double Price, int Attack, double Range) : Item(Name, Price){
if(Attack > 9) Attack = 9; //Impor limites nos atributos
else if (Attack < 1) Attack = 1;
attackpts = Attack;
range = Range;
}

Weapon::Weapon(Weapon& Source) : Item(Source){
this->attackpts = Source.attackpts;
this->range = Source.range;
}

//Getters

int Weapon::getDefensePts(){
return 0;
}

int Weapon::getAttackPts(){
return attackpts;
}

double Weapon::getRange(){
return range;
}

void Weapon::use(){} //Nao faz nada, porem e necessario ter pois senao seria classe puramente virtual.

//Armor class

Armor::Armor(string Name, double Price, int Defense, double Weight) : Item(Name, Price){
if(Defense > 20) Defense = 20; //Impor limites.
else if (Defense < 1) Defense = 1;
defensepts = Defense;
weight = Weight;
}

Armor::Armor(Armor& Source) : Item(Source){
this->defensepts = Source.defensepts;
this->weight = Source.weight;
}

//Getters

int Armor::getDefensePts(){
return defensepts;
}

int Armor::getAttackPts(){
return 0;
}

double Armor::getWeight(){
return weight;
}

void Armor::use(){} //Idem a weapon.
