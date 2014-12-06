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
		Team* teamMngd; // team managed, ou seja, o time com o quais os personagens a classe irá editar
		int mode; // para a maquina de estados
		bool run; // maquina de estados funciona enquanto true
		Character* player; // jogador selecionado no momento
		int Option; // utilizado constantemente para selecionar a opçao
	public:
		InventoryManager(Team*);
		void invManage(); // gerencia o inventory
};
#endif
