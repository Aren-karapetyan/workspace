#include <iostream>
#include <string>

using namespace std;

class Dish {
protected:
	string name;
	double price;
public:
	Dish(string dishName, double dishPrice)
		: name(move(dishName)), price(dishPrice){}
	Dish(const Dish& other)
		: name(other.name), price(other.price){}
	Dish& operator=(const Dish& other){
		name = other.name;
		price = other.price;
		return *this;
	}
	Dish(Dish&& other) noexcept
		: name(move(other.name)), price(other.price){}
	Dish& operator=(Dish&& other) noexcept{
		name = move(other.name);
		price = other.price;
		return *this;
	}


	void display() const{
		cout << name << '\n' << price;
	}
	double getPrice() const{
		return price;
	}
	string getName() const{
		return name;
	}
};

