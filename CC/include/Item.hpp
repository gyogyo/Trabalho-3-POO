#ifndef ITEM_H_
#define ITEM_H_

#include <string>
class Character;
using namespace std;

class Item {

//Atributos
	private:
	string name;
	double price;
	int points; //Pontos a serem interpretados pelas classes filhas.
	Character* owner;

	void setPoints(int); //Setter de pontos interno da classe.

//Metodos
	public:
	Item(string, double, int);
	Item(Item&);
	void setOwner(Character*);
	string getName();
	double getPrice();
	int getPoints();
	Character* getOwner();
	virtual void use() = 0;
};


#endif
