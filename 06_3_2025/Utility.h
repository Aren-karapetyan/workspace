#pragma once
#include <string>
#include <vector>
#include "Employee.h"

using namespace std;

void validateInput(const string& input);
Employee* searchEmployeeByID(const vector<Employee*>& employees, const string& id);
Employee* searchEmployeeByName(const vector<Employee*>& employees, const string& name);
void formatDisplay(const Employee* emp);