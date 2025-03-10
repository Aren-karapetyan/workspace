#include "Order.h"
#include <vector>
#include "Customer.h"
#include <iostream>

using namespace std;

        Order::Order(Customer* customer): customer(customer), totalPrice(0){}
        Order::Order(const Order& other): customer(other.customer), orderedDishes(other.orderedDishes), totalPrice(other.totalPrice){}
        Order& Order::operator=(const Order& other){
            if(this != &other){
                customer = other.customer;
                orderedDishes = other.orderedDishes;
                totalPrice = other.totalPrice;
            }
            return *this;
        }
        Order::Order(Order&& other) noexcept: customer(other.customer), orderedDishes(move(other.orderedDishes)), totalPrice(other.totalPrice){}
        Order& Order::operator=(Order&& other) noexcept{
            if(this != &other){
                customer = other.customer;
                orderedDishes = move(other.orderedDishes);
                totalPrice = other.totalPrice;
            }
            return *this;
        }
        void Order::addDish(Dish* dish){
            orderedDishes.push_back(dish);
        }
        void Order::calculateTotal(){
            for(const auto& dish : orderedDishes){
                totalPrice += dish->getPrice();
            }
        }
        void Order::displayOrder() const{
            cout << "Customer: " << customer->getName() << endl;
            for(const auto& dish : orderedDishes){
                dish->display();
            }
            cout << "Total Price: " << totalPrice << endl;
        }