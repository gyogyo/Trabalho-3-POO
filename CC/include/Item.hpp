#ifndef ITEM_H_
#define ITEM_H_
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
class Character;
using namespace std;

class Item {

//Atributos
	private:
	string name;
	double price;
	int points; //Pontos a serem interpretados pelas classes filhas.
	Character* owner;

	 //Setter de pontos interno da classe.

//Metodos
	public:
	void setPoints(int);
	Item(string, double, int);
	Item(Item&);
	//Setter
	void setOwner(Character*);
	//Getters
	string getName();
	double getPrice();
	int getPoints();
	Character* getOwner();
	//Funçoes proprias de item
	virtual void use() = 0;
	virtual void equip();
};


#endif
