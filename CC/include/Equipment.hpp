#ifndef EQUIPMENT_H_
#define EQUIPMENT_H_

#include <Item.hpp>
#include <Gear.hpp>
#include <string>
using namespace std;

class Weapon : public Gear {
//Metodos
	public:
	Weapon(string,double,int);
	Weapon(Weapon&);
	void equip();
};

class Armor : public Gear {
//Metodos
	public:
	Armor(string,double,int);
	Armor(Armor&);
	void equip();
};

class HealthPotion : public Item {
//Metodos
	public:
	HealthPotion(string,double,int);
	HealthPotion(HealthPotion&);
	~HealthPotion();
	virtual void use();
	int check();
};

class ManaPotion : public Item {
//Metodos
	public:
	ManaPotion(string,double,int);
	ManaPotion(ManaPotion&);
	~ManaPotion();
	virtual void use();
	int check();
};

#endif
