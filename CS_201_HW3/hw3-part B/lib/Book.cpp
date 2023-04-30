#include "Book.h"
#include <string>
#include <iostream>

using namespace std;

/*
**
** Name: Tarýk Buðra Karali
** ID: 21703937
** Section :2
**
*/

Book::Book(const int id, const string bookName, const int yearOfBook,  int checkedOutStudNo): bookId(id),title(bookName),year(yearOfBook)
{

    this->checkedOutStudNo = checkedOutStudNo;
}


const int Book::getBookId()
{
    return this->bookId;
}

const string Book::getTitle()
{
    return this->title;
}

const int Book::getYear()
{
    return this->year;
}

int Book::getCheckedOutStudNo()
{
    return checkedOutStudNo;
}

void Book::display()
{
    if (getCheckedOutStudNo() > 0 )
    {
       cout << "Book ID: "<< bookId << ", Book Title: " << title << ", Year: " << year << ", "<< "Checked out by student " << checkedOutStudNo << endl;
    }
    else
    {
       cout << "Book ID: "<< bookId << ", Book Name: " << title << ", Year: " << year << ", "<< "Not checked out" << endl;
    }
}
