#include "InventoryManager.hpp"

InventoryManager::InventoryManager(Team* teamMngd)
{
	this->teamMngd=teamMngd;
	mode=0;
	player=NULL;
}

void InventoryManager::invManage()
{
	int statusAux;
	int itemAux, chosen;
	int numchars = teamMngd->getSize();
	run=true;
	do{
		switch(mode)
		{
			case 0: // escolhe o personagem
				cout << "\033[2J\033[1;1H";
				cout << "Escolha qual personagem voce deseja editar:" << endl;
				for(int i = 0 ; i < numchars ; i++)
				{
					cout << i << ": " << teamMngd->getCharacter(i)->getName() << endl;
				}
				cout << numchars << " : Sair" << endl << "\nEscolha: ";
				cin >> chosen;
				while(chosen<0||chosen>numchars)
				{
					cout << "Opção Inválida. Escolha novamente" << endl << "Escolha:" << endl;
					cin >> Option;
				}
				if(chosen==numchars)
				{
					run=false;
					mode=0;
					break;
				}
				player = teamMngd->getCharacter(chosen);
				mode=1;
				break;
			case 1: // seleciona o que deseja fazer
				cout << "\033[2J\033[1;1H";
				cout << "Configurando " << player->getName() << ":\n0 : Alterar status\n1 : Conferir inventario\n2 : Trocar de personagem\n3 : Voltar ao menu\n\nEscolha: ";
				cin >> Option;
				while(Option<0||Option>3)
				{
					cout << "\nOpção Inválida. Escolha novamente" << endl << "Escolha:" << endl;
					cin >> Option;
				}
				if(Option==0)
				{
					mode=2;
					break;
				}
				if(Option==1)
				{
					mode=3;
					break;
				}
				if(Option==2)
				{
					mode=0;
					break;
				}
				if(Option==3)
				{
					mode=0;
					run=false;
					break;
				}
			case 2:
				cout << "\033[2J\033[1;1H";
				player->PrintInfo();
				cout << "Qual status deseja alterar?\n0 - Strength\n1 - Speed\n2 - Dexterity\n3 - Constitution\n4 - Cancelar\n\nEscolha: ";
				cin >> Option;
				while(Option<0||Option>4)
				{
					cout << "\nOpção Inválida. Escolha novamente" << endl << "Escolha:" << endl;
					cin >> Option;
				}
				if(Option==0)
				{
					cout << "\033[2J\033[1;1H";
					cout << "Alterando STR:\n\nQuantos pontos deseja adicionar?\n\nNro: ";
					cin >> statusAux;
					if(player->getSkillPts()>=statusAux&&statusAux>0)
						player->setStrenght(statusAux,true);
					else
					{
						cout << "\033[2J\033[1;1H";
						cout << "Nao ha pontos suficientes ou o valor é inválido" << endl;
						this_thread::sleep_for(std::chrono::milliseconds(2000));
					}
					mode=1;
					break;	
				}
				if(Option==1)
				{
					cout << "\033[2J\033[1;1H";
					cout << "Alterando SPD:\n\nQuantos pontos deseja adicionar?\n\nNro: ";
					cin >> statusAux;
					if(player->getSkillPts()>=statusAux&&statusAux>0)
						player->setSpeed(statusAux,true);
					else
					{
						cout << "\033[2J\033[1;1H";
						cout << "Nao ha pontos suficientes ou o valor é inválido" << endl;
						this_thread::sleep_for(std::chrono::milliseconds(2000));
					}
					mode=1;
					break;	
				}
				if(Option==2)
				{
					cout << "\033[2J\033[1;1H";
					cout << "Alterando DEX:\n\nQuantos pontos deseja adicionar?\n\nNro: ";
					cin >> statusAux;
					if(player->getSkillPts()>=statusAux&&statusAux>0)
						player->setDexterity(statusAux,true);
					else
					{
						cout << "\033[2J\033[1;1H";
						cout << "Nao ha pontos suficientes ou o valor é inválido" << endl;
						this_thread::sleep_for(std::chrono::milliseconds(2000));
					}
					mode=1;
					break;	
				}
				if(Option==3)
				{
					cout << "\033[2J\033[1;1H";
					cout << "Alterando CON:\n\nQuantos pontos deseja adicionar?\n\nNro: ";
					cin >> statusAux;
					if(player->getSkillPts()>=statusAux&&statusAux>0)
						player->setConstitution(statusAux,true);
					else
					{
						cout << "\033[2J\033[1;1H";
						cout << "Nao ha pontos suficientes ou o valor é inválido" << endl;
						this_thread::sleep_for(std::chrono::milliseconds(2000));
					}
					mode=1;
					break;
				}
				if(Option==4)
				{
					mode=1;
					break;
				}
			case 3:
				cout << "\033[2J\033[1;1H";
				cout << "Inventario de " << player->getName() << ":" << endl;
				player->PrintItemsInfo();
				cout << "O que deseja fazer?\n0 - Equipar um equipamento\n1 - Vender um item\n2 - Voltar\n\nEscolha: ";
				cin >> Option;
				while(Option<0||Option>2)
				{
					cout << "\nOpção Inválida. Escolha novamente" << endl << "Escolha:" << endl;
					cin >> Option;
				}
				if(Option==0)
				{
					cout << "\033[2J\033[1;1H";
					cout << "Inventario de " << player->getName() << ":" << endl;
					player->PrintItemsInfo();
					cout << "\nQual item deseja equipar?" << endl << "Escolha: ";
					cin >> itemAux;
					while(itemAux<0||itemAux>player->size())
					{
						cout << "\nOpção Inválida. Escolha novamente" << endl << "Escolha:" << endl;
						cin >> itemAux;
					}
					player->equipItem(itemAux);
					mode=1;
					break;
				}
				if(Option==1)
				{
					cout << "\033[2J\033[1;1H";
					cout << "Inventario de " << player->getName() << ":" << endl;
					player->PrintItemsInfo();
					cout << "\nQual item deseja vender?" << endl << "Escolha: ";
					cin >> itemAux;
					while(itemAux<0||itemAux>player->size())
					{
						cout << "\nOpção Inválida. Escolha novamente" << endl << "Escolha:" << endl;
						cin >> itemAux;
					}
					player->earnGold((player->removeItem(itemAux))/2);
					mode=1;
					break;
				}
				if(Option==2)
				{
					mode=1;
					break;
				}
		}
	}while(run);
}
