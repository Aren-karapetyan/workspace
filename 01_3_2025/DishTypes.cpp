#include "DishTypes.h"
#include<iostream>
#include<string>	

using namespace std;


	Appetizer::Appetizer(string dishName, double dishPrice, bool spicy)
		: Dish(move(dishName), dishPrice), isSpicy(spicy){}
	void Appetizer::display() const{
		cout << name << '\n' << price << '\n' << (isSpicy ? "YES" : "NO") << endl;
	}

	Entree::Entree(string dishName, double dishPrice, int cal)
	: Dish(move(dishName), dishPrice), calories(cal){}
	void Entree::display() const{
		cout << name << '\n' << price << '\n' << calories << endl;
	}

	Dessert::Dessert(std::string dishName, double dishPrice, bool nuts)
		: Dish(move(dishName), dishPrice), containsNuts(nuts){}
	void Dessert::display() const{
		cout << name << '\n' << price << '\n' << (containsNuts ? "YES" :"NO") << endl;
	}


		