﻿#include <string>
#include <Item.hpp>
using namespace std;

//Construtor de items.
Item::Item(string Name, double Price, int Points){
	name = Name;
	price = Price;
	points = Points;
}

Item::Item(Item& Source){
	this->name = Source.name;
	this->price = Source.price;
}

//Setter

void Item::setPoints(int Value){
	points = Value;
}

void Item::setOwner(Character* Owner){
	owner = Owner;
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

Character* Item::getOwner(){
	return owner;
}
