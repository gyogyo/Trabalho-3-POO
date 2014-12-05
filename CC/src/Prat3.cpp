#include <iostream>
#include <string>
#include <Character.hpp>
#include <Classes.hpp>
#include <Team.hpp>
#include <Equipment.hpp>
#include <Loja.hpp>
#include <deque>
#include <thread>
#include <chrono>

using namespace std;

int main(){

deque<int> rngdeque;

//Alguns personagens de RPG.
Character* Players[10];
Players[0] = new Knight("Rad",4,55,10,15,20);
Players[1] = new Knight("Ramza",5,40,10,10,40);
Players[2] = new Wizard("Merlin",4,40,15,35,10);
Players[3] = new Wizard("Medea",5,60,15,15,10);
Players[4] = new Thief("Lupin",3,20,30,45,5);
Players[5] = new Thief("X",4,30,20,35,15);
Players[6] = new Duelist("Zalbag",5,60,30,5,5);
Players[7] = new Duelist("Akatsuki",6,40,20,35,5);
Players[8] = new Paladin("Dycedarg",7,20,5,5,70);
Players[9] = new Paladin("Larkberg",4,25,5,15,55);

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
			cout << "\033[2J\033[1;1H";
			cout << "Escolha seus personagens dentre os abaixo:" << endl;
			for(int i = 0 ; i < 10 ; i++)
			{
				cout << "\nOpção " << i << " --------------";
				Players[i]->PrintInfo();
				cout << endl;
			}

			Teams[0]->clear();
			Teams[1]->clear();
			rngdeque.clear();
			for(int i = 0 ; i < 10; i++) rngdeque.push_back(i);

			for(int i = 0 ; i < 3 ; i++)
			{
				cout << "\nEscolha " << (3-i) << " personagens! (Nao podem ser repetidos)" << endl;
				cin >> Option;
				while(Option<0||Option>9||rngdeque[Option]!=Option)
				{
					cout << Err << endl << "Escolha:" << endl;
					cin >> Option;
				}
				rngdeque[Option]=-1;
				cout << Players[Option]->getName() << " escolhido!" << endl;
				Teams[0]->addChar(Players[Option]);
			}
			this_thread::sleep_for(std::chrono::milliseconds(700));
			cout << "\033[2J\033[1;1H";
			cout << "Time oponente escolhendo seus personagens!" << endl;
			this_thread::sleep_for(std::chrono::milliseconds(1000));
			for(int k=0;k<3;k++)
			{
				int enemyChar = rand()%10;
				while(rngdeque[enemyChar]!=enemyChar) enemyChar = rand()%10;
				rngdeque[enemyChar]=-1;
				Teams[1]->addChar(Players[enemyChar]);

			}

			cout << "Time oponente atualizado!" << endl;
			this_thread::sleep_for(std::chrono::milliseconds(1200));
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
			this_thread::sleep_for(std::chrono::milliseconds(2000));
			system("clear");
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
for (int i=0;i<10;i++) delete Players[i];
for (int i=0;i<2;i++) delete Teams[i];
delete Shop;
return 0;
}

