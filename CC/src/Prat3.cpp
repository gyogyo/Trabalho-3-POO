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

Item* Items[23];

Items[0] = new Armor("Escudo de Ferro", 100, 3);
Items[1] = new Armor("Armadura de Ferro", 100, 3);
Items[2] = new Armor("Capacete de Ferro", 100, 3);
Items[3] = new Armor("Botas de Couro", 100, 3);
Items[4] = new Armor("Bracelete Abencoado", 500, 2);
Items[5] = new Armor("Amuleto Da Sorte", 10, 1);

Items[6] = new Weapon("Espada Lendaria", 600, 7);
Items[7] = new Weapon("Osafune", 300, 3);
Items[8] = new Weapon("Ame No Murakamo", 500, 5);
Items[9] = new Weapon("Falchion", 240, 4);
Items[10] = new Weapon("Bastao de Beisebol", 100, 4);
Items[11] = new Weapon("Foice Maligna", 600, 6);
Items[12] = new Weapon("Cajado Mistico", 900, 3);
Items[13] = new Weapon("Faca de Ferro", 100, 2);
Items[14] = new Weapon("Pistola Tranquilizadora", 800, 4);
Items[15] = new Weapon("Metralhadora", 3000, 9);

Items[16] = new HealthPotion("Pocao Pequena de Vida", 50, 20);
Items[17] = new HealthPotion("Pocao Media de Vida", 100, 40);
Items[18] = new HealthPotion("Pocao Grande de Vida", 150, 60);
Items[19] = new HealthPotion("Pocao de Yggdrasil", 200, 100);

Items[20] = new ManaPotion("Pocao Pequena De Mana", 100, 30);
Items[21] = new ManaPotion("Pocao Media De Mana", 200, 60);
Items[22] = new ManaPotion("Pocao Grande De Mana", 300, 100);
bool Menu = true;
//Montar rodada e times.
rngdeque.clear();
for(int i=0; i<10; i++) rngdeque.push_back(i);
while(Menu)
{
	int Option, numchars, chosen;
	Item* Compra;
	string Greet = "Luka to Jojo no RPG:";
	string Err =  "Opção Inválida. Escolha novamente";
	cout << Greet << endl;
	cout << "Menu principal:\n0 - Escolher Personagens\n1 - Equipamentos\n2 - Loja de Pocoes\n3 - Batalhar\n4 - Sair" << endl;
	cin >> Option;
	switch(Option){
		case 0:
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

		cout << "Time oponente escolhendo seus personagens!" << endl;

		for(int k=0;k<3;k++)
		{
			int enemyChar = rand()%10;
			while(rngdeque[enemyChar]!=enemyChar) enemyChar = rand()%10;
			rngdeque[enemyChar]=-1;
			Teams[1]->addChar(Players[enemyChar]);

		}

		cout << "Time oponente atualizado!" << endl;

		break;
		case 1:
		numchars = Teams[0]->getSize();
		chosen = 0;
		if(numchars < 1) {
			cout << "Time sem personagens, favor escolher personagens primeiro." << endl;
			break;
		}
		do{

			cout << "Escolha qual personagem usara a loja: (Insira qualquer outro numero para sair)" << endl;
			for(int i = 0 ; i < numchars ; i++)
			{
				cout << i << ": " << Teams[0]->getCharacter(i)->getName() << endl;
			}
			cin >> chosen;

			while(chosen<0||chosen>=numchars)
				{
					cout << Err << endl << "Escolha:" << endl;
					cin >> chosen;
				}

			cout << endl << "Escolha uma Armadura:" << endl;
			cout << "Armaduras:           |Defesa|Peso|Nro da Opcao|" << endl;
			cout << "Escudo de Ferro     	 |     5|  40|           0|" << endl;
			cout << "Armadura de Ferro   	 |     7|  90|           1|" << endl;
			cout << "Capacete de Ferro   	 |     3|  20|           2|" << endl;
			cout << "Botas de Couro      	 |     4|  25|           3|" << endl;
			cout << "Bracelete Abencoado 	 |     2|   5|           4|" << endl;
			cout << "Grevas de Ferro    	 |     6|  60|           5|" << endl;
			cin >> Option;
			while(Option<0||Option>5)
				{
					cout << Err << endl << "Escolha:" << endl;
					cin >> Option;
				}
			Compra = new Armor(*(Armor*)Items[Option]); // construtor de copia
			Players[chosen]->getItem(Compra);
			Players[chosen]->equipArmor(Compra);
			cout << endl << "Escolha uma Arma:" << endl;
			cout << "Armas:            	 	|Ataque|Nro da Opcao|" << endl;
			cout << "Espada Lendaria     	 	|     7|           0|" << endl;
			cout << "Osafune             	 	|     7|           1|" << endl;
			cout << "Ame No Murakamo     	 	|     7|           2|" << endl;
			cout << "Falchion            	 	|     7|           3|" << endl;
			cout << "Bastao de Beisebol  	 	|     7|           4|" << endl;
			cout << "Foice Maligna       	 	|     7|           5|" << endl;
			cout << "Cajado Mistico     	 	|     7|           6|" << endl;
			cout << "Faca de Ferro     	 	|     7|           7|" << endl;
			cout << "Pistola Tranquilizadora	|     7|           8|" << endl;
			cout << "Metralhadora           	|     7|           9|" << endl;
			cin >> Option;
			while(Option<0||Option>9)
			{
				cout << Err << endl << "Escolha:" << endl;
				cin >> Option;
			}
			Compra = new Weapon(*(Weapon*)Items[Option+6]); // construtor de copia
			Players[chosen]->getItem(Compra);
			Players[chosen]->equipWeapon(Compra);

			cout << "Items equipados com sucesso. Deseja equipar outro personagem? 1 = Sim." << endl;
			cin >> Option;
		} while (Option == 1);

		break;
		case 2:

		numchars = Teams[0]->getSize();
		chosen = 0;
		if(numchars < 1) {
			cout << "Time sem personagens, favor escolher personagens primeiro." << endl;
			break;
		}
		do{

			cout << "Escolha qual personagem usara a loja: (Insira qualquer outro numero para sair)" << endl;
			for(int i = 0 ; i < numchars ; i++)
			{
				cout << i << ": " << Teams[0]->getCharacter(i)->getName() << endl;
			}
			cin >> chosen;

			while(chosen<0||chosen>=numchars)
				{
					cout << Err << endl << "Escolha:" << endl;
					cin >> chosen;
				}

			cout << "Pocoes para " << Players[chosen]->getName() << ":\nGold Disponivel: " << Players[chosen]->getTotalGold() << "\nO que deseja comprar?" << endl;
			cout << "Poções:              |Preço| Cura|Nro da Opcao|" << endl;
			cout << "Pocao Pequena de Vida  |   50|   20|           1|" << endl;
			cout << "Pocao Media de Vida    |  100|   40|           2|" << endl;
			cout << "Pocao Grande de Vida   |  150|   60|           3|" << endl;
			cout << "Pocao de Yggdrasil     |  200|  100|           4|" << endl;
			cout << "Pocao Pequena De Mana  |  100|   30|           5|" << endl;
			cout << "Pocao Media De Mana    |  200|   60|           6|" << endl;
			cout << "Pocao Grande De Mana   |  300|  100|           7|" << endl;
			cout << "Sair - Opcao 0";
			cin >> Option;
			while(Option<0||Option>7)
			{
				cout << Err << endl << "Escolha:" << endl;
				cin >> Option;
			}

			if(Option!=0){
				if(Option<5) Compra = new HealthPotion(*(HealthPotion*)Items[Option+15]); // construtor de copia
				else Compra = new ManaPotion(*(ManaPotion*)Items[Option+15]); // construtor de copia
				Players[chosen]->getItem(Compra);
			}

			cout << "Pocoes compradas com sucesso. Deseja comprar com outro personagem? 1 = Sim." << endl;
			cin >> Option;
		} while (Option == 1);

		break;

		case 3:

		cout << "Luka to Jojo no RPG: BATTLE STARTING";
		this_thread::sleep_for(std::chrono::milliseconds(3000));
		system("clear");
		Teams[0]->fight(*Teams[1]);

		break;

		case 4:

		Menu = false;
		break;

		default:
		cout << Err << endl;
	}
}

//Liberar Memoria
for (int i=0;i<8;i++) delete Players[i];
for (int i=0;i<2;i++) delete Teams[i];
for (int i=0;i<24;i++) delete Items[i];
return 0;
}
