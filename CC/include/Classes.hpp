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
	Knight(string);
	Knight(string, int, int, int, int, int);
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
	Wizard(string);
	Wizard(string, int, int, int, int, int);
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
	Thief(string);
	Thief(string, int, int, int, int, int);
	void attack(Character*);
	void addStealth(int);
};

class Duelist : public Character {      
//Atributos

	protected:
	int proficiency;

//Metodos

	int getAttackPoints();
	int getDefensePoints();

	public:
	Duelist(string);
	Duelist(string, int, int, int, int, int);
	void attack(Character*);
	void addProficiency(int);
};

class Paladin : public Character {      
//Atributos

	protected:
	int holy;

//Metodos

	int getAttackPoints();
	int getDefensePoints();

	public:
	Paladin(string);
	Paladin(string, int, int, int, int, int);
	void attack(Character*);
	void addHoly(int);
};
#endif
