#include <iostream>
#include <string>
#include <Character.hpp>
#include <Classes.hpp>
#include <Team.hpp>
#include <Equipment.hpp>
#include <Potions.hpp>
#include <deque>
#include <unistd.h>
#include <term.h>

using namespace std;

void ClearScreen()
{
    if (!cur_term)
    {
        int result;
        setupterm( NULL, STDOUT_FILENO, &result );
        if (result <= 0) return;
    }
    putp( tigetstr( "clear" ) );
}

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

Items[0] = new Armor("Escudo de Ferro", 100, 3, 30);
Items[1] = new Armor("Armadura de Ferro", 100, 3, 45);
Items[2] = new Armor("Capacete de Ferro", 100, 3, 20);
Items[3] = new Armor("Botas de Couro", 100, 3, 15);
Items[4] = new Armor("Bracelete Abencoado", 500, 2, 15);
Items[5] = new Armor("Amuleto Da Sorte", 10, 1, 5);

Items[6] = new Weapon("Espada Lendaria", 600, 7, 7);
Items[7] = new Weapon("Osafune", 300, 3, 5);
Items[8] = new Weapon("Ame No Murakamo", 500, 5, 6);
Items[9] = new Weapon("Falchion", 240, 4, 8);
Items[10] = new Weapon("Bastao de Beisebol", 100, 4, 4);
Items[11] = new Weapon("Foice Maligna", 600, 6, 10);
Items[12] = new Weapon("Cajado Mistico", 900, 3, 10);
Items[13] = new Weapon("Faca de Ferro", 100, 2, 3);
Items[14] = new Weapon("Pistola Tranquilizadora", 800, 4, 10);
Items[15] = new Weapon("Metralhadora", 3000, 9, 10);

Items[16] = new HealthPotion("Pocao Pequena de Vida", 50, 20);
Items[17] = new HealthPotion("Pocao Media de Vida", 100, 40);
Items[18] = new HealthPotion("Pocao Grande de Vida", 150, 60);
Items[19] = new HealthPotion("Pocao de Yggdrasil", 200, 100);

Items[20] = new ManaPotion("Pocao Pequena De Mana", 100, 30);
Items[21] = new ManaPotion("Pocao Media De Mana", 200, 60);
Items[22] = new ManaPotion("Pocao Grande De Mana", 300, 100);
bool loop = true;
//Montar rodada e times.
for(int i=0; i<10; i++) rngdeque.push_back(i);
while(loop)
{
	int Option, teamChosen, teamEnemy;
	cout << "Luka to Jojo no RPG:";
	cout << "Escolha seu time:\nRed - 0\nBlue - 1";
	while(Option<0||Option>1)
	{
		cout << "Opção Inválida. Escolha novamente";
		cin >> Option
	}
	if(Option==0)
	{
		cout << "\nTime "<< teamChosen << " escolhido";
		teamChosen=0;
		teamEnemy=1;
	}
	else
	{
		cout << "\nTime "<< teamChosen << " escolhido";
		teamChosen=1;
		teamEnemy=0;
	}
	system("CLS");
	cout << "Luka to Jojo no RPG:\nMonte seu time escolhendo três personagens abaixo: ";
	for(int i = 0 ; i < 10 ; i++)
	{
		cout << "\nOpção " << i << " --------------";
		Players[i].PrintInfo();
		cout << "\n");
	}
	for(int i = 0; i < 3 ; i++)
	{
		cout << "\nEscolha " << (3-i) << " personagens! (Nao podem ser repetidos)";
		cin >> Option;
		while(Option<0||Option>9||rngdeque[Option]!=Option)
		{
			cout << "\n\nOpção Inválida. Escolha novamente\nOp: ";
			cin >> Option
		}
		rngdeque[Option]=-1;
		cout << endl << Players[Option].getName() << " escolhido!";
		Teams[teamChosen]->addChar(Players[Option]);
	}
	int k=3;
	while(k>0)
	{
		int enemyChar = rnd%10;
		if(rngdeque[enemyChar]==enemyChar)
		{
			rngdeque[Option]=-1;
			Teams[teamEnemy]->addChar(Players[enemyChar]);
			k--;
		}
	}
	system("CLS");
	bool loja=true;
	for(int i =0 ; i < 3 ; i++)
	{
		cout << "Luka to Jojo no RPG:\n\nEscolha uma Armadura";
		cout << "\n\nArmaduras:           |Defesa|Peso|Nro da Opcao|";
		cout << "\nEscudo de Ferro     	 |     5|  40|           0|";
		cout << "\nArmadura de Ferro   	 |     7|  90|           1|";
		cout << "\nCapacete de Ferro   	 |     3|  20|           2|";
		cout << "\nBotas de Couro      	 |     4|  25|           3|";
		cout << "\nBracelete Abencoado 	 |     2|   5|           4|";
		cout << "\nGrevas de Ferro    	 |     6|  60|           5|";
		cin >> Option
		while(Option<0||Option>5)
		{
			cout << "\n\nOpção Inválida. Escolha novamente\nOp: ";
			cin >> Option
		}
		Item* Chosen = new Armor(*Items[Option]); // construtor de copia
		Players[i]->getItem(Chosen);
		Players[i]->equipArmor(Chosen);
		system("CLS");
		cout << "Luka to Jojo no RPG:\n\nEscolha uma Arma";
		cout << "\n\nArmas:            	 	|Ataque|Nro da Opcao|";
		cout << "\nEspada Lendaria     	 	|     7|           1|";
		cout << "\nOsafune             	 	|     7|           2|";
		cout << "\nAme No Murakamo     	 	|     7|           3|";
		cout << "\bFalchion            	 	|     7|           4|";
		cout << "\nBastao de Beisebol  	 	|     7|           5|";
		cout << "\nFoice Maligna       	 	|     7|           6|";
		cout << "\nCajado Mistico     	 	|     7|           7|";
		cout << "\nFaca de Ferro     	 	|     7|           8|";
		cout << "\nPistola Tranquilizadora	|     7|           9|";
		cout << "\nMetralhadora           	|     7|           10|";
		cin >> Option
		while(Option<0||Option>10)
		{
			cout << "\n\nOpção Inválida. Escolha novamente\nOp: ";
			cin >> Option
		}
		Chosen = new Weapon(*Items[Option+5]); // construtor de copia
		Players[i]->getItem(Chosen);
		Players[i]->equipWeapon(Chosen);
		system("CLS");
		while(loja)
		{
			cout << "Luka to Jojo no RPG:\nMarketplace for " << Players[i].getName() << " :\nGold Disponivel: " << Players[i].getTotalGold() << " \nO que deseja comprar?";
			cout << "\n\nPoções:              |Preço|Regen|Nro da Opcao|";
			cout << "\nPocao Pequena de Vida  |   50|   20|           1|";
			cout << "\nPocao Media de Vida    |  100|   40|           2|";
			cout << "\nPocao Grande de Vida   |  150|   60|           3|";
			cout << "\nPocao de Yggdrasil     |  200|  100|           4|";
			cout << "\nPocao Pequena De Mana  |  100|   30|           5|";
			cout << "\nPocao Media De Mana    |  200|   60|           6|";
			cout << "\nPocao Grande De Mana   |  300|  100|           7|";
			cout << "\nSair da loja - Opcao 0";
			cin >> Option
			while(Option<0||Option>7)
			{
				cout << "\n\nOpção Inválida. Escolha novamente\nOp: ";
				cin >> Option
			}
			if(Option>0)
			{
				if(Option<5)
				{
					Chosen = new HealthPotion(*Items[Option+15]); // construtor de copia
					Players[i]->getItem(Chosen);
				}
				else
				{
					Chosen = new ManaPotion(*Items[Option+15]); // construtor de copia
					Players[i]->getItem(Chosen);
				}
			}
			else
			{
				loja=false;
			}
			system("CLS");
		}
	}
	cout << "Luka to Jojo no RPG: BATTLE STARTING";
	this_thread::sleep_for(std::chrono::milliseconds(3000));
	system("CLS");
	//Teams[teamChosen]->fight(*Teams[teamEnemy]);
	loop=false;
}

//Liberar Memoria
for (int i=0;i<8;i++) delete Players[i];
for (int i=0;i<2;i++) delete Teams[i];
for (int i=0;i<24;i++) delete Items[i];
rngdeque.clear();
return 0;
}

