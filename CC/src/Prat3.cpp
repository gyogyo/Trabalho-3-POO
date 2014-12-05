#include <iostream>
#include <string>
#include <Character.hpp>
#include <Classes.hpp>
#include <Team.hpp>
#include <Equipment.hpp>
#include <Loja.hpp>
#include <CharacterSelect.hpp>
#include <deque>
#include <thread>
#include <chrono>

using namespace std;

int main(){

deque<int> rngdeque;

//Alguns personagens de RPG.
CharacterSelect* PlayerSelect = new CharacterSelect();

Loja* Shop = new Loja();

Team* Teams[2];
Teams[0] = new Team("Red",red);
Teams[1] = new Team("Blue",blue);

bool Menu = true;
//Montar rodada e times.
rngdeque.clear();
for(int i=0; i<10; i++) rngdeque.push_back(i);
while(Menu)
{
	int Option, numchars, chosen;
	bool mode;
	cout << "\033[2J\033[1;1H";
	string Greet = "Luka to Jojo no RPG:";
	string Err =  "Opção Inválida. Escolha novamente";
	cout << Greet << endl;
	cout << "Menu principal:\n0 - Escolher novo time\n1 - Loja de armas e armaduras\n2 - Loja de Pocoes\n3 - Batalhar\n4 - Checar status do Time\n5 - Sair\n\nEscolha: " << endl;
	cin >> Option;
	switch(Option){
		case 0:
			PlayerSelect->assembleTeam(Teams[0]);
			break;
		case 1:
			numchars = Teams[0]->getSize();
			chosen = 0;
			if(numchars < 1)
			{
				cout << "\033[2J\033[1;1H";
				cout << "Time sem personagens, favor escolher personagens primeiro." << endl;
				this_thread::sleep_for(std::chrono::milliseconds(2000));
				break;
			}
			Shop->start(Teams[0]);
			break;
		case 2:

			numchars = Teams[0]->getSize();
			chosen = 0;
			if(numchars < 1) 
			{
				cout << "\033[2J\033[1;1H";
				cout << "Time sem personagens, favor escolher personagens primeiro." << endl;
				this_thread::sleep_for(std::chrono::milliseconds(2000));
				break;
			}
			do{
				cout << "\033[2J\033[1;1H";
				cout << "Escolha qual personagem usara a loja: (Insira qualquer outro numero para sair)" << endl;
				for(int i = 0 ; i < numchars ; i++)
				{
					cout << i << ": " << Teams[0]->getCharacter(i)->getName() << endl;
				}
				cout << numchars << ": Sair" << endl;
				cin >> chosen;
				if(chosen==numchars)
				{
					cout << "\033[2J\033[1;1H";
					cout << "Saindo da loja" << endl;
					this_thread::sleep_for(std::chrono::milliseconds(1000));
					break;
				}
				while(chosen<0||chosen>numchars)
				{
					cout << Err << endl << "Escolha:" << endl;
					cin >> chosen;
				}
				Shop->potionShop(Players[chosen]);
				cout << endl << "Compra Finalizada.\n1 : Comprar novamente.\n2 : Sair" << endl;
				cout << "Escolha: ";
				cin >> Option;
			} while (Option == 1);

			break;

		case 3:
			cout << "Luka to Jojo no RPG: BATTLE STARTING" << endl;
			PlayerSelect->assembleEnemies(Teams[1]);
			this_thread::sleep_for(std::chrono::milliseconds(2000));
			cout << "\033[2J\033[1;1H";
			Teams[0]->fight(*Teams[1]);
			break;

		case 4:
			cout << "\033[2J\033[1;1H";
			Teams[0]->PrintInfo();
			cout << "\n\nDigite um numero qualquer para voltar: ";
			cin >> Option;
			break;
			
		case 5:
			cout << "\033[2J\033[1;1H";
			cout << "Luka to Jojo no RPG: GAME ENDING :(" << endl;
			this_thread::sleep_for(std::chrono::milliseconds(3000));
			cout << "\033[2J\033[1;1H";
			Menu = false;
			break;

		default:
		cout << Err << endl;
	}
}

//Liberar Memoria
for (int i=0;i<2;i++) delete Teams[i];
delete Shop;
return 0;
}

