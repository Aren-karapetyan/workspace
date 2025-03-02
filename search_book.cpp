#include "include.h"

bool strhavasar(const char str1[], const char str2[]) {
    int k = 0;
    while (str1[k] != '\0' && str2[k] != '\0') {
        if (str1[k] != str2[k]) {
            return false;
        }
        k++;
    }
    return true;
}
void search_book()
{
	char search_title[100];
	char search_author[100];
	cout << "Enter title: ";
    	cin.ignore();
    	fgets(search_title, 100, stdin); 
    	cout << "Enter author: ";
    	fgets(search_author, 100,stdin);
	for (int j = 0; j < i; j++)
	{
		if (strhavasar(arr[j].title, search_title))
		{
			print_books(j);
		}
		else if (strhavasar(arr[j].author, search_author))
		{
			print_books(j);
		}
	}
}


