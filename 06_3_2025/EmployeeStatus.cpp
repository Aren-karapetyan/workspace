#include "EmployeeStatus.h"
#include <iostream>

using namespace std;    

string toString(Role role){
    switch(role){
        case Role::Intern:
            return "Intern";
        case Role::Junior:
            return "Junior";
        case Role::Middle:
            return "Middle";
        case Role::Senior:
            return "Senior";
        default:
            return "Invalid Role";

    }
}
string toString(Status status){
    switch(status){
        case Status::Active:
            return "Active";
        case Status::OnLeave:
            return "On Leave";
        case Status::Inactive:
            return "Inactive";
        case Status::Retired:
            return "Retired";
        default:
            return "Invalid Status";
    }
}
string toString(Type type){
    switch(type){
        case Type::FullTime:
            return "Full Time";
        case Type::PartTime:
            return "Part Time";
        default:
            return "Invalid Type";
    }
}
double getRateForRole(Role role){
    switch(role){
        case Role::Intern:
            return 1.0;
        case Role::Junior:
            return 1.2;
        case Role::Middle:
            return 1.5;
        case Role::Senior:
            return 2.0;
        default:
            return 0.0;
    }
}