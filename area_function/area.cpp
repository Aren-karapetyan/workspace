#include <iostream>
using namespace std;
double area(double d)
{
    return (d / 2) * (d / 2) * 3, 14;
}
double area(double a, double b, char t)
{
    return a * b;
}
double area(double a, double h)
{
    return (a * h) / 2;
}
int area(int a)
{
    return a * a;
}
int main()
{
    cout << area(12.2) << endl << area(123, 22, 'a') << endl << area(12, 12) << endl << area(32) << endl;
    return 0;
}
