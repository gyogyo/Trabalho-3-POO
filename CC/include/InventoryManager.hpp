#ifndef INVMANAGER_H_
#define INVMANAGER_H_
#include "Team.hpp"
#include "Equipment.hpp"
#include "Inventory.hpp"
#include <iostream>
#include <string>

class InventoryManager
{
	private:
		Team* teamMngd;
		int mode;
		bool run;
		Character* player;
		int Option;
	public:
		InventoryManager(Team*);
		void invManage();
};
#endif
