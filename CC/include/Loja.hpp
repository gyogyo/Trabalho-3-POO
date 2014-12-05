#ifndef LOJA_H_
#define LOJA_H_

#include <string>
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>
#include "Character.hpp"
#include "Inventory.hpp"
#include "Equipment.hpp"
#include "Team.hpp"

using namespace std;


class Loja
{
	private:
		Item* Armors[3];
		Item* Weapons[3];
		Item* HPotions[4];
		Item* MPotions[3];
		Item* Compra;
		Character* player;
	public:
		Loja();
		~Loja();
		void start(Team*,int);
		void potionShop(Character*);
		int armorShop(Character*);
		int weaponShop(Character*);
};
#endif
