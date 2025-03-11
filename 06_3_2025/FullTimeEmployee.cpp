#include "FullTimeEmployee.h"
#include "Employee.h"
#include "EmployeeStatus.h"
#include <iostream>

using namespace std;

FullTimeEmployee::FullTimeEmployee(string id, string empName, double salary, Role empRole)
    : Employee(id, empName, salary, empRole, Type::FullTime) {}

double FullTimeEmployee::calculateSalary() const {
    return baseSalary * rate;
}

