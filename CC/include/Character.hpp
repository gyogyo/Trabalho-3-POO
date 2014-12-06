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
	int willpower; // multiplicador de ataque baseado no psyche up
	int status;
	int skillcost; // custo de mana da habilidade do personagem
	int skillpts; // nro de pontos para aumentar os atributos dos personagens
	bool guard; // if true => diminui dano pela metade

//Metodos
	public:
	Character(string);
	Character(string,int,int,int,int);
	void randomGenerate(); //setta atributos de forma aleatoria
	virtual Character* clone(); //construtor de copia
	//Getters
	string getName(); 
	int getHP();
	int getMP();
	int getSpeed();
	int getStatus();
	int getSkillCost();
	int getSkillPts();

	//Setters
	void setStrenght(int, bool);
	void setSpeed(int, bool);
	void setDexterity(int, bool);
	void setConstitution(int, bool);
	void setAttackSpeed(int);
	void addHP(int);
	void addMP(int);
	void physiqueUp(); // altera willpower
	void physiqueDown(); // altera willpower
	void setStatus(int,bool); // altera status (paralyzed/poisoned)
	void addSkillPts(int); // adiciona pontos de atributos para distribuir

	//Funcao Debug
	void PrintInfo();
	void PrintItemsInfo();

	//Manipulacao de items e inventario - maioria intuitiva
	int size(); // devolve quantos itens há em inventory
	void getItem(Item*);
	double getTotalGold();
	void spendGold(double);
	void earnGold(double);
	void equipWeapon(Item*);
	void equipArmor(Item*);
	template<typename T>
	void useItem(T);
	void equipItem(int);
	template<typename T>
	double removeItem(T);
	

	//Calculo de batalha
	void block(bool);
	bool isBlocking();
	virtual void attack(Character*);
	virtual void specialAttack(Character*);
	virtual int getDefensePoints();
	virtual int getAttackPoints();

};



#endif
