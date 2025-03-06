#include<iostream>
#include<vector>
#include"Order.h"

using namespace std;

class Customer {
private:
	string name;
	string contactInfo;
	vector<Order> orderHistory;
public:
	Customer(string customerName, string contact)
		:name(customerName), contactInfo(contact){}
	Customer(const Customer& other)
		: name(other.name), contactInfo(other.contactInfo), orderHistory(other.orderHistory){}
    Customer& operator=(const Customer& other){
        if(this != &other){
            name = other.name;
            contactInfo = other.contactInfo;
            orderHistory = other.orderHistory;
        }
        return *this;
    }
    Customer(Customer&& other) noexcept
    : name(move(other.name)), contactInfo(move(other.contactInfo)), orderHistory(move(other.orderHistory)){}
    Customer& operator=(Customer&& other) noexcept{
        if(this != &other){
            name = move(other.name);
            contactInfo = move(other.contactInfo);
            orderHistory = move(other.orderHistory);
        }
        return *this;
    }
    ~Customer() = default{}
    void placeOrder(Order order){
        orderHistory.push_back(order);
    }
    void viewOrderHistory() const{
        for(const auto& order : orderHistory){
            order.display();
        }
    }
    string getName() const{
        return name;
    }
};
