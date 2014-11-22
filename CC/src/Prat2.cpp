#include <iostream>
#include <string>
#include <Character.hpp>
#include <Classes.hpp>
#include <Team.hpp>
#include <Equipment.hpp>
#include <Potions.hpp>
#include <deque>

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
	printf("Luka to Jojo no RPG:");
	printf("Escolha seu time:\nRed - 0\nBlue - 1");
	while(Option<0||Option>1)
	{
		printf("Opção Inválida. Escolha novamente");
		scanf("%d", &Option);
	}
	if(Option==0)
	{
		printf("\nTime %d escolhido", teamChosen);
		teamChosen=0;
		teamEnemy=1;
	}
	else
	{
		printf("\nTime %d escolhido", teamChosen);
		teamChosen=1;
		teamEnemy=0;
	}
	system("CLEAR");
	printf("Luka to Jojo no RPG:\nMonte seu time escolhendo três personagens abaixo: ");
	for(int i = 0 ; i < 10 ; i++)
	{
		Printf("\nOpção %d: --------------", i);
		Players[i].PrintInfo();
		printf("\n");
	}
	for(int i = 0; i < 3 ; i++)
	{
		printf("\nEscolha %d personagens! (Nao podem ser repetidos)", (3-i));
		scanf("%d", &Option);
		while(Option<0||Option>9||rngdeque[Option]!=Option)
		{
			printf("\n\nOpção Inválida. Escolha novamente\nOp: ");
			scanf("%d", &Option);
		}
		rngdeque[Option]=-1;
		printf("\n%s escolhido!", Players[Option].getName());
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
	system("CLEAR");
	bool loja=true;
	for(int i =0 ; i < 3 ; i++)
	{
		printf("Luka to Jojo no RPG:\n\nEscolha uma Armadura");
		printf("\n\nArmaduras:           |Defesa|Peso|Nro da Opcao|")
		printf("\nEscudo de Ferro     	 |     5|  40|           0|");
		printf("\nArmadura de Ferro   	 |     7|  90|           1|");
		printf("\nCapacete de Ferro   	 |     3|  20|           2|");
		printf("\nBotas de Couro      	 |     4|  25|           3|");
		printf("\nBracelete Abencoado 	 |     2|   5|           4|");
		printf("\nGrevas de Ferro    	 |     6|  60|           5|");
		scanf("%d", &Option);
		while(Option<0||Option>5)
		{
			printf("\n\nOpção Inválida. Escolha novamente\nOp: ");
			scanf("%d", &Option);
		}
		Item* Chosen = new Armor(*Items[Option]); // construtor de copia
		Players[i]->getItem(Chosen);
		Players[i]->equipArmor(Chosen);
		system("CLEAR");
		printf("Luka to Jojo no RPG:\n\nEscolha uma Arma");
		printf("\n\nArmas:            	 	|Ataque|Nro da Opcao|")
		printf("\nEspada Lendaria     	 	|     7|           1|");
		printf("\nOsafune             	 	|     7|           2|");
		printf("\nAme No Murakamo     	 	|     7|           3|");
		printf("\bFalchion            	 	|     7|           4|");
		printf("\nBastao de Beisebol  	 	|     7|           5|");
		printf("\nFoice Maligna       	 	|     7|           6|");
		printf("\nCajado Mistico     	 	|     7|           7|");
		printf("\nFaca de Ferro     	 	|     7|           8|");
		printf("\nPistola Tranquilizadora	|     7|           9|");
		printf("\nMetralhadora           	|     7|           10|");
		scanf("%d", &Option);
		while(Option<0||Option>10)
		{
			printf("\n\nOpção Inválida. Escolha novamente\nOp: ");
			scanf("%d", &Option);
		}
		Chosen = new Weapon(*Items[Option+5]); // construtor de copia
		Players[i]->getItem(Chosen);
		Players[i]->equipWeapon(Chosen);
		while(loja)
		{
			printf("Luka to Jojo no RPG:\nMarketplace for %s :\nGold Disponivel: %lf\nO que deseja comprar?", Players[i].getName(), Players[i].getTotalGold());
			printf("\n\nPoções:              |Preço|Regen|Nro da Opcao|")
			printf("\nPocao Pequena de Vida  |   50|   20|           1|");
			printf("\nPocao Media de Vida    |  100|   40|           2|");
			printf("\nPocao Grande de Vida   |  150|   60|           3|");
			printf("\nPocao de Yggdrasil     |  200|  100|           4|");
			printf("\nPocao Pequena De Mana  |  100|   30|           5|");
			printf("\nPocao Media De Mana    |  200|   60|           6|");
			printf("\nPocao Grande De Mana   |  300|  100|           7|");
			printf("\nSair da loja - Opcao 0");
			scanf("%d", &Option);
			while(Option<0||Option>7)
			{
				printf("\n\nOpção Inválida. Escolha novamente\nOp: ");
				scanf("%d", &Option);
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
			system("CLEAR");
		}
	}
	printf("Luka to Jojo no RPG: BATTLE STARTING");
	this_thread::sleep_for(std::chrono::milliseconds(3000));
	system("CLEAR");
	Teams[teamChosen]->fight(*Teams[teamEnemy]);
}

//Liberar Memoria
for (int i=0;i<8;i++) delete Players[i];
for (int i=0;i<2;i++) delete Teams[i];
for (int i=0;i<24;i++) delete Items[i];
rngdeque.clear();
return 0;
}

