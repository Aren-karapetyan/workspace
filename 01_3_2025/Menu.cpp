#include"Menu.h"
#include<iostream>
#include<string>


using namespace std;
	Menu::Menu(){}
	Menu::Menu(const Menu& other){
		for(int i = 0; i < other.dishes.size(); i++){
			dishes.push_back(new Dish(*other.dishes[i]));
		}
	}
	Menu& Menu::operator=(const Menu& other){
		for(int i = 0; i < other.dishes.size(); i++){
                	delete dishes[i];
                }
		dishes.clear();
		for (int i = 0; i < other.dishes.size(); i++){
			dishes.push_back(new Dish(*other.dishes[i]));
		}
		return *this;
        }
	Menu::Menu(Menu&& other) noexcept{
		dishes= move(other.dishes);
	}
	Menu& Menu::operator=(Menu&& other) noexcept{
		for(int i = 0; i < other.dishes.size(); i++){
                        delete dishes[i];
                }
                dishes.clear();
		dishes = move(other.dishes);
		return *this;
	}
	Menu::~Menu(){
		for(int i = 0; i < dishes.size(); i++){
                        delete dishes[i];
                }
	}

	void Menu::addDish(Dish* dish){
		dishes.push_back(dish);
	}
	void Menu::displayMenu() const{
		for (size_t i = 0; i < dishes.size(); ++i) {
			dishes[i]->display();
		}
	}
	Dish* Menu::getDishByName(const string& dishName) const{
		for (size_t i = 0; i < dishes.size(); ++i) {
			if (dishes[i]->getName() == dishName) {
				return dishes[i];
			}
		}
		return nullptr;
	}

