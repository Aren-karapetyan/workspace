#pragma once
#include<iostream>
#include<string>
#include "EmployeeStatus.h"

using namespace std;

class Employee{
    protected:
        string EmployeeID;
        string name;
        double baseSalary;
        Role role;
        Status status;
        Type type;
        double rate;
    public:
        Employee(string id, string empName, double salary, Role empRole, Type empType);
        virtual ~Employee() = default;

        virtual double calculateSalary() const = 0;
        virtual void promote();
        virtual void displayDetails() const;

        void updateStatus(Status newstatus);
        string getEmployeeID() const;
        string getName() const;
        Role getRole()const;
        Status getStatus()const;
        Type getType()const;
};