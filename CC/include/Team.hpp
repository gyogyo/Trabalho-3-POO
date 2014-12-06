#ifndef TEAM_H_
#define TEAM_H_

#include <Character.hpp>
#include <string>
#include <vector>
#include <Enum.hpp>

using namespace std;

class Team {
	//Atributos
	private:
	string name;
	int color; //Cores nomeadas no Enum
	int win;
	int lose;
	vector<Character*> characters;
	//Métodos
	public:
	//Construtores
	Team(string,int);
	~Team();
	//Getters
	string getName();
	string getResults();
	Character* getCharacter(int);
	int getPoints();
	int getSize();
	//Print win/lose
	string toString();
	//Inicia a luta
	void fight(Team&);
	void addChar(Character*); // adiciona personagem
	void clear(); //deleta todos personagens
	void removeChar(int); // deleta personagem por posiçao
	void removeChar(Character*); // deleta personagem pela referencia
	Character* searchChar(string);
	void PrintInfo(); //Debug Print
	void printCharacters(); // Debug Print

};

#endif
