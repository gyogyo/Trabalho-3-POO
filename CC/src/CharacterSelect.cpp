#include <string>
#include <vector>
#include <iostream>
#include <Classes.hpp>
#include <CharacterSelect.hpp>

using namespace std;

CharacterSelect::CharacterSelect()
{
	
	players[0].first = new Knight("Rad",4,55,10,15,20);
	players[1].first = new Knight("Ramza",5,40,10,10,40);
	players[2].first = new Wizard("Merlin",4,40,15,35,10);
	players[3].first = new Wizard("Medea",5,60,15,15,10);
	players[4].first = new Thief("Lupin",3,20,30,45,5);
	players[5].first = new Thief("X",4,30,20,35,15);
	players[6].first = new Duelist("Zalbag",5,60,30,5,5);
	players[7].first = new Duelist("Akatsuki",6,40,20,35,5);
	players[8].first = new Paladin("Dycedarg",7,20,5,5,70);
	players[9].first = new Paladin("Larkberg",4,25,5,15,55);

	for(int i = 0; i < 10; i++) players[i].second = true;

	waveCounter = 0;

}

CharacterSelect::~CharacterSelect()
{
	for (int i=0;i<10;i++) delete players[i].first;
}

void CharacterSelect::assembleTeam(Team* user)
{
	int Option;
	int teamchars = user->getSize();
	if(teamchars < 3) {
		cout << "\033[2J\033[1;1H";
		cout << "Escolha seus personagens dentre os abaixo:" << endl;
		for(int i = 0 ; i < 10 ; i++)
		{
			if(players[i].second == true){
				cout << "\nOpção " << i << " --------------";
				players[i].first->PrintInfo();
				cout << endl;
			}
		}

		while(teamchars < 3)
		{
			cout << "\nEscolha " << (3-teamchars) << " personagens! (Nao podem ser repetidos)" << endl;
			cin >> Option;
			while(Option<0||Option>9||players[Option].second == false)
			{
				cout << "Opção Inválida. Escolha novamente" << endl << "Escolha:" << endl;
				cin >> Option;
			}
			players[Option].second = false;
			cout << players[Option].first->getName() << " escolhido!" << endl;
			user->addChar(players[Option].first->clone());
			teamchars++;
		}
		this_thread::sleep_for(std::chrono::milliseconds(700));
		cout << "\033[2J\033[1;1H";
	}
	else
	{
		cout << "\033[2J\033[1;1H";
		cout << "A sua equipe ja esta com o limite de personagens." << endl;
		this_thread::sleep_for(std::chrono::milliseconds(2000));
	}
}

void CharacterSelect::assembleEnemies(Team* user)
{
	int teamchars = user->getSize();
	if(teamchars < 3) {
		cout << "\033[2J\033[1;1H";
		cout << "Preparando inimigos..." << endl;

		Character* enemyChar;
		Item* enemyEquipment;
		int rng;

		while(teamchars < 3)
		{
			rng = ((rand()/double(RAND_MAX))*5);
			switch(rng){
			case 0:
				enemyChar = new Knight("Knight");
				break;
			case 1:
				enemyChar = new Wizard("Wizard");
				break;
			case 2:
				enemyChar = new Thief("Thief");
				break;
			case 3:
				enemyChar = new Duelist("Duelist");
				break;
			case 4:
				enemyChar = new Paladin("Paladin");
				break;

			}

			enemyChar->setStrenght(5*waveCounter,1);
			enemyChar->setSpeed(5*waveCounter,1);
			enemyChar->setDexterity(5*waveCounter,1);
			enemyChar->setConstitution(5*waveCounter,1);
			enemyChar->addHP(10*waveCounter);
			enemyChar->addMP(5*waveCounter);

			enemyEquipment = new Armor("Armadura Inimiga", 0, (rand()/double(RAND_MAX))*10);
			enemyChar->getItem(enemyEquipment);
			enemyChar->equipArmor(enemyEquipment);

			enemyEquipment = new Weapon("Arma Inimiga", 0, (rand()/double(RAND_MAX))*10);
			enemyChar->getItem(enemyEquipment);
			enemyChar->equipWeapon(enemyEquipment);

			user->addChar(enemyChar);

			teamchars++;
		}
		this_thread::sleep_for(std::chrono::milliseconds(700));
		cout << "Inimigos preparados." << endl;
		waveCounter++;
	}
}
