#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <chrono>
#include <thread>
#include <Team.hpp>
#include <Character.hpp>

using namespace std;

Team::Team(string Name, int colour)
{
	name = Name;
	color = colour;
	win = 0;
	lose = 0;
	characters = vector<Character*> (0);
}

Team::~Team()
{
	characters.clear();
}


//Getters

string Team::getName()
{
	return name;
}

string Team::getResults()
{
	string Info = "Wins: " + to_string(win) + " Losses: " + to_string(lose);
	return Info;
}

Character* Team::getCharacter(int N)
{
	if(N < characters.size()) return characters[N];
	throw;
}

int Team::getSize()
{
	return characters.size();
}

string Team::toString()
{
	string Info = name + " " + to_string(color);
	return Info;
}

void Team::fight(Team& EnemyTeam)
{

	int FightEnd = 0;
	int Option;
	bool Turn = (characters[0]->getSpeed() < EnemyTeam.characters[0]->getSpeed())? true:false;
	while(FightEnd == 0)
	{
		if(Turn == true)
		{
			cout << "\033[2J\033[1;1H";
			cout << "Luka to Jojo no RPG:" << endl << endl << characters[0]->getName() <<": HP: "<< characters[0]->getHP() << " MP: "<< characters[0]->getMP() <<" 		vs 		MP: "<< EnemyTeam.characters[0]->getMP() << " HP: "<< EnemyTeam.characters[0]->getHP() <<"  :"<< EnemyTeam.characters[0]->getName() << "\n\nModes:\n0 - Attack\n1 - Skill\n2 - Defend\n3 - Psyche Up\n4 - Item\n5 - Analisar Inimigo" << endl;

			if(characters[0]->isBlocking()) characters[0]->block(false);

			if(characters[0]->getStatus() & Paralyze){
				cout << characters[0]->getName() << " esta paralizado!" << endl;
				characters[0]->setStatus(Paralyze,false);
			}
			else
			{
				cin >> Option;
				while(Option<0||Option>5)
				{
					cout << "Opção Inválida. Escolha novamente.\nEscolha: " << endl;
					cin >> Option;
				}
				switch(Option){
				case 0:
					characters[0]->attack(EnemyTeam.characters[0]);
					break;
				case 1:
					if(characters[0]->getMP() >= characters[0]->getSkillCost())
					{
						characters[0]->specialAttack(EnemyTeam.characters[0]);
						characters[0]->addMP(-characters[0]->getSkillCost());
					}
					else cout << "Nao ha MP disponivel para ataque especial!" << endl;
					break;
				case 2:
					characters[0]->block(true);
					break;
				case 3:
					characters[0]->physiqueUp();
					break;
				case 4:
					cout << "Escolha um item usável\n-1 - Cancel" << endl;
					characters[0]->PrintItemsInfo();
					cin >> Option;
					if(Option!=-1)
					{
						characters[0]->useItem(Option);
					}
					break;
				case 5:
					EnemyTeam.characters[0]->PrintInfo();
					EnemyTeam.characters[0]->PrintItemsInfo();
					break;
				}
			}

			if(characters[0]->getStatus() & Poison)
			{
				cout << characters[0]->getName() << " perdeu vida por causa do veneno!" << endl;
				characters[0]->addHP(-10);
				if( (rand()/double(RAND_MAX)) < 25 )
				{
					cout << characters[0]->getName() << " se curou do veneno!" << endl;
					characters[0]->setStatus(Poison, false);
				}
			}
			this_thread::sleep_for(std::chrono::milliseconds(5000));
			Turn = false;
		}
		else
		{
			cout << "\033[2J\033[1;1H";
			cout << "Luka to Jojo no RPG:" << endl << endl << characters[0]->getName() <<": HP: "<< characters[0]->getHP() << " MP: "<< characters[0]->getMP() <<" 		vs 		MP: "<< EnemyTeam.characters[0]->getMP() << " HP: "<< EnemyTeam.characters[0]->getHP() <<"  :"<< EnemyTeam.characters[0]->getName() << "\n\nTurno inimigo!" << endl;

			if(EnemyTeam.characters[0]->isBlocking()) EnemyTeam.characters[0]->block(false);

			if(EnemyTeam.characters[0]->getStatus() & Paralyze)
			{
				cout << EnemyTeam.characters[0]->getName() << " esta paralizado!" << endl;
				EnemyTeam.characters[0]->setStatus(Paralyze,false);
			}

			else
			{
				Option = (int) ((rand()/double(RAND_MAX))*4);
				switch(Option)
				{
					case 0:
						EnemyTeam.characters[0]->attack(characters[0]);
						break;
					case 1:
						if(EnemyTeam.characters[0]->getMP() >= EnemyTeam.characters[0]->getSkillCost())
						{
							EnemyTeam.characters[0]->specialAttack(characters[0]);
							EnemyTeam.characters[0]->addMP(-EnemyTeam.characters[0]->getSkillCost());
						}
						else cout << "Nao ha MP disponivel para ataque especial!" << endl;
						break;
					case 2:
						EnemyTeam.characters[0]->block(true);
						break;
					case 3:
						EnemyTeam.characters[0]->physiqueUp();
						break;
					/*case 4:
						cout << "Escolha um item usável\n-1 - Cancel" << endl;
						characters[i]->PrintItemsInfo();
						cin >> ItemOption;
						if(ItemOption!=-1){
							characters[i]->useItem(ItemOption);
						}
						break;*/
				}
			}
			
			if(EnemyTeam.characters[0]->getStatus() & Poison)
			{
				cout << EnemyTeam.characters[0]->getName() << " perdeu vida por causa do veneno!" << endl;
				EnemyTeam.characters[0]->addHP(-10);
				if( (rand()/double(RAND_MAX))*100 < 25 ){
					cout << EnemyTeam.characters[0]->getName() << " se curou do veneno!" << endl;
					EnemyTeam.characters[0]->setStatus(Poison, false);
				}
			}

			this_thread::sleep_for(std::chrono::milliseconds(5000));
			Turn = true;
		}
		// terminou ambos turnos, checa por uma derrota
		if(EnemyTeam.characters[0]->getHP() == 0) {
			cout << EnemyTeam.characters[0]->getName() << " foi derrotado!" << endl;
			EnemyTeam.characters.erase(EnemyTeam.characters.begin());
			this_thread::sleep_for(std::chrono::milliseconds(1000));
			if(EnemyTeam.getSize() < 1) FightEnd = 1;
		}

		if(characters[0]->getHP() == 0) {
			cout << characters[0]->getName() << " foi derrotado!" << endl;
			characters.erase(characters.begin());
			this_thread::sleep_for(std::chrono::milliseconds(1000));
			if(getSize() < 1) FightEnd = 2;
		}
	}

	if(FightEnd == 1)
	{
		cout << "Vitoria! Voce ganha 200 gold e 10 pontos para cada personagem!" << endl;
		for(int i = 0; i < getSize(); i++)
		{
			characters[i]->spendGold(-200);
			characters[i]->addSkillPts(10);
		}
		this_thread::sleep_for(std::chrono::milliseconds(5000));
		win += 1;
		EnemyTeam.lose += 1;
	}

	else
	{
		cout << "Derrota! Game over!" << endl;
		this_thread::sleep_for(std::chrono::milliseconds(5000));
		EnemyTeam.win += 1;
		lose += 1;
	}
}

//Operacoes com items
//Insercao de personagem no time.
void Team::addChar(Character* New)
{
	characters.push_back(New);
}

void Team::clear()
{
	characters.clear();
}

//Remove personagem do time.
void Team::removeChar(int Num)
{
	if(Num < characters.size())
		characters.erase(characters.begin()+Num);
}

//Remove TODOS os personagens de mesmo nome.
void Team::removeChar(Character* Chara)
{
	int TeamSize = characters.size();
	for(int i=0; i<TeamSize; i++)
	{
		if(characters[i]->getName()==Chara->getName())
		{
			characters.erase(characters.begin()+i);
		}
	}
}

//Retorna UM personagem com o devido nome.
Character* Team::searchChar(string Name)
{
	int TeamSize = characters.size();
	for(int i=0; i<TeamSize; i++)
	{
		if(characters[i]->getName()==Name)
		{
			return characters[i];
		}
	}
	return NULL;
}

//Retorna media do HP.
int Team::getPoints()
{
	int Points = 0;
	int TeamSize = characters.size();
	for(int i=0; i<TeamSize; i++)
		Points += characters[i]->getHP();
	return (Points/TeamSize);
}

void Team::PrintInfo()
{ //Debug Print
	string S = " ";
	cout << "Team: " << color << endl;
	cout << "Wins: " << win << " Losses: " << lose << endl;
	getResults();
	int TeamSize = characters.size();
	for(int i=0; i<TeamSize; i++)
		characters[i]->PrintInfo();
	cout << endl;
}

void Team::printCharacters()
{
	int TeamSize = characters.size();
	for(int i=0; i<TeamSize; i++)
		cout << "Personagem " << i << ": " << characters[i]->getName() << endl;
}
