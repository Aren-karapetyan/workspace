#include"Dish.h"
#include<iostream>
#include<string>	


using namespace std;
class Appetizer : public Dish {
private:
	bool isSpicy;
public:
	Appetizer(string dishName, double dishPrice, bool spicy)
		: Dish(move(dishName), dishPrice), isSpicy(spicy){}
	void display() const{
		cout << name << '\n' << price << '\n' << (isSpicy ? "YES" : "NO") << endl;
	}
};

class Entree : public Dish {
private:
	int calories;
public:
	Entree(string dishName, double dishPrice, int cal)
		: Dish(move(dishName), dishPrice), calories(cal){}
	void display() const{
		cout << name << '\n' << price << '\n' << calories << endl;
	}
};

class Dessert : public Dish {
private:
	bool containsNuts;
public:
	Dessert(std::string dishName, double dishPrice, bool nuts)
		: Dish(move(dishName), dishPrice), containsNuts(nuts){}
	void display() const{
		cout << name << '\n' << price << '\n' << (containsNuts ? "YES" :"NO") << endl;
	}
};


		
