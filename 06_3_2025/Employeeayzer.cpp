#pragma once
#include <iostream>
#include <string>
#include "EmployeeStatus.h"

enum class Role { Intern, Junior, Middle, Senior };
enum class EmploymentType { FullTime, PartTime };

class Employee {
protected:
    std::string employeeID;
    std::string name;
    double baseSalary;
    Role role;
    EmploymentType employmentType;
    EmployeeStatus status;
    double rate; // Կախված է role-ից

public:
    Employee(std::string id, std::string empName, double salary, Role empRole, EmploymentType empType);
    virtual ~Employee() = default; 

    virtual double calculateSalary() const = 0; // 🔹 Հաշվարկում է աշխատավարձը (Pure Virtual)
    virtual void promote(); // 🔹 Աշխատակիցին բարձրացնում է պաշտոնի մեջ (++ Role)
    virtual void displayDetails() const; // 🔹 Ցուցադրում է աշխատակցի տվյալները

    void updateStatus(EmployeeStatus newStatus); // 🔹 Թարմացնում է աշխատակցի կարգավիճակը
    void updateRole(Role newRole); // 🔹 Թարմացնում է աշխատակցի դերը

    std::string getEmployeeID() const; // 🔹 Վերադարձնում է աշխատակցի ID-ն
    std::string getName() const; // 🔹 Վերադարձնում է աշխատակցի անունը
    Role getRole() const; // 🔹 Վերադարձնում է աշխատակցի դերը
    EmployeeStatus getStatus() const; // 🔹 Վերադարձնում է կարգավիճակը
};
#pragma once
#include "Employee.h"

class FullTimeEmployee : public Employee {
public:
    FullTimeEmployee(std::string id, std::string empName, double salary, Role empRole);
    double calculateSalary() const override; // 🔹 Հաշվարկում է ֆիքսված աշխատավարձ (Base Salary * Rate)
    void displayDetails() const override; // 🔹 Ցուցադրում է լրացուցիչ տվյալներ Full-Time աշխատակիցների համար
};
#pragma once
#include "Employee.h"

class PartTimeEmployee : public Employee {
private:
    double hoursWorked;
    double hourlyWage;

public:
    PartTimeEmployee(std::string id, std::string empName, double hourlyWage, double hoursWorked, Role empRole);
    double calculateSalary() const override; // 🔹 Հաշվարկում է աշխատավարձը (ժամավճար * աշխատած ժամ * Rate)
    void displayDetails() const override; // 🔹 Ցուցադրում է Part-Time-ի մասին տվյալները
};
#pragma once
#include <string>

enum class EmployeeStatus { Active, OnLeave, Inactive, Retired };

std::string toString(Role role); // 🔹 Վերադարձնում է դերի տեքստային տարբերակը
std::string toString(EmployeeStatus status); // 🔹 Վերադարձնում է կարգավիճակի տեքստային տարբերակը
std::string toString(EmploymentType type); // 🔹 Վերադարձնում է աշխատանքի տեսակի տեքստային տարբերակը
double getRateForRole(Role role); // 🔹 Վերադարձնում է Role-ին համապատասխան գանձման գործակիցը (Intern = 1.0, Senior = 2.0)
#pragma once
#include <string>
#include <vector>
#include "Employee.h"

void validateInput(const std::string& input); // 🔹 Վավերացնում է մուտքային տվյալները
Employee* searchEmployeeByID(const std::vector<Employee*>& employees, const std::string& id); // 🔹 Փնտրում է աշխատակցին ըստ ID-ի
Employee* searchEmployeeByName(const std::vector<Employee*>& employees, const std::string& name); // 🔹 Փնտրում է աշխատակցին ըստ անունի
void formatDisplay(const Employee* emp); // 🔹 Ցուցադրում է աշխատակցի ձևաչափված տվյալները
