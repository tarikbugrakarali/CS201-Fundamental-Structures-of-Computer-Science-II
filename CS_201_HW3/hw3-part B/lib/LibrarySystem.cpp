#include "LibrarySystem.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
using namespace std;


/*
**
** Name: Tarýk Buðra Karali
** ID: 21703937
** Section :2
**
*/

StudentList::StudentList(){
    sizeOfStudentList = 0;
    head = NULL;
}

StudentList::~StudentList()
{
    while(!isEmpty())
    {
        removeNode(1);
    }
}

bool StudentList::isEmpty() const
{
    return (sizeOfStudentList == 0);
}

void StudentList::addStudent(int studentId, string name)
{
    if(studentId < 1)
    {
        cout<< "Invalid Book ID !"<<endl;
    }

    else
    {
        if(getLength() > 0)
        {
           StudentListNode* cur = head->prev;
           cur->next = new StudentListNode;
           cur->next -> prev = cur;
           cur->next-> next = head;
           head->prev = cur->next;
           cur->next->item = new Student (studentId, name);
        }

        else
        {
           head = new StudentListNode;
           head -> next = head;
           head -> prev = head;
           head -> item = new Student (studentId, name);

        }

        sizeOfStudentList++;
    }
}

int StudentList::getLength() const
{
    return sizeOfStudentList;
}

void StudentList::removeNode(int index)
{

    if (index > 0 && index < getLength())
    {

        if (getLength() == 1)
        {
          delete head;
          head = NULL;
          head -> prev = NULL;
          head -> next = NULL;
        }

        else
        {
           StudentListNode *cur;

           if (index == 1)
           {
                cur = head;
                head = head ->next;
                head ->next-> prev = head ->prev;
                head ->prev -> next = head ->next;
           }

           else
           {
               cur= find(index);
               StudentListNode* nextStud = cur ->next;
               StudentListNode* prevStud = cur ->prev;
               prevStud -> next = nextStud;
               nextStud -> prev = prevStud;
           }

           delete cur;
           cur = NULL;
        }

        --sizeOfStudentList;
    }
}

StudentList::StudentListNode* StudentList::find(int index)
{
    if ( (index < 1) || (index > sizeOfStudentList) )
    {
      return NULL;
    }

    else{ // count from the beginning of the list

      StudentListNode *cur = head;

      for (int skip = 1; skip < index; ++skip)
         cur = cur->next;

      return cur;
   }
}

Student* StudentList::retrieve(int index)
{
    StudentListNode* cur = find(index);
    return cur->item;
}

bool StudentList::doesExist(int studentId)
{
      StudentListNode* cur = head;
      for (int i = 1; i < sizeOfStudentList + 1; ++i)
      {
         if ( (cur->item)->getStudentId() == studentId){
            return true;
         }
         cur = cur->next;
      }

      return false;
}

int StudentList::getIndexById(int studentId){
    StudentListNode* cur = head;
    for(int i = 1; i < sizeOfStudentList+1;i++){
        if(cur->item->getStudentId() == studentId){
            return i;
        }
        cur = cur -> next;
    }
    return -1;
}

Book* StudentList::returnBook(int bookId)
{
    BookList* tempList;
    Book* toReturn = NULL;
    Book* book;

    for( int i = 1; i < getLength() +1; i++)
    {
        tempList = find(i)->item->getBorrowedBooks();

        for(int j = 1; j < tempList->getLength()+1;i++)
        {
            book = tempList->retrieve (j);

            if (book->getBookId() == bookId)
            {
                toReturn = new Book (toReturn->getBookId(),toReturn->getTitle(),toReturn->getYear(),0);
                tempList->removeBook(j);
                return toReturn;
            }
        }
    }

    return toReturn;
}

void StudentList::display()
{
    if (sizeOfStudentList != 0)
    {

        StudentListNode* cur = head;

        for( int i = 1; i < sizeOfStudentList + 1; i++)
        {
            cur->item->display();
            cur = cur-> next;
        }
    }

    else
        cout<<"List is empty !" <<endl;
}


LibrarySystem::LibrarySystem()
 {

    listOfBooks = new BookList();
    listOfStudents = new StudentList();

}

LibrarySystem:: ~LibrarySystem()
{
    delete listOfBooks;
    delete listOfStudents;
}

void LibrarySystem:: addBook (const int bookId, const string title, const int year)
{

    if (bookId < 1)
    {
        cout << "Invalid Book ID "<<endl;
    }

    else
    {
        if(listOfBooks->doesExist(bookId))
        {
           cout << "Book " << bookId << " already exists" <<endl;
        }

        else
        {
           listOfBooks->addBook(bookId, title, year, 0);
           cout << "Book " << bookId << " has been added" <<endl;
        }
    }
}

void LibrarySystem::deleteBook( const int bookId )
{
    if (listOfBooks->doesExist(bookId) || doesCheckedOut(bookId))
    {
        int no;

        if (doesCheckedOut(bookId))
        {

           returnBook(bookId);
           no = listOfBooks->findBookIndex(bookId);
           listOfBooks->removeBook(no);
           cout << "Book " << bookId << " has been deleted" <<endl;
        }

        else
        {
           no = listOfBooks->findBookIndex(bookId);
           cout << "Book " << bookId << " has not been checked out" <<endl;
           listOfBooks->removeBook(no);
           cout << "Book " << bookId << " has been deleted" <<endl;
        }
    }

    else
    {
            cout << "Book "<< bookId <<" does not exists"<<endl;
    }
}

void LibrarySystem::addStudent( const int studentId, const string name )
{
    if (studentId < 0)
    {
        cout << "Invalid ID "<<endl;
    }

    else
    {
        if (listOfStudents->doesExist(studentId))
        {
            cout << "Student " << studentId << " already exists" <<endl;
        }

        else
        {
            listOfStudents->addStudent(studentId,name);
            cout << "Student " << studentId << " has been added" <<endl;
        }
    }
}

void LibrarySystem::deleteStudent( const int studentId )
{
    if(listOfStudents->doesExist(studentId))
    {
        if ( listOfStudents->retrieve(listOfStudents->getIndexById(studentId))->getBorrowedBooks()->getLength() > 0)
        {
            for ( int j = 1; j < listOfStudents->retrieve(listOfStudents->getIndexById(studentId))->getBorrowedBooks()->getLength()+1; j++)
            {
                Book* book = listOfStudents->retrieve(listOfStudents->getIndexById(studentId))->getBorrowedBooks()->retrieve(j);
                listOfBooks->addBook(book->getBookId(), book->getTitle(), book->getYear(),0);

                cout << "Book " << book->getBookId() << " has been returned" << endl;
            }
        }

        listOfStudents->removeNode(listOfStudents->getIndexById(studentId));
        cout << "Student " << studentId << " has been deleted." << endl;
    }

    else
    {
        cout << "Student " << studentId << " does not exist" << endl;
    }
}

void LibrarySystem::checkoutBook( const int bookId, const int studentId )
{
    if(listOfStudents->doesExist(studentId))
    {
       if ( doesCheckedOut(bookId) )
       {
        cout << "Book " << bookId << " has been already checked out by another student " << endl;
       }

       else if (listOfBooks->doesExist(bookId))
       {
         Student* targetStudent = listOfStudents->retrieve ( listOfStudents->getIndexById(studentId) );
         Book* targetBook = listOfBooks->retrieve (listOfBooks->findBookIndex(bookId));
         targetStudent->getBorrowedBooks()->addBook(targetBook->getBookId(), targetBook->getTitle(), targetBook->getYear(),studentId);
         listOfBooks->removeBook(listOfBooks->findBookIndex(bookId));
         cout << "Book " << bookId << " has been checked out by student " << studentId << endl;
       }

       else
       {
        cout << "Book " << bookId << " does not exist for checkout"<< endl;
       }
    }

    else
    {
        cout << "Student " << studentId << " does not exist for checkout" << endl;
    }
}

void LibrarySystem::returnBook( const int bookId )
{
    if ( listOfBooks->doesExist(bookId))
    {
        cout << "Book "<< bookId <<" has not been checked out"<< endl;
    }

    else
    {
        if ( bookId > 0)
        {
           for ( int i = 1; i < listOfStudents->getLength()+1; i++)
           {
                for ( int j = 1; j < listOfStudents->retrieve(i)->getBorrowedBooks()->getLength()+1; j++)
                {
                    Book* removedBook = listOfStudents->retrieve(i)->getBorrowedBooks()->retrieve(j);

                    if (  listOfStudents->retrieve(i)->getBorrowedBooks()->retrieve(j)->getBookId() == bookId)
                    {
                       listOfBooks->addBook(removedBook->getBookId(), removedBook->getTitle(), removedBook->getYear(),0);
                       listOfStudents->retrieve(i)->getBorrowedBooks()->removeBook(j);
                    }
                }
           }

           cout << "Book " << bookId << " has been returned." << endl;
        }

        else
        {
            cout << "Invalid Book Id" << endl;
        }
    }
}

void LibrarySystem::showAllBooks()
{
    cout<< "Book id \t" << "Book name \t" << "Year" << " \t\t Status" << endl;
    listOfBooks->display();

    for (int i = 1; i < listOfStudents->getLength() + 1; i++)
    {
        listOfStudents->retrieve(i)->getBorrowedBooks()->display();
    }
}

void LibrarySystem::showBook( const int bookId )
{

    if (listOfBooks->doesExist(bookId))
    {

        listOfBooks->retrieve (listOfBooks->findBookIndex(bookId))->display();
    }

    else if ( doesCheckedOut(bookId))
    {
        for (int i = 1; i < listOfStudents->getLength() + 1; i++)
        {
           for (int j = 1; j < listOfStudents->retrieve(i)->getBorrowedBooks()->getLength()+1;j++)
           {
              if (listOfStudents->retrieve(i)->getBorrowedBooks()->retrieve(j)->getBookId() == bookId)
              {
                  listOfStudents->retrieve(i)->getBorrowedBooks()->retrieve(j)->display();
              }
           }
        }
    }

    else
    {
        cout << "Book " << bookId << " does not exist" << endl;
    }
}


void LibrarySystem::showStudent( const int studentId )
{

    if (listOfStudents->doesExist(studentId))
    {
        listOfStudents->retrieve(listOfStudents->getIndexById(studentId))->display();
    }

    else
    {
        cout<<"Student "<< studentId << " does not exist"<<endl;
    }
}

bool LibrarySystem::doesCheckedOut( int bookId )
{
    for (int i = 1; i < listOfStudents->getLength() + 1; i++)
    {
        if (listOfStudents->retrieve(i)->getBorrowedBooks()->getLength() > 0 && listOfStudents->retrieve(i)->getBorrowedBooks()->doesExist(bookId))
        {
            return true;
        }
    }

    return false;
}
