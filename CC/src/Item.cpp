#include <string>
#include <Item.hpp>
using namespace std;

//Construtor de items.
Item::Item(string Name, double Price){
name = Name;
price = Price;
type=0;
}

Item::Item(Item& Source){
this->name = Source.name;
this->price = Source.price;
}

//Getters

string Item::getName(){
return name;
}

double Item::getPrice(){
return price;
}

int Item::getType(){
return type;
}
