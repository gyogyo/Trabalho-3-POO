#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <Team.hpp>
#include <Colors.hpp>
#include <Character.hpp>

using namespace std;

Team::Team(string Name, int colour){
name = Name;
color = colour;
win = 0;
lose = 0;
draw = 0;
characters = vector<Character*> (0);
}

Team::~Team(){
characters.clear();
}


//Getters

string Team::getName(){
return name;
}

string Team::getResults(){
string Info = "Wins: " + to_string(win) + " Losses: " + to_string(lose) + " Draw: " + to_string(draw);
return Info;
}

Character* Team::getCharacter(int N){
if(N < characters.size()) return characters[N];
throw;
}

int Team::getSize(){
return characters.size();
}

string Team::toString(){
string Info = name + " " + to_string(color);
return Info;
}

void Team::fight(Team& EnemyTeam){
deque<int> rngTeam1; //Deque de personagens desse time.
deque<int> rngTeam2; //Deque de personagens do time adversario.
deque<int> TurnOrder; //Deque de ordem de quem luta com quem.
for(int i=0; i<characters.size(); i++) rngTeam1.push_back(i); //Colocar ints em uma deque para evitar repeticao.
for(int i=0; i<EnemyTeam.characters.size(); i++) rngTeam2.push_back(i);
while((rngTeam1.size()>0)&&(rngTeam2.size()>0)){
	int i = rand()%rngTeam1.size(); //Puxar ints aleatoriamente para sortear os personagens.
	int j = rngTeam1[i];
	rngTeam1.erase(rngTeam1.begin()+i); //Apagar int ja selecionado.
	TurnOrder.push_back(j); //Empilhar turno.
	i = rand()%rngTeam2.size(); //Puxar ints aleatoriamente para sortear os personagens do outro time.
	j = rngTeam2[i];
	rngTeam2.erase(rngTeam2.begin()+i); //Apagar int ja selecionado.
	TurnOrder.push_back(j); //Empilhar turno.
}
while(TurnOrder.size()>1){
	int Option;
	int i = TurnOrder.front();
	TurnOrder.pop_front();
	int j = TurnOrder.front();
	TurnOrder.pop_front();
	cout << "Luka to Jojo no RPG:" << endl << endl << characters[i]->getName() <<"  : HP: "<< characters[i]->getHP() <<" 		vs 		HP: "<< EnemyTeam.characters[j]->getHP() <<"  : "<< EnemyTeam.characters[j]->getName() <<" \n\nModes:\n1 - Attack\n2 - Magic Attack\n3 - Defend\n4 - Psyche Up\n5 - Item\n Op: ";
	cin >> Option;
	while(Option<1||Option>5)
	{
		cout << "\nOpção Inválida. Escolha novamente\nOp: ";
		cin >> Option;
	}
	while(Option==1)
	{
		system("CLS");
		characters[i]->attack(EnemyTeam.characters[j]);
		cout << "Luka to Jojo no RPG:\n\n" << characters[i]->getName() <<"  : HP: "<< characters[i]->getHP() <<" 		vs 		HP: "<< EnemyTeam.characters[j]->getHP() <<"  : "<< EnemyTeam.characters[j]->getName() <<" \n\nModes:\n1 - Attack\n2 - Magic Attack\n3 - Defend\n4 - Psyche Up\n5 - Item\n Op: ";
		cin >> Option;
		while(Option<1||Option>5)
		{
			cout << "\nOpção Inválida. Escolha novamente\nOp: ";
			cin >> Option;
		}
	}
	while(Option==2)
	{
		system("CLS");
		characters[i]->attack(EnemyTeam.characters[j]); // mudar
		cout << "Luka to Jojo no RPG:\n\n" << characters[i]->getName() <<"  : HP: "<< characters[i]->getHP() <<" 		vs 		HP: "<< EnemyTeam.characters[j]->getHP() <<"  : "<< EnemyTeam.characters[j]->getName() <<" \n\nModes:\n1 - Attack\n2 - Magic Attack\n3 - Defend\n4 - Psyche Up\n5 - Item\n Op: ";
		cin >> Option;
		while(Option<1||Option>5)
		{
			cout << "\nOpção Inválida. Escolha novamente\nOp: ";
			cin >> Option;
		}
	}
	while(Option==3)
	{
		system("CLS");
		characters[i]->attack(EnemyTeam.characters[j]); // mudar
		cout << "Luka to Jojo no RPG:\n\n" << characters[i]->getName() <<"  : HP: "<< characters[i]->getHP() <<" 		vs 		HP: "<< EnemyTeam.characters[j]->getHP() <<"  : "<< EnemyTeam.characters[j]->getName() <<" \n\nModes:\n1 - Attack\n2 - Magic Attack\n3 - Defend\n4 - Psyche Up\n5 - Item\n Op: ";
		cin >> Option;
		while(Option<1||Option>5)
		{
			cout << "\nOpção Inválida. Escolha novamente\nOp: ";
			cin >> Option;
		}
	}
	while(Option==4)
	{
		system("CLS");
		characters[i]->physiqueUp();
		cout << "Luka to Jojo no RPG:\n\n" << characters[i]->getName() <<"  : HP: "<< characters[i]->getHP() <<" 		vs 		HP: "<< EnemyTeam.characters[j]->getHP() <<"  : "<< EnemyTeam.characters[j]->getName() <<" \n\nModes:\n1 - Attack\n2 - Magic Attack\n3 - Defend\n4 - Psyche Up\n5 - Item\n Op: ";
		cin >> Option;
		while(Option<1||Option>5)
		{
			cout << "\nOpção Inválida. Escolha novamente\nOp: ";
			cin >> Option;
		}
	}
	while(Option==5)
	{
		int ItemOption;
		system("CLS");
		cout << "Escolha um item usável";
		cout << "-1 - Cancel";
		characters[i]->PrintItemsInfo();
		cin >> ItemOption;
		if(ItemOption!=-1)
		{
			characters[i]->useItem(ItemOption);
		}
		cout << "Luka to Jojo no RPG:\n\n" << characters[i]->getName() <<"  : HP: "<< characters[i]->getHP() <<" 		vs 		HP: "<< EnemyTeam.characters[j]->getHP() <<"  : "<< EnemyTeam.characters[j]->getName() <<" \n\nModes:\n1 - Attack\n2 - Magic Attack\n3 - Defend\n4 - Psyche Up\n5 - Item\n Op: ";
		cin >> Option;
		while(Option<1||Option>5)
		{
			cout << "\nOpção Inválida. Escolha novamente\nOp: ";
			cin >> Option;
		}
	}
}
}

int Team::resolveBattle(Team& EnemyTeam){
int AllyPoints = this->getPoints();
int EnemyPoints = EnemyTeam.getPoints(); //Pegar media de HP
if(AllyPoints < EnemyPoints) lose+=1; //Comparar media de HP
else if(AllyPoints >EnemyPoints) win+=1;
else draw+=1;
return 0; //Por que e que essa funcao retorna int?
}

//Operacoes com items
//Insercao de personagem no time.
void Team::addChar(Character* New){
characters.push_back(New);
}

void Team::clear(){
characters.clear();
}

//Remove personagem do time.
void Team::removeChar(int Num){
if(Num < characters.size())
characters.erase(characters.begin()+Num);
}

//Remove TODOS os personagens de mesmo nome.
void Team::removeChar(Character* Chara){
int TeamSize = characters.size();
for(int i=0; i<TeamSize; i++)
 if(characters[i]->getName()==Chara->getName()){
  characters.erase(characters.begin()+i);
  }
}

//Retorna UM personagem com o devido nome.
Character* Team::searchChar(string Name){
int TeamSize = characters.size();
for(int i=0; i<TeamSize; i++)
 if(characters[i]->getName()==Name)
  return characters[i];
return NULL;
}

//Retorna media do HP.
int Team::getPoints(){
int Points = 0;
int TeamSize = characters.size();
for(int i=0; i<TeamSize; i++) Points += characters[i]->getHP();
return (Points/TeamSize);
}

void Team::PrintInfo(){ //Debug Print
string S = " ";
cout << "Team: " << color << endl;
cout << "Wins: " << win << " Losses: " << lose << " Draw: " << draw << endl;
getResults();
int TeamSize = characters.size();
for(int i=0; i<TeamSize; i++) characters[i]->PrintInfo();
cout << endl;
}

void Team::printCharacters(){
int TeamSize = characters.size();
for(int i=0; i<TeamSize; i++) cout << "Personagem " << i << ": " << characters[i]->getName() << endl;
}
