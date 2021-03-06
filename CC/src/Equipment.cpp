﻿#include <string>
#include <Equipment.hpp>
#include <Character.hpp>
using namespace std;

//Weapon class

Weapon::Weapon(string Name, double Price, int Attack) : Gear(Name, Price, 0)
{
	if(Attack > 9) Attack = 9; //Impor limites nos atributos
	else if (Attack < 1) Attack = 1;
	setPoints(Attack);
}

Weapon::Weapon(Weapon& Source) : Gear(Source){}

void Weapon::equip()
{
	getOwner()->equipWeapon(this);
}

//Armor class

Armor::Armor(string Name, double Price, int Defense) : Gear(Name, Price, 0)
{
	if(Defense > 20) Defense = 20; //Impor limites.
	else if (Defense < 1) Defense = 1;
	setPoints(Defense);
}

Armor::Armor(Armor& Source) : Gear(Source){}

void Armor::equip()
{
	getOwner()->equipArmor(this);
}

//Health Potion

HealthPotion::HealthPotion(string Name, double Price, int Restore) : Item(Name, Price, 0)
{
	if (Restore < 1) Restore = 0; //Limite
	setPoints(Restore);
}

HealthPotion::HealthPotion(HealthPotion& Source) : Item(Source){}

void HealthPotion::use()
{
	getOwner()->addHP(getPoints()); // usa a potion
	getOwner()->removeItem(((Item*)this)); // deleta a potion
}

int HealthPotion::check()
{
	return 1;
}

//Mana Potion

ManaPotion::ManaPotion(string Name, double Price, int Restore) : Item(Name, Price, 0)
{
	if (Restore < 1) Restore = 0; //Limite
	setPoints(Restore);
}

ManaPotion::ManaPotion(ManaPotion& Source) : Item(Source){}

void ManaPotion::use()
{
	getOwner()->addMP(getPoints()); // usa a pot
	getOwner()->removeItem(((Item*)this)); // deleta a potion
}

int ManaPotion::check()
{
	return 1;
}
