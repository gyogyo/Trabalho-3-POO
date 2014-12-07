#include <Gear.hpp>
#include <string>

Gear::Gear(string name,double price,int points) : Item(name,price,points)
{}

Gear::Gear(Gear& Source) : Item(Source){}

void Gear::use()
{
	cout << endl <<"Item invalido: 'nao utilizavel'" << endl;
	this_thread::sleep_for(std::chrono::milliseconds(2000));
}

int Gear::check()
{
	return 0;
}




