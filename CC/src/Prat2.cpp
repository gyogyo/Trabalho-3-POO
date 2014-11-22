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

deque<int> rngdeque; //Deque para uso na ordenaçao aleatoria de times.

//Alguns personagens de RPG.
Character* Players[10];
Players[0] = new Knight("Rad",4,55,10,15,20);
Players[1] = new Knight("Ramza",5,40,10,10,40);
Players[2] = new Wizard("Merlin",4,40,15,35,10);
Players[3] = new Wizard("Medea",5,60,15,15,10);
Players[4] = new Thief("Lupin",3,20,30,45,5);
Players[5] = new Thief("X",4,30,20,35,15);
Players[6] = new Duelist("X",5,60,30,5,5);
Players[7] = new Duelist("Akatsuki",6,40,20,35,5);
Players[8] = new Paladin("Dyceldarg",7,20,5,5,70);
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
for(int i=0; i<23; i++) rngdeque.push_back(i); 
while(loop)
{
	int Option, teamChosen;
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
		teamChosen=0
	}
	else
	{
		printf("\nTime %d escolhido", teamChosen);
		teamChosen=1;
	}
	system("CLEAR");
	printf("Luka to Jojo no RPG:\nMonte seu time escolhendo três personagens abaixo: ");
	for(int i = 0 ; i < 10 ; i++)
	{
		Printf("\nOpção %d: --------------", i);
		Players[0].PrintInfo();
		printf("\n");
	}
	for(int i = 0; i < 3 ; i++)
	{
		printf("\nEscolha %d personagens!", (3-i));
		scanf("%d", &Option);
		while(Option<0||Option>9)
		{
			printf("\n\nOpção Inválida. Escolha novamente\nOp: ");
			scanf("%d", &Option);
		}
		printf("\n%s escolhido!", Players[i].getName());
		Teams[teamChosen]->addChar(Players[i]);
	}
	system("CLEAR");
	bool loja=true;
	for(int i =0 ; i < 3 ; i++)
	{
		while(loja)
		{
			printf("Luka to Jojo no RPG:\nMarketplace for %s :\nGold Disponivel: %lf\nO que deseja comprar?", Players[i].getName(), Players[i].getTotalGold());
			printf("\n\nArmaduras:           |Preço|Defesa|Peso|Nro da Opcao|")
			printf("\nEscudo de Ferro     	 |  100|     3|  30|           0|");
			printf("\nArmadura de Ferro   	 |  100|     3|  45|           1|");
			printf("\nCapacete de Ferro   	 |  100|     3|  20|           2|");
			printf("\nBotas de Couro      	 |  100|     3|  15|           3|");
			printf("\nBracelete Abencoado 	 |  500|     2|  15|           4|");
			printf("\nAmuleto Da Sorte    	 |   10|     1|   5|           5|");
			printf("\n\nArmas:            	 |Preço|Ataque|Nro da Opcao|")
			printf("\nEspada Lendaria     	 |  600|     7|           6|");
			printf("\nOsafune             	 |  300|     3|           7|");
			printf("\nAme No Murakamo     	 |  500|     5|           8|");
			printf("\bFalchion            	 |  240|     4|           9|");
			printf("\nBastao de Beisebol  	 |  100|     4|           10|");
			printf("\nFoice Maligna       	 |  600|     6|           11|");
			printf("\nCajado Mistico     	 |  900|     3|           12|");
			printf("\nFaca de Ferro     	 |  100|     2|           13|");
			printf("\nPistola Tranquilizadora|  800|     4|           14|");
			printf("\nMetralhadora           | 3000|     9|           15|");
			printf("\n\nPoções:              |Preço|Regen|Nro da Opcao|")
			printf("\nPocao Pequena de Vida  |   50|   20|          16|");
			printf("\nPocao Media de Vida    |  100|   40|          17|");
			printf("\nPocao Grande de Vida   |  150|   60|          18|");
			printf("\nPocao de Yggdrasil     |  200|  100|          19|");
			printf("\nPocao Pequena De Mana  |  100|   30|          20|");
			printf("\nPocao Media De Mana    |  200|   60|          21|");
			printf("\nPocao Grande De Mana   |  300|  100|          22|");
			printf("\nSair da loja - Opcao 23");
			scanf("%d", &Option);
			while(Option<0||Option>23)
			{
				printf("\n\nOpção Inválida. Escolha novamente\nOp: ");
				scanf("%d", &Option);
			}
			if(Option<23)
			{
				if(Option<6)
				{
					if(rngdeque[Option]==Option)
					{
						Item* Bought = new Armor(*Items[Option]); // construtor de copia
						rngdeque.erase(rngdeque.begin()+Option);
						Players[i]->getItem(Bought);
						Players[i]->equipArmor(Bought);
						Players[i].spendGold(Bought->getPrice());
					}
				}
				else if(Option<16)
				{
					if(rngdeque[Option]==Option) // nao permite equipar mais de uma armadura nem a mesma
					{
						Item* Bought = new Weapon(*Items[Option]);
						rngdeque.erase(rngdeque.begin()+Option);
						Players[i]->getItem(Bought);
						Players[i]->equipWeapon(Bought);
						Players[i].spendGold(Bought->getPrice());
					}
				}
				else if(Option<20)
				{
					Item* Bought = new HealthPotion(*Items[Option]);
					Players[i]->getItem(Bought);	
					Players[i].spendGold(Bought->getPrice());
				}
				else
				{
					Item* Bought = new ManaPotion(*Items[Option]);
					Players[i]->getItem(Bought);
					Players[i].spendGold(Bought->getPrice());
				}
			}
			else
			{
				loja=false;
			}
			system("CLEAR");
		}
	}
	printf("Luka to Jojo no RPG: BATTLE START");
	this_thread::sleep_for(std::chrono::milliseconds(3000));
	/*Inserir sistema de luta aqui*/
}

for(int i=0; i<8; i++) rngdeque.push_back(i); //Colocar ints em uma deque para evitar repeticao.
while(rngdeque.size()>1){
int i = rand()%rngdeque.size(); //Puxar ints aleatoriamente para sortear os personagens.
int j = rngdeque[i];
rngdeque.erase(rngdeque.begin()+i); //Apagar int ja selecionado.
i = rand()%rngdeque.size(); //Puxar personagem oponente.
int k = rngdeque[i];
rngdeque.erase(rngdeque.begin()+i); //Apagar selecionado.
Teams[0]->addChar(Players[j]); //Sortear em times.
Teams[1]->addChar(Players[k]);
}

Teams[0]->fight(*Teams[1]); //Rodar batalha entre times.
Teams[0]->resolveBattle(*Teams[1]); //Atualizar pontuacao dos times.
Teams[1]->resolveBattle(*Teams[0]);

//for (int i=0;i<2;i++) Teams[i]->PrintInfo(); //Debug Print
for (int i=16;i<24;i++) {Players[0]->getItem(Items[i]); Players[0]->useItem(Items[i]);} //Potion Test
//Players[0]->PrintInfo(); //Debug Print

//Liberar Memoria
for (int i=0;i<8;i++) delete Players[i];
for (int i=0;i<2;i++) delete Teams[i];
for (int i=0;i<24;i++) delete Items[i];
rngdeque.clear();
return 0;
}

