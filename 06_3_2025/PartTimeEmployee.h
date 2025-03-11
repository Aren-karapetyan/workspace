#pragma once
#include "Employee.h"
#include <iostream>

using namespace std;

class PartTimeEmployee : public Employee{
    private:
        double hoursWorked;
        double hourlyWage;
    public:
        PartTimeEmployee(string id, string empName, Role empRole, double Worked, double Wage);
        double calculateSalary() const override;
        void displayDetails() const override;
};