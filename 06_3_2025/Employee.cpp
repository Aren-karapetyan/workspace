#include<Employee>

using namespace std;

Employee::Employee(string EmployeeID, string name, double baseSalary, Role role, Status status, Type type, double rate)
{
    this->EmployeeID = EmployeeID;
    this->name = name;
    this->baseSalary = baseSalary;
    this->role = role;
    this->status = status;
    this->type = type;
    this->rate = rate;
}