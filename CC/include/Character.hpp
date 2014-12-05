#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <string>
#include <cstdlib>
#include <Inventory.hpp>
#include <Enum.hpp>
using namespace std;

class Character {

//Atributos
	private:
	string alias;
	Inventory myitems;
	int HP;
	int MP;

	protected:
	int strenght;
	int basespeed; //Membro adicionado, é o valor da velocidade do personagem sem modificadores de armadura.
	int speed; //Velocidade funcional.
	int dexterity;
	int constitution;
	int atkspeed; // nro de hits por turno do personagem
	int accuracy; // accuracy
	int willpower;
	int status;
	int skillcost;

//Metodos
	public:
	Character(string);
	Character(string,int,int,int,int);
	void randomGenerate();
	//Getters
	string getName();
	int getHP();
	int getMP();
	int getSpeed();
	int getStatus();
	int getSkillCost();

	//Setters
	void setStrenght(int, bool);
	void setSpeed(int, bool);
	void setDexterity(int, bool);
	void setConstitution(int, bool);
	void setAttackSpeed(int);
	void addHP(int);
	void addMP(int);
	void physiqueUp();
	void physiqueDown();
	void setStatus(int,bool);

	//Funcao Debug
	void PrintInfo();
	void PrintItemsInfo();

	//Manipulacao de items e inventario
	void getItem(Item*);
	double getTotalGold();
	void spendGold(double);
	void equipWeapon(Item*);
	void equipArmor(Item*);
	void useItem(Item*);
	void useItem(int);

	//Calculo de batalha
	virtual void attack(Character*);
	virtual void specialAttack(Character*);
	virtual int getDefensePoints();
	virtual int getAttackPoints();

};



#endif
