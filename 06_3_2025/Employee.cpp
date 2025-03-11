#include "Employee.h"
#include "EmployeeStatus.h"
#include <iostream>

using namespace std;

Employee::Employee(string id, string empName, double salary, Role empRole, Type empType){
    EmployeeID = id;
    name = empName;
    baseSalary = salary;
    role = empRole;
    status = Status::Active;
    type = empType;
    rate = getRateForRole(role);
}
void Employee::promote(){
    if(role == Role::Intern){
        role = Role::Junior;
    }else if(role == Role::Junior){
        role = Role::Middle;
    }else if(role == Role::Middle){
        role = Role::Senior;
    }
    rate = getRateForRole(role);
}
void Employee::displayDetails() const{
    cout << "Employee ID: " << EmployeeID << endl;
    cout << "Name: " << name << endl;
    cout << "Base Salary: " << baseSalary << endl;
    cout << "Role: " << toString(role) << endl;
    cout << "Status: " << toString(status) << endl;
    cout << "Type: " << toString(type) << endl;
    cout << "Rate: " << rate << endl;
}
void Employee::updateStatus(Status newstatus){
    status = newstatus;
}
string Employee::getEmployeeID() const{
    return EmployeeID;
}
string Employee::getName() const{
    return name;
}
Role Employee::getRole()const{
    return role;
}
Status Employee::getStatus()const{
    return status;
}
Type Employee::getType()const{
    return type;
}