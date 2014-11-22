#ifndef EQUIPMENT_H_
#define EQUIPMENT_H_

#include <Item.hpp>
#include <string>
using namespace std;

class Weapon : public Item {    
//Atributos
	protected:
	int attackpts;
	double range;

//Metodos
	public:
	Weapon(string,double,int,double);
	Weapon(Weapon&);
	int getAttackPts();
	int getDefensePts();
	double getRange();
	void use();
};

class Armor : public Item {    
//Atributos
	protected:
	int defensepts;
	double weight;

//Metodos
	public:
	Armor(string,double,int,double);
	Armor(Armor&);
	int getAttackPts();
	int getDefensePts();
	double getWeight();
	void use();
};

#endif
