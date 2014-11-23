#ifndef EQUIPMENT_H_
#define EQUIPMENT_H_

#include <Item.hpp>
#include <string>
using namespace std;

class Weapon : public Item {
//Metodos
	public:
	Weapon(string,double,int);
	Weapon(Weapon&);
	void use();
};

class Armor : public Item {
//Metodos
	public:
	Armor(string,double,int);
	Armor(Armor&);
	void use();
};

class HealthPotion : public Item {
//Metodos
	public:
	HealthPotion(string,double,int);
	HealthPotion(HealthPotion&);
	~HealthPotion();
	virtual void use();
};

class ManaPotion : public Item {
//Metodos
	public:
	ManaPotion(string,double,int);
	ManaPotion(ManaPotion&);
	~ManaPotion();
	virtual void use();
};

#endif
