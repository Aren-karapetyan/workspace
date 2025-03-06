#include<vector>
#include<iostream>
#include"Dish.h"

using namespace std;

class Menu {
private:
	vector<Dish*> dishes;
public:
	Menu(const Menu& other)
	Menu& operator=(const Menu& other);
	Menu(Menu&& other) noexcept;
	Menu& operator=(Menu&& other) noexcept;
	~Menu();
	void addDish(Dish* dish);
	void displayMenu() const;
	Dish* getDishByName(const string& dishName) const;
};

