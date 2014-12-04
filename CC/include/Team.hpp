#ifndef TEAM_H_
#define TEAM_H_

#include <Character.hpp>
#include <string>
#include <vector>
#include <Enum.hpp>

using namespace std;

class Team {

	private:
	string name;
	int color; //Cores nomeadas no Enum
	int win;
	int lose;
	int draw;
	vector<Character*> characters;

	public:
	Team(string,int);
	~Team();
	string getName();
	string getResults();
	Character* getCharacter(int);
	int getPoints();
	int getSize();
	string toString();
	void fight(Team&);
	int resolveBattle(Team&);
	void addChar(Character*);
	void clear();
	void removeChar(int);
	void removeChar(Character*);
	Character* searchChar(string);
	void PrintInfo(); //Debug Print
	void printCharacters();

};

#endif
