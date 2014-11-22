#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <string>
#include <cstdlib>
#include <Inventory.hpp>
using namespace std;

class Character {    
  
//Atributos
	private:
	string alias;
	Inventory myitems;
	int HP;
	int MP;

	protected:
	int XP;
	int strenght;
	int basespeed; //Membro adicionado, é o valor da velocidade do personagem sem modificadores de armadura.
	int speed; //Velocidade funcional.
	int dexterity;
	int constitution;
	int atkspeed; // nro de hits por turno do personagem
	int accuracy; // accuracy
	float willpower;

//Metodos
	public:
	Character(string);
	Character(string,int,int,int,int);
	//Getters
	string getName();
	int getHP();
	int getMP();

	virtual void attack(Character*) = 0;

	//Setters
	void addXP(int);
	void setStrenght(int);
	void setSpeed(int);
	void setDexterity(int);
	void setConstitution(int);
	void addHP(int);
	void addMP(int);
	void physiqueUp();
	void physiqueDown();

	//Funcao Debug
	void PrintInfo();

	//Manipulacao de items e inventario
	void getItem(Item*);
	void equipWeapon(Item*);
	void equipArmor(Item*);
	void useItem(Item*);

	//Calculo de batalha
	protected:
	virtual int getDefensePoints();
	friend class Knight;
	friend class Wizard;
	friend class Thief;
	friend class Duelist;
	friend class Paladin;
	virtual int getAttackPoints();

};



#endif
