#include "include.h"


void add_book()
{
    Book new_book; 

    cout << "Enter title: ";
    cin.ignore();
    fgets( new_book.title, 100, stdin);  

    cout << "Enter author: ";
    fgets(new_book.author, 100,stdin);

    cout << "Enter ISBN: ";
    fgets(new_book.isbn, 20,stdin);

    cin >> new_book.available ;
    arr[i++]= new_book;
}
