#include "include.h"

void print_books()
{
	for(int j=0;j<i;j++)
	{
		cout << " " << arr[j].title;
	        cout << " " << arr[j].author;
		cout << " " << arr[j].isbn;
	        cout << " " << (arr[j].available ? "HASANELI E" : "ANHASANELI E") << endl;
	}
}

void print_books(int j)
{
	cout << " " << arr[j].title;
	cout << " " << arr[j].author;
        cout << " " << arr[j].isbn;
        cout << " " << (arr[j].available ? "HASANELI E" : "ANHASANELI E") << endl;
}
