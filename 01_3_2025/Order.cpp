#include "Order.h"
#include<iostream>
#include<vector>
#include"Customer.h"
#include"Dish.h"
using namespace std;
class Order {
    private:
        Customer* customer;
        vector<Dish*> orderedDishes;
        double totalPrice;
    public:
        Order(Customer* customer): customer(customer), totalPrice(0){}
        Order(const Order& other): customer(other.customer), orderedDishes(other.orderedDishes), totalPrice(other.totalPrice){}
        Order& operator=(const Order& other){
            if(this != &other){
                customer = other.customer;
                orderedDishes = other.orderedDishes;
                totalPrice = other.totalPrice;
            }
            return *this;
        }
        Order(Order&& other) noexcept: customer(other.customer), orderedDishes(move(other.orderedDishes)), totalPrice(other.totalPrice){}
        Order& operator=(Order&& other) noexcept{
            if(this != &other){
                customer = other.customer;
                orderedDishes = move(other.orderedDishes);
                totalPrice = other.totalPrice;
            }
            return *this;
        }
        ~Order() = default;
        void addDish(Dish* dish){
            orderedDishes.push_back(dish);
        }
        void calculateTotal(){
            for(const auto& dish : orderedDishes){
                totalPrice += dish->getPrice();
            }
        }
        void displayOrder() const{
            cout << "Customer: " << customer->getName() << endl;
            for(const auto& dish : orderedDishes){
                dish->display();
            }
            cout << "Total Price: " << totalPrice << endl;
        }
    };