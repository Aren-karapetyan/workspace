#include<iostream>

using namespace std;

class enum Role{
    Intem,
    Junior,
    Middle,
    Senior
}
class enum Status{
    Active,
    Onleave,
    Inactiv,
    Retired
}
class enum Type{
    FullTime,
    PartTime 
}
class enum 
class Employee{
    private:
        streing EmployeeID;
        streing name;
        double baseSalary;
        Role role;
        Status status;
        Type type;
        double rate;
    public:
        Employee(string EmployeeID, string name, double baseSalary, Role role, Status status, Type type, double rate);
        virtual ~Employee();

        virtual double calculateSalary() = 0;
        virtual void promote();
        virtual void displayDetails() = 0;

        void updateStatus(Status newstatus);
        string getEmployeeID() const;
        string getName() const;
        Role getRole()const;
        Status getStatus()const;
        Type getType()const;
};