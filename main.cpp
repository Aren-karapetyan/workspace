#include "include.h"

int n,i=0;

Book * arr = NULL;

int main()
{
	cout<< "size of array of books";
	cin >> n;
	arr = new Book[n];
	for (int j = 0; j < n; j ++)
	{
		add_book();
	}
	search_book();
//	print_books();	
	delete[] arr;
arr;

}
