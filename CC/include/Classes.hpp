#ifndef CLASSES_H_
#define CLASSES_H_
#include <Character.hpp>
#include <string>
#include <cstdlib>

using namespace std;

class Knight : public Character {      
//Atributos

	protected:
	int power;

//Metodos

	int getAttackPoints();
	int getDefensePoints();

	public:
	Knight(string, int);
	void attack(Character*);
	void addPower(int);
};

class Wizard : public Character {      
//Atributos

	protected:
	int wisdom;

//Metodos

	int getAttackPoints();
	int getDefensePoints();

	public:
	Wizard(string, int);
	void attack(Character*);
	void addWisdom(int);
};

class Thief : public Character {      
//Atributos

	protected:
	int stealth;

//Metodos

	int getAttackPoints();
	int getDefensePoints();

	public:
	Thief(string, int);
	void attack(Character*);
	void addStealth(int);
};
#endif
