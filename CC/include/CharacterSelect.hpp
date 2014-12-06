#ifndef CHARSELECT_H_
#define CHARSELECT_H_

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


class CharacterSelect
{
	private:
		pair<Character*,bool> players[10];
		int waveCounter; // conta quantas batalhas ja ocorreram
	public:
		CharacterSelect();
		~CharacterSelect();
		void assembleTeam(Team*);
		void assembleEnemies(Team*);
};
#endif
