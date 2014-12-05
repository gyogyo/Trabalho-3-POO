#include <string>
#include <vector>
#include <iostream>
#include <Loja.hpp>

using namespace std;

Loja::Loja()
{
	
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
}

Loja::~Loja()
{
	for (int i=0;i<3;i++) delete Armors[i];
	for (int i=0;i<3;i++) delete Weapons[i];
	for (int i=0;i<4;i++) delete HPotions[i];
	for (int i=0;i<4;i++) delete MPotions[i];
}

void Loja::potionShop(Character* user)
{
	int Option;
	cout << "\033[2J\033[1;1H";
	cout << "Pocoes para " << user->getName() << ":\nGold Disponivel: " << user->getTotalGold() << "\nO que deseja comprar?" << endl;
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
		return;
	}
	while(Option<0||Option>6)
	{
		cout << "Opção Inválida. Escolha novamente" << endl << "Escolha:" << endl;
		cin >> Option;
	}
	if(Option<4)
	{
		if(user->getTotalGold()>HPotions[Option]->getPrice())
		{
			Compra = new HealthPotion(*(HealthPotion*)HPotions[Option]); // construtor de copia
			user->getItem(Compra);
			user->spendGold(HPotions[Option]->getPrice());
		}
		else
		{
			cout << endl << "Gold Insuficiente.";
		}
	}
	else
	{
		if(user->getTotalGold()>MPotions[Option-4]->getPrice())
		{
			Compra = new ManaPotion(*(ManaPotion*)MPotions[Option-4]); // construtor de copia
			user->getItem(Compra);
			user->spendGold(MPotions[Option-4]->getPrice());
		}
		else
		{
			cout << endl << "Gold Insuficiente.";
		}
	}
}

int Loja::armorShop(Character* user)
{
	int Option;
	cout << "\033[2J\033[1;1H";
	cout << "Escolha uma armadura para " << user->getName() << ":\nGold Disponivel: " << user->getTotalGold() << "\nO que deseja comprar?" << endl;
	cout << "Armaduras               |Defesa|Preco|Nro da Opcao|" << endl;
	cout << "Couraça de Bonbril      |     3|   50|           0|" << endl;
	cout << "Couraça de Ferro   	|     6|  100|           1|" << endl;
	cout << "Couraça de Aço     	|     9|  150|           2|" << endl;
	cout << "3 : Escolher uma arma\n4 : Sair\n\nEscolha: " ;
	cin >> Option;
	if(Option==4)
	{
		cout << "\033[2J\033[1;1H";
		cout << "Saindo da loja" << endl;
		this_thread::sleep_for(std::chrono::milliseconds(1000));
		return 3;
	}
	while(Option<0||Option>3)
	{
		cout << "Opção Inválida. Escolha novamente" << endl << "Escolha:" << endl;
		cin >> Option;
	}
	if(Option!=3)
	{
		if(user->getTotalGold()>=Armors[Option]->getPrice())
		{
			Compra = new Armor(*(Armor*)Armors[Option]); // construtor de copia
			user->getItem(Compra);
			user->equipArmor(Compra);
			user->spendGold(Armors[Option]->getPrice());
		}
		else
		{
			cout << endl << "Gold Insuficiente.";
			this_thread::sleep_for(std::chrono::milliseconds(2000));
		}		
	}
	else
	{
		return 1;
	}
}

int Loja::weaponShop(Character* user)
{
	int Option;
	cout << "\033[2J\033[1;1H";
	cout << "Escolha uma arma para " << user->getName() << ":\nGold Disponivel: " << user->getTotalGold() << "\nO que deseja comprar?" << endl;
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
		return 3;
	}
	while(Option<0||Option>3)
	{
		cout << "Opção Inválida. Escolha novamente" << endl << "Escolha:" << endl;
		cin >> Option;
	}
	if(Option!=3)
	{
		if(user->getTotalGold()>=Weapons[Option]->getPrice())
		{
			Compra = new Weapon(*(Weapon*)Weapons[Option]); // construtor de copia
			user->getItem(Compra);
			user->equipWeapon(Compra);
			user->spendGold(Weapons[Option]->getPrice());
		}
		else
		{
			cout << endl << "Gold Insuficiente.";
			this_thread::sleep_for(std::chrono::milliseconds(2000));
		}
	}
	else
	{
		return 0;
	}
}

void Loja::start(Team* userTeam)
{
	int Option;
	int aux;
	int numchars = userTeam->getSize();
	int chosen;
	int mode=2;
	do
	{
		switch(mode)
		{
			case 0:
				aux = armorShop(player);
				if(aux!=1)
				{
					mode=3;
					break;
				}
				else
				{
					mode=1;
					break;
				}
				break;
			case 1:	
				aux = weaponShop(player);
				if(aux!=0)
				{
					mode=3;
					break;
				}
				else
				{
					mode=0;
					break;
				}
				break;
			case 2:
				cout << "\033[2J\033[1;1H";
				cout << "Escolha qual personagem usara a loja: (Insira qualquer outro numero para sair)" << endl;
				for(int i = 0 ; i < numchars ; i++)
				{
					cout << i << ": " << userTeam->getCharacter(i)->getName() << endl;
				}
				cout << numchars << " : Sair" << endl << "Escolha: ";
				cin >> chosen;
				while(chosen<0||chosen>numchars)
				{
					cout << "Opção Inválida. Escolha novamente" << endl << "Escolha:" << endl;
					cin >> Option;
				}
				player = userTeam->getCharacter(chosen);
				if(chosen==numchars)
				{
					cout << "\033[2J\033[1;1H";
					cout << "Saindo da loja" << endl;
					this_thread::sleep_for(std::chrono::milliseconds(1000));
					mode=3;
					break;
				}
				mode=0;
				break;
			case 3:
				cout << "\033[2J\033[1;1H";
				cout << "Acesso concluido. O que deseja?\n0 : Equipar uma arma\n1 : Equipar uma armadura\n2 : Equipar outro personagem\n3 : Sair\n\nEscolha: " << endl;
				cin >> Option;
				while(Option<0||Option>3)
				{
					cout << "Opção Inválida. Escolha novamente" << endl << "Escolha:" << endl;
					cin >> Option;
				}
				if(Option==0)
				{
					mode=1;
					break;
				}
				if(Option==1)
				{
					mode=0;
					break;
				}
				if(Option==2)
				{
					mode=2;
					break;
				}
				if(Option==3)
				{
					mode=4;
					break;
				}
		}
	} while(mode!=4);
}
