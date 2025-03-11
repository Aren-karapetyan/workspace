#pragma once
#include "Employee.h"
#include <iostream>

using namespace std;

class FullTimeEmployee : public Employee{
    public:
        FullTimeEmployee(std::string id, std::string empName, double salary, Role empRole);
        double calculateSalary() const override;  
        void displayDetails() const override;  
};