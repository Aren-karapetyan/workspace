#pragma once
#include <string>
#include <iostream>

using namespace std;

enum class Role{Intern, Junior, Middle, Senior};
enum class Type{FullTime, PartTime};
enum class Status {Active, OnLeave, Inactive, Retired };

string toString(Role role);
string toString(Status status);
string toString(Type type);
double getRateForRole(Role role);


