#include "PartTimeEmployee.h"
#include <iostream>

using namespace std;

PartTimeEmployee::PartTimeEmployee(string id, string empName, Role empRole, double Wage, double Worked)
    : Employee(id, empName, 0.0, empRole, Type::PartTime), hourlyWage(Wage), hoursWorked(Worked) {}

double PartTimeEmployee::calculateSalary() const {
    return hourlyWage * hoursWorked * rate;
}
void PartTimeEmployee::displayDetails() const {
    Employee::displayDetails();
    cout << "Hourly Wage: " << hourlyWage << endl;
    cout << "Hours Worked: " << hoursWorked << endl;
}