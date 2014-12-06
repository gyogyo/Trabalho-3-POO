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
	public:
	Knight(string);
	Knight(string, int, int, int, int, int);
	Character* clone();
	virtual void specialAttack(Character*);
	void addPower(int);
	int getAttackPoints();
	int getDefensePoints();
};

class Wizard : public Character {      
//Atributos

	protected:
	int wisdom;

//Metodos
	public:
	Wizard(string);
	Wizard(string, int, int, int, int, int);
	Character* clone();
	virtual void specialAttack(Character*);
	void addWisdom(int);
	int getAttackPoints();
	int getDefensePoints();
};

class Thief : public Character {      
//Atributos

	protected:
	int stealth;

//Metodos
	public:
	Thief(string);
	Thief(string, int, int, int, int, int);
	Character* clone();
	virtual void specialAttack(Character*);
	void addStealth(int);
	int getAttackPoints();
	int getDefensePoints();
};

class Duelist : public Character {      
//Atributos

	protected:
	int proficiency;

//Metodos
	public:
	Duelist(string);
	Duelist(string, int, int, int, int, int);
	Character* clone();
	virtual void specialAttack(Character*);
	void addProficiency(int);
	int getAttackPoints();
	int getDefensePoints();
};

class Paladin : public Character {      
//Atributos

	protected:
	int holy;

//Metodos
	public:
	Paladin(string);
	Paladin(string, int, int, int, int, int);
	Character* clone();
	virtual void specialAttack(Character*);
	void addHoly(int);
	int getAttackPoints();
	int getDefensePoints();
};
#endif
