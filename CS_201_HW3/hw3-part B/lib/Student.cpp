#include "Book.h"
#include "Student.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

/*
**
** Name: Tarýk Buðra Karali
** ID: 21703937
** Section :2
**
*/
Student::Student (const int id, const string studentName): studentId(id),name(studentName)
{
   borrowedBooks = new BookList();
}

Student:: ~Student()
{
    delete borrowedBooks;
}

int Student::getStudentId()
{
    return this->studentId;
}

string Student::getName()
{
    return name;
}

BookList* Student::getBorrowedBooks()
{
    return borrowedBooks;
}

void Student::display()
{
    cout << "Student id: " << studentId << "       Student name: " << name << endl;

    if(getBorrowedBooks()->getLength() == 0)
    {
        cout << "Student " << studentId << " has no books" << endl;
    }

    else
    {
        cout<< "Student " << studentId <<" has checked out the following books:" << endl;
        cout<< "Book id "  <<setw(15)<< "Book name " <<setw(30)<< "Year" <<setw(10) << "Status" << endl;
        borrowedBooks->display();
    }
}

BookList::BookList()
{
    sizeOfList = 0;
    head = NULL;
}

BookList::~BookList()
{
    while (!isEmpty())
    {
        removeBook(1);
    }
}

BookList::BookListNode::~BookListNode()
{
    delete item;
}

int BookList::getLength() const
{
   return sizeOfList;
}

bool BookList::isEmpty() const
{
   return (sizeOfList == 0);
}

void BookList::addBook(int bookId, string name, int year, int studentId)
{
    if(bookId < 1)
    {
        cout<< "Invalid Book ID !"<<endl;
    }

    else
    {
        if( getLength() > 0 )
        {
            BookListNode* prev = find(sizeOfList);
            prev->next = new BookListNode;
            prev->next->item = new Book (bookId, name, year, studentId);
            prev->next->next = head;
        }

        else
        {
            head = new BookListNode;
            head -> item = new Book (bookId, name, year, studentId);
            head -> next = head;
        }

        sizeOfList++;
    }
}

void BookList::removeBook(int index)
{
   if (!(index < 1) && !(index > getLength()))
   {
      if (getLength() == 1)
      {
            delete head;
            head = NULL;
      }

      else
      {
           BookListNode* cur;

           if (index == 1)
           {
              cur = head;
              head = head ->next;
           }

           else
           {
              BookListNode* prev = find(index-1);
              cur  = prev -> next;
              prev->next = cur->next;
           }

           delete cur;
      }

      sizeOfList--;
   }
}

BookList::BookListNode* BookList::find(int index)
{
  if ( (index < 1) || (index > getLength()) )
      return NULL;

  else
  { // count from the beginning of the list
      BookListNode *cur = head;
      for (int skip = 1; skip < index; ++skip)
         cur = cur->next;
      return cur;
  }
}

Book* BookList::retrieve(int index)
{
    BookListNode* cur = find(index);
    return cur->item;
}

bool BookList::doesExist(int bookId)
{
      BookListNode* cur = head;

      for (int i = 1; i < getLength() + 1; ++i)
      {
         if ( (cur->item)->getBookId() == bookId)
         {
            return true;
            break;
         }

         cur = cur->next;
      }

      return false;
}


int BookList::findBookIndex(int bookId)
{
    BookListNode* cur = head;

    for(int i = 1; i < getLength() + 1; i++)
    {
        if(cur->item->getBookId() == bookId)
        {
            return i;
        }

        cur = cur -> next;
    }

    return -1;
}



void BookList::display()
{
    if (getLength() != 0)
    {
        BookListNode* cur = head;

        for( int i = 1; i < getLength() + 1; i++)
        {
            cur->item->display();
            cur = cur-> next;
        }
    }

    else
    {
        cout<<"List is empty !"<<endl;
    }
}
