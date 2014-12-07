#ifndef ITEM_H_
#define ITEM_H_
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <Usable.hpp>	
class Character;
using namespace std;

class Item : public Usable
{

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
	virtual int check()=0;
	//Funçoes proprias de item
};


#endif
