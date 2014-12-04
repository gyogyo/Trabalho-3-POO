#include <iostream>
#include <string>
#include <Character.hpp>
#include <Classes.hpp>
#include <Team.hpp>
#include <Equipment.hpp>
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

Team* Teams[2];
Teams[0] = new Team("Red",red);
Teams[1] = new Team("Blue",blue);

Item* Weapons[3];
Item* Armors[3];
Item* HPotions[3];
Item* MPotions[3];

Armors[0] = new Armor("Couraça de Bonbril", 50, 3);
Armors[1] = new Armor("Couraça de Ferro", 100, 6);
Armors[2] = new Armor("Couraça de Aço", 150, 9);

Weapons[0] = new Weapon("Tanto", 100, 3);
Weapons[1] = new Weapon("Wakizashi", 200, 6);
Weapons[2] = new Weapon("Nodachi", 300, 9);

HPotions[0] = new HealthPotion("Pocao Pequena de Vida", 50, 20);
HPotions[1] = new HealthPotion("Pocao Media de Vida", 100, 40);
HPotions[2] = new HealthPotion("Pocao Grande de Vida", 150, 60);
HPotions[3] = new HealthPotion("Pocao de Yggdrasil", 200, 100);

MPotions[0] = new ManaPotion("Pocao Pequena De Mana", 100, 30);
MPotions[1] = new ManaPotion("Pocao Media De Mana", 200, 60);
MPotions[2] = new ManaPotion("Pocao Grande De Mana", 300, 100);

bool Menu = true;
//Montar rodada e times.
rngdeque.clear();
for(int i=0; i<10; i++) rngdeque.push_back(i);
while(Menu)
{
	int Option, numchars, chosen, mode;
	Item* Compra;
	cout << "\033[2J\033[1;1H";
	string Greet = "Luka to Jojo no RPG:";
	string Err =  "Opção Inválida. Escolha novamente";
	cout << Greet << endl;
	cout << "Menu principal:\n0 - Escolher novo time\n1 - Loja de armas e armaduras\n2 - Loja de Pocoes\n3 - Batalhar\n4 - Sair\n\nEscolha: " << endl;
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
				mode = 2;
				do
				{
					switch(mode)
					{
						case 0:
							cout << "\033[2J\033[1;1H";
							cout << "Escolha uma armadura para " << Players[chosen]->getName() << ":\nGold Disponivel: " << Players[chosen]->getTotalGold() << "\nO que deseja comprar?" << endl;
							cout << "Armaduras               |Defesa|Preco|Nro da Opcao|" << endl;
							cout << "Couraça de Bonbril      |     3|   50|           0|" << endl;
							cout << "Couraça de Ferro   	|     6|  100|           1|" << endl;
							cout << "Couraça de Aço     	|     9|  150|           2|" << endl;
							cout << "3 : Escolher uma arma\n4 : Sair\n\nEscolha: " << endl;
							cin >> Option;
							if(Option==4)
							{
								cout << "\033[2J\033[1;1H";
								cout << "Saindo da loja" << endl;
								this_thread::sleep_for(std::chrono::milliseconds(1000));
								mode=3;
								break;
							}
							while(Option<0||Option>3)
							{
								cout << Err << endl << "Escolha:" << endl;
								cin >> Option;
							}
							if(Option!=3)
							{
								if(Players[chosen]->getTotalGold()>Armors[Option]->getPrice())
								{
									Compra = new Armor(*(Armor*)Armors[Option]); // construtor de copia
									Players[chosen]->getItem(Compra);
									Players[chosen]->equipArmor(Compra);
									Players[chosen]->spendGold(Armors[Option]->getPrice());
								}
								else
								{
									cout << endl << "Gold Insuficiente.";
									this_thread::sleep_for(std::chrono::milliseconds(2000));
								}		
							}
							else
							{
								mode=1;
								break;
							}
							cout << "\033[2J\033[1;1H";
							cout << "Acesso concluido. O que deseja?\n0 : Equipar uma arma\n1 : Equipar outro personagem\n2 : Sair\nEscolha: " << endl;
							cin >> Option;
							while(Option<0||Option>2)
							{
								cout << Err << endl << "Escolha:" << endl;
								cin >> Option;
							}
							if(Option==0)
							{
								mode=1;
								break;
							}
							if(Option==1)
							{
								mode=2;
								break;
							}
							if(Option==2)
							{
								mode=3;
								break;
							}
						case 1:	
							cout << "\033[2J\033[1;1H";
							cout << "Escolha uma arma para " << Players[chosen]->getName() << ":\nGold Disponivel: " << Players[chosen]->getTotalGold() << "\nO que deseja comprar?" << endl;
							cout << "Armas              	 |Ataque|Preco|Nro da Opcao|" << endl;
							cout << "Tanto              	 |     3|  100|           0|" << endl;
							cout << "Wakizashi             	 |     6|  200|           1|" << endl;
							cout << "Nodachi             	 |     9|  300|           2|" << endl;
							cout << "3 : Escolher uma armadura\n4 : Sair" << endl;
							cout << "\nEscolha: ";
							cin >> Option;
							if(Option==4)
							{
								cout << "\033[2J\033[1;1H";
								cout << "Saindo da loja" << endl;
								this_thread::sleep_for(std::chrono::milliseconds(1000));
								mode=3;
								break;
							}
							while(Option<0||Option>3)
							{
								cout << Err << endl << "Escolha:" << endl;
								cin >> Option;
							}
							if(Option!=3)
							{
								if(Players[chosen]->getTotalGold()>Weapons[Option]->getPrice())
								{
									Compra = new Weapon(*(Weapon*)Weapons[Option]); // construtor de copia
									Players[chosen]->getItem(Compra);
									Players[chosen]->equipWeapon(Compra);
									Players[chosen]->spendGold(Weapons[Option]->getPrice());
								}
								else
								{
									cout << endl << "Gold Insuficiente.";
									this_thread::sleep_for(std::chrono::milliseconds(2000));
								}
							}
							else
							{
								mode=0;
								break;
							}
							cout << "\033[2J\033[1;1H";
							cout << "Acesso concluido. O que deseja?\n0 : Equipar uma armadura\n1 : Equipar outro personagem\n2 : Sair\nEscolha: " << endl;
							cin >> Option;
							while(Option<0||Option>2)
							{
								cout << Err << endl << "Escolha:" << endl;
								cin >> Option;
							}
							if(Option==0)
							{
								mode=0;
								break;
							}
							if(Option==1)
							{
								mode=2;
								break;
							}
							if(Option==2)
							{
								mode=3;
								break;
							}
						case 2:
							cout << "\033[2J\033[1;1H";
							cout << "Escolha qual personagem usara a loja: (Insira qualquer outro numero para sair)" << endl;
							for(int i = 0 ; i < numchars ; i++)
							{
								cout << i << ": " << Teams[0]->getCharacter(i)->getName() << endl;
							}
							cout << numchars << " : Sair" << endl << "Escolha: ";
							cin >> chosen;
							if(chosen==numchars)
							{
								cout << "\033[2J\033[1;1H";
								cout << "Saindo da loja" << endl;
								this_thread::sleep_for(std::chrono::milliseconds(1000));
								mode=3;
								break;
							}
							while(chosen<0||chosen>numchars)
							{
								cout << Err << endl << "Escolha:" << endl;
								cin >> Option;
							}
							mode=0;
							break;
						case 3:
							cout << "Acesso concluido. O que deseja?\n0 : Equipar outro personagem\n1 : Sair\n\nEscolha: " << endl;
							cin >> Option;
							while(Option<0||Option>1)
							{
								cout << Err << endl << "Escolha:" << endl;
								cin >> Option;
							}
							if(Option==0)
							{
								mode=2;
								break;
							}
							if(Option==1)
							{
								mode=4;
								break;
							}
					}
				} while (mode!=4);
			break;
		case 2:

			numchars = Teams[0]->getSize();
			chosen = 0;
			if(numchars < 1) {
				cout << "Time sem personagens, favor escolher personagens primeiro." << endl;
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
				cout << "\033[2J\033[1;1H";
				cout << "Pocoes para " << Players[chosen]->getName() << ":\nGold Disponivel: " << Players[chosen]->getTotalGold() << "\nO que deseja comprar?" << endl;
				cout << "Poções:              |Preço| Cura|Nro da Opcao|" << endl;
				cout << "Pocao Pequena de Vida  |   50|   20|           0|" << endl;
				cout << "Pocao Media de Vida    |  100|   40|           1|" << endl;
				cout << "Pocao Grande de Vida   |  150|   60|           2|" << endl;
				cout << "Pocao de Yggdrasil     |  200|  100|           3|" << endl;
				cout << "Pocao Pequena De Mana  |  100|   30|           4|" << endl;
				cout << "Pocao Media De Mana    |  200|   60|           5|" << endl;
				cout << "Pocao Grande De Mana   |  300|  100|           6|" << endl;
				cout << "7 : Sair" << endl;
				cout << "Escolha: "; 
				cin >> Option;
				if(Option==7)
				{
					cout << "\033[2J\033[1;1H";
					cout << "Saindo da loja" << endl;
					this_thread::sleep_for(std::chrono::milliseconds(1000));
					break;
				}
				while(Option<0||Option>6)
				{
					cout << Err << endl << "Escolha:" << endl;
					cin >> Option;
				}
				if(Option!=0)
				{
					if(Option<5)
					{
						if(Players[chosen]->getTotalGold()>HPotions[Option]->getPrice())
						{
							Compra = new HealthPotion(*(HealthPotion*)HPotions[Option]); // construtor de copia
							Players[chosen]->getItem(Compra);
							Players[chosen]->spendGold(HPotions[Option]->getPrice());
						}
						else
						{
							cout << endl << "Gold Insuficiente.";
						}
					}
					else
					{
						if(Players[chosen]->getTotalGold()>MPotions[Option-4]->getPrice())
						{
							Compra = new ManaPotion(*(ManaPotion*)MPotions[Option-4]); // construtor de copia
							Players[chosen]->getItem(Compra);
							Players[chosen]->spendGold(MPotions[Option-4]->getPrice());
						}
						else
						{
							cout << endl << "Gold Insuficiente.";
						}
					}
				}
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
for (int i=0;i<3;i++) delete Armors[i];
for (int i=0;i<3;i++) delete Weapons[i];
for (int i=0;i<4;i++) delete HPotions[i];
for (int i=0;i<4;i++) delete MPotions[i];
return 0;
}

