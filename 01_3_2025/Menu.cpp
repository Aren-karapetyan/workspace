#include<vector>
#include<iostream>
#include"Dish.h"

using namespace std;

class Menu {
private:
	vector<Dish*> dishes;
public:
	Menu(const Menu& other){
		for(int i = 0; i < other.dishes.size(); i++){
			dishes.push_back(new Dish(*other.dishes[i]));
		}
	}
	Menu& operator=(const Menu& other){
		for(int i = 0; i < other.dishes.size(); i++){
                	delete dishes[i];
                }
		dishes.clear();
		for (int i = 0; i < other.dishes.size(); i++){
			dishes.push_back(new.Dish(*other.dishes[i]));
		}
		return *this;
        }
	Menu(Menu&& other) noexcept{
		dishes= move(other.dishes);
	}
	Menu& operator=(Menu&& other) noexcept{
		for(int i = 0; i < other.dishes.size(); i++){
                        delete dishes[i];
                }
                dishes.clear();
		dishes = move(other.dishes);
		return *this;
	}
	~Menu(){
		for(int i = 0; i < other.dishes.size(); i++){
                        delete dishes[i];
                }
	}

	void addDish(Dish* dish){
		dishes.push_back(dish);
	}
	void displayMenu() const{
		for (size_t i = 0; i < dishes.size(); ++i) {
			dishes[i]->display();
		}
	}
	Dish* getDishByName(const string& dishName) const{
		for (size_t i = 0; i < dishes.size(); ++i) {
			if (dishes[i]->getName() == dishName) {
				return dishes[i];
			}
		}
	}
};

