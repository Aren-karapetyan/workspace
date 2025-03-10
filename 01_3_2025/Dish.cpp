#include "Dish.h"
#include <iostream>

using namespace std;


	Dish::Dish(string dishName, double dishPrice)
		: name(move(dishName)), price(dishPrice){}
	Dish::Dish(const Dish& other)
		: name(other.name), price(other.price){}
	Dish& Dish::operator=(const Dish& other){
		name = other.name;
		price = other.price;
		return *this;
	}
	Dish::Dish(Dish&& other) noexcept
		: name(move(other.name)), price(other.price){}
	Dish& Dish::operator=(Dish&& other) noexcept{
		name = move(other.name);
		price = other.price;
		return *this;
	}


	void Dish::display() const{
		cout << name << '\n' << price;
	}
	double Dish::getPrice() const{
		return price;
	}
	string Dish::getName() const{
		return name;
	}

