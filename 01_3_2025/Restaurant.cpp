
#include"Restaurant.h"
#include<iostream>

using namespace std;


        Restaurant::Restaurant(){}
        Restaurant::Restaurant(const Restaurant& other): menu(other.menu), orders(other.orders){
            for(int i = 0; i < other.customers.size(); i++){
                customers.push_back(new Customer(*other.customers[i]));
            }
        }
        Restaurant& Restaurant::operator=(const Restaurant& other){
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
        Restaurant::Restaurant(Restaurant&& other) noexcept: menu(move(other.menu)), orders(move(other.orders)), customers(move(other.customers)){}
        Restaurant& Restaurant::operator=(Restaurant&& other) noexcept{
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
        Restaurant::~Restaurant(){
            for(int i = 0; i < customers.size(); i++){
                delete customers[i];
            }
        }
        void Restaurant::showMenu() const{
            menu.displayMenu();
        }
        Customer* Restaurant::getCustomerByName(const string& name){
            for(int i = 0; i < customers.size(); i++){
                if(customers[i]->getName() == name){
                    return customers[i];
                }
            }
            return nullptr;
        }
        void Restaurant::placeNewOrder(const string& customerName){
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
        void Restaurant::viewCustomerOrderHistory(const string& customerName){
            Customer* customer = getCustomerByName(customerName);
            if(customer == nullptr){
                cout << "Customer not found" << endl;
                return;
            }
            customer->viewOrderHistory();
        }   
    