#ifndef GEAR_H_
#define GEAR_H_
#include <Equipable.hpp>
#include <Item.hpp>
#include <string>
class Gear : public Item, public Equipable
{
	public:
		Gear(string,double,int);
		Gear(Gear&);
		int check();
		void use();
};
#endif
