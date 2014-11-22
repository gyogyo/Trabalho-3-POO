#ifndef POTIONS_H_
#define POTIONS_H_

#include <Item.hpp>
#include <Character.hpp>
#include <string>
using namespace std;

class Potion : public Item {    
//Atributos
	private:
	int restorepts;
	Character* owner; //Em quem a pocao surte efeito.
//Metodos
	public:
	Potion(string,double,int);
	Potion(Potion&);
	~Potion();
	int getRestorePts();
	void setOwner(Character*); //Colocar dono so depois da criacao.
	Character* getOwner();
	virtual void use() = 0;
	virtual int getAttackPts();
	virtual int getDefensePts();

};

class HealthPotion : public Potion {    
//Metodos
	public:
	HealthPotion(string,double,int);
	~HealthPotion();
	virtual void use();
};

class ManaPotion : public Potion {    
//Metodos
	public:
	ManaPotion(string,double,int);
	~ManaPotion();
	virtual void use();
};

#endif
