#include "Menu.h"
#include "Customer.h"
#include "Order.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Restaurant {
    private:
        Menu menu;
        vector<Customer*> customers;
        vector<Order> orders;
    public:
    
        Restaurant(){}
        Restaurant(const Restaurant& other): menu(other.menu), orders(other.orders){
            for(int i = 0; i < other.customers.size(); i++){
                customers.push_back(new Customer(*other.customers[i]));
            }
        }
        Restaurant& operator=(const Restaurant& other){
            if(this != &other){
                menu = other.menu;
                orders = other.orders;
                for(int i = 0; i < other.customers.size(); i++){
                    delete customers[i];
                }
                customers.clear();
                for(int i = 0; i < other.customers.size(); i++){
                    customers.push_back(new Customer(*other.customers[i]));
                }
            }
            return *this;
        }
        Restaurant(Restaurant&& other) noexcept: menu(move(other.menu)), orders(move(other.orders)), customers(move(other.customers)){}
        Restaurant& operator=(Restaurant&& other) noexcept{
            if(this != &other){
                menu = move(other.menu);
                orders = move(other.orders);
                for(int i = 0; i < other.customers.size(); i++){
                    delete customers[i];
                }
                customers.clear();
                customers = move(other.customers);
            }
            return *this;
        }
        ~Restaurant(){
            for(int i = 0; i < customers.size(); i++){
                delete customers[i];
            }
        }
        void showMenu() const{
            menu.displayMenu();
        }
        Customer* getCustomerByName(const string& name){
            for(int i = 0; i < customers.size(); i++){
                if(customers[i]->getName() == name){
                    return customers[i];
                }
            }
            return nullptr;
        }
        void placeNewOrder(const string& customerName){
            Customer* customer = getCustomerByName(customerName);
            if(customer == nullptr){
                cout << "Customer not found" << endl;
                return;
            }
            Order order(customer);
            string dishName;
            while(true){
                cout << "Enter dish name: ";
                cin >> dishName;
                Dish* dish = menu.getDishByName(dishName);
                if(dish == nullptr){
                    cout << "Dish not found" << endl;
                    continue;
                }
                order.addDish(dish);
                cout << "Do you want to add another dish? (y/n): ";
                char choice;
                cin >> choice;
                if(choice == 'n'){
                    break;
                }
            }
            order.calculateTotal();
            orders.push_back(order);
            customer->placeOrder(order);
        }
        void viewCustomerOrderHistory(const string& customerName) const{
            Customer* customer = getCustomerByName(customerName);
            if(customer == nullptr){
                cout << "Customer not found" << endl;
                return;
            }
            customer->viewOrderHistory();
        }   
    }; 
    