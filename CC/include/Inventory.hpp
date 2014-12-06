#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <string>
#include <utility>
#include <vector>
#include <Item.hpp>

using namespace std;
class Inventory {   
//Atributos
	private:
	int spaces;
	double gold;
	vector<pair<Item*, bool>> items; //Pair para fazer um vector de 'dois' elementos.
	int armorequip; //Variaveis para os dados de equipamento
	int weaponequip[2]; //Quais armas estao equipadas

//Metodos
	public:
	Inventory();
	~Inventory();

	//Getters
	double getTotalGold();
	int getAvailableSpace();

	//Setters
	void spendGold(double);
	void earnGold(double);


	//Enquanto o atributo spaces indica o espaco disponivel, setSpaces(int) altera o espaco absoluto.
	//Se for colocado um número menor que o tamanho atual, os items extras serao forcadamente removidos.
	void setSpaces(int);
	int size();

	//Operacoes com items
	//Retorna UM item com o devido nome.
	template <typename T>
	Item* searchItem(T);
	//Retorno de posicao absoluta.
	//Insercao ao final do inventario.
	void insertItem(Item*);
	//Remove o item e retorna o preço do mesmo
	template <typename T>
	double removeItem(T);


	//Retorna soma total de ataque.
	int itemAtkPts();
	//Retorna soma total de defesa.
	int itemDefPts();

	void PrintInfo(); //Debug Print
	void equipWeapon(string); //Funcao para equipar arma e armadura no personagem.
	void equipArmor(string);

};


#endif
