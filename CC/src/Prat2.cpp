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
Character* Players[8];
Players[0] = new Knight("Loto",10);
Players[1] = new Knight("Ramza",3);
Players[2] = new Knight("Marth",5);
Players[3] = new Wizard("Ness",3);
Players[4] = new Wizard("Magus",8);
Players[5] = new Wizard("Merlin",9);
Players[6] = new Thief("Vaan",2);
Players[7] = new Thief("Snake",10);

Team* Teams[2];
Teams[0] = new Team("Red",red);
Teams[1] = new Team("Blue",blue);

/*
Armor* Armors[6];
Weapon* Weapons[10];
Potion* Potions[8];
*/
Item* Items[24];

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

Items[16] = new HealthPotion("Pocao Pequena De Vida", 50, 20);
Items[17] = new HealthPotion("Pocao Media De Vida", 100, 40);
Items[18] = new HealthPotion("Pocao Grande De Vida", 150, 60);
Items[19] = new HealthPotion("Pocao Extra Grande De Vida", 200, 80);
Items[20] = new HealthPotion("Pocao Que Cura Tudo", 250, 100);

Items[21] = new ManaPotion("Pocao Pequena De Mana", 100, 30);
Items[22] = new ManaPotion("Pocao Media De Mana", 200, 60);
Items[23] = new ManaPotion("Pocao Grande De Mana", 300, 100);

//Os items sao achados, nao comprados. Portanto, sem manipulacao de gold ainda.
Players[0]->getItem(Items[0]);	Players[0]->getItem(Items[6]);	Players[1]->getItem(Items[7]);	Players[1]->getItem(Items[8]);
Players[2]->getItem(Items[1]);	Players[2]->getItem(Items[9]);	Players[3]->getItem(Items[10]);	Players[3]->getItem(Items[3]);
Players[4]->getItem(Items[11]);	Players[4]->getItem(Items[2]);	Players[5]->getItem(Items[12]);	Players[5]->getItem(Items[4]);
Players[6]->getItem(Items[13]);	Players[6]->getItem(Items[5]);	Players[7]->getItem(Items[14]);	Players[7]->getItem(Items[15]);

//Equipando os items criados
Players[0]->equipArmor(Items[0]);	Players[0]->equipWeapon(Items[6]);	Players[1]->equipWeapon(Items[7]);	Players[1]->equipWeapon(Items[8]);
Players[2]->equipArmor(Items[1]);	Players[2]->equipWeapon(Items[9]);	Players[3]->equipWeapon(Items[10]);	Players[3]->equipArmor(Items[3]);
Players[4]->equipWeapon(Items[11]);	Players[4]->equipArmor(Items[2]);	Players[5]->equipWeapon(Items[12]);	Players[5]->equipArmor(Items[4]);
Players[6]->equipWeapon(Items[13]);	Players[6]->equipArmor(Items[5]);	Players[7]->equipWeapon(Items[14]);	Players[7]->equipWeapon(Items[15]);

//Montar rodada e times.
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

