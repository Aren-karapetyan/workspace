using namespace std;
#include <iostream>
#include <vector>
#include <string>
struct Book
{
	char title[100];
	char author[100];
	char isbn[20];
	bool available;

};
extern Book* arr;
extern int n, i;
void print_books();
void print_books(int);
void search_book();
void brrow_book();
void return_book();
bool strhavasar(const char str[],const char str1[]);

void add_book();
