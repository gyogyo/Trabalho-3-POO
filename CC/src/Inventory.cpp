#include <string>
#include <vector>
#include <iostream>
#include <Inventory.hpp>

using namespace std;

Inventory::Inventory()
{
	spaces = 10;
	gold = 500.0;
	armorequip = -1; //Nada equipado
	weaponequip[0] = -1;
	weaponequip[1] = -1;
	items = vector<pair<Item*, bool>> (0);
}

Inventory::~Inventory()
{
	int InvSize = items.size();
	for(int i=0; i<InvSize; i++) delete items[i].first;
	items.clear(); //Limpar a lista assim que for destruido.
}

//Getters

double Inventory::getTotalGold()
{
	return gold;
}

int Inventory::getAvailableSpace()
{
	return (items.size())-(items.capacity()); //Retorna espacos vazios no vector.
}

//Setters

void Inventory::spendGold(double Amount)
{
	if((gold - Amount)>=0) gold -= Amount; //Gold nao negativo.
}

void Inventory::earnGold(double Amount)
{
	gold += Amount;
}

int Inventory::size()
{
	return items.size();
}

//Enquanto o atributo spaces indica o espaca disponivel, setSpaces(int) altera o espaco absoluto.
//Se for colocado um numero menor que o tamanho atual, os items extras serao forcadamente removidos.

void Inventory::setSpaces(int Amount)
{
	if(Amount>0)
	{
		items.resize(Amount);
		spaces = (items.size())-(items.capacity());
	}
}

//Operacoes com items
//Retorna UM item com o devido nome.
template<>
Item* Inventory::searchItem<string>(string Name)
{
	int InvSize = items.size();
	for(int i=0; i<InvSize; i++)
		if(get<0>(items[i])->getName()==Name)
			return get<0>(items[i]);
	return NULL;
}

//Retorno de posicao absoluta.
template<>
Item* Inventory::searchItem<int>(int Num)
{
	if(Num < items.size())
	{
		return get<0>(items[Num]);
	}
	return NULL;
}

//Insercao ao final do inventario.

void Inventory::insertItem(Item* New)
{
	pair<Item*,bool> NewPair (New, false); //Item inicializado como desequipado.
	if(spaces>0)
	{
		items.push_back(NewPair);
		spaces--;
	}
}

//Remove TODOS os items de mesmo nome.
template<>
double Inventory::removeItem<string>(string Name)
{
	double aux=0;
	int InvSize = items.size();
	for(int i=0; i<InvSize; i++)
	{
		if(get<0>(items[i])->getName()==Name)
		{
			aux=get<0>(items[i])->getPrice();
			items.erase(items.begin()+i);
			spaces++;
		}
	}
	return aux;
}

//Remove o item com a posicao absoluta.
template<>
double Inventory::removeItem<int>(int Num)
{
	double aux = get<0>(items[Num])->getPrice();
	if(weaponequip[0]==Num)
	{
		if(weaponequip[1]!=-1)
		{
			weaponequip[0]=weaponequip[1];
			weaponequip[1]=-1;
		}
		else
		{
			weaponequip[0]=-1;
		}
	}
	else if(weaponequip[1]==Num)
	{
		weaponequip[1]=-1;
	}
	else if(armorequip==Num)
	{
		armorequip=-1;
	}
	if(Num < items.size())
	{
		items.erase(items.begin()+Num);
		spaces++;
	}
	return aux;
}

//Retorna soma total de ataque.

int Inventory::itemAtkPts()
{
	int InvSize = items.size();
	int Total=0;
	if(weaponequip[0]!=-1) Total += items[weaponequip[0]].first->getPoints();
	if(weaponequip[1]!=-1) Total += items[weaponequip[1]].first->getPoints();
	return Total;
}

//Retorna soma total de defesa.

int Inventory::itemDefPts()
{
	int InvSize = items.size();
	int Total=0;
	if(armorequip!=-1) Total += items[armorequip].first->getPoints();
	return Total;
}

void Inventory::PrintInfo()
{ //Debug Print
	string S = " ";
	cout << "Inventory: " << endl;
	int InvSize = items.size();
	for(int i=0; i<InvSize; i++)
	{
		cout << "Item " << i << " : " << get<0>(items[i])->getName() << endl
		<< "Price/Points/Equip : " << get<0>(items[i])->getPrice() <<S<< get<0>(items[i])->getPoints() <<S<< get<1>(items[i]) << endl;
		cout << "Ataque/Defesa dos items equipados: " << itemAtkPts() <<S<< itemDefPts() << endl;
	}
}

void Inventory::equipWeapon(string Select)
{
	int InvSize = items.size();
	int N = -1;
	for(int i=0; i<InvSize; i++)
		if(get<0>(items[i])->getName()==Select) //Procurar arma no inventario
			N = i;
	if(weaponequip[1]!=-1) get<1>(items[weaponequip[1]]) = false; //Se tinha uma arma no segundo slot, desequipar.
	if(weaponequip[0]!=-1) weaponequip[1] = weaponequip[0]; //Jogar arma do primeiro slot pro segundo.
	if(N!=-1) get<1>(items[N]) = true; //Se esta equipando uma arma valida, settar bool.
	weaponequip[0] = N; //Colocar novo equipamento no primeiro slot. Esse algoritmo fica fazendo ciclos com as armas que sao equipadas.
}


void Inventory::equipArmor(string Select)
{
	int InvSize = items.size();
	int N = -1;
	for(int i=0; i<InvSize; i++)
		if(get<0>(items[i])->getName()==Select) //Procurar armadura no inventario
			N = i;
	if(armorequip!=-1) get<1>(items[armorequip]) = false; //Se tinha armadura equipada, tirar.
	if(N!=-1) get<1>(items[N]) = true; //Equipar nova armadura.
	armorequip = N; //Colocar equip no slot.
}
