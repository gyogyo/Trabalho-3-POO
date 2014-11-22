#ifndef ITEM_H_
#define ITEM_H_

#include <string>
//#include <Character.hpp>
using namespace std;

class Item {
//Atributos
	private:
	string name;
	double price;
	//Character* owner; //Item não pode ter Character no codigo porque faz recursao infinita.

	protected:
	int type; //Tipo do item a ser usado. 1 = HealthPotion, 2 = ManaPotion.
//Metodos
	public:
	Item(string, double);
	Item(Item&);
	string getName();
	double getPrice();
	int getType();
	//void setOwner(Character*); //Seria muito melhor se isso funcionasse, mas nao da.
	//Character* getOwner(); //Porque se fosse, Item precisa de Character que precisa de Inventory que precisa de Item.
	virtual void use() = 0;
	virtual int getAttackPts() = 0; //Sem funcao
	virtual int getDefensePts() = 0; //Sem funcao
};


#endif
