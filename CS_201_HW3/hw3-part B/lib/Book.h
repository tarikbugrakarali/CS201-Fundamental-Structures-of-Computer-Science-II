#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;

/*
**
** Name: Tarýk Buðra Karali
** ID: 21703937
** Section :2
**
*/

class Book {

    public:
        Book (const int id, const string title, const int yearOfBook, int checkedOutStudNo);
        Book ();
        const int getBookId();
        const string getTitle();
        const int getYear();
        int getCheckedOutStudNo();
        void display();


     private:
        const int bookId;
        const string title;
        const int year;
        int checkedOutStudNo;
};
#endif // BOOK_H
