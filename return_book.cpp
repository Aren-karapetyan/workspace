#include "include.h"
void return_book()
{
        char search_isbn[20];
        cout << "Enter ISBN: ";
        cin.ignore();
        fgets(search_isbn, 20, stdin);
        for (int j = 0; j < i; j++)
        {
                if (strhavasar(arr[j].isbn, search_isbn) && !arr[j].available)
                {
                        cout << "YES";
                        arr[j].available = true;
                        return;
                }
        }
        cout << "book was not borrowed " << endl;
}
