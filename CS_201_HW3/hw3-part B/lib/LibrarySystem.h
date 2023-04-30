#ifndef LIBRARYSYSTEM_H_INCLUDED
#define LIBRARYSYSTEM_H_INCLUDED
#include <string>
#include "Book.h"
#include "Student.h"
using namespace std;

/*
**
** Name: Tarýk Buðra Karali
** ID: 21703937
** Section :2
**
*/

class StudentList
{

    public:
        StudentList();
        ~StudentList();
        void addStudent(int studentId, string name);
        void removeNode(int index);
        bool isEmpty() const;
        int getLength() const;
        Student* retrieve(int index);

        bool doesExist(int studentId);
        void display();
        int getIndexById(int studentId);
        Book* returnBook(int bookId);
    private:
        struct StudentListNode{
            Student* item;
            StudentListNode* next;
            StudentListNode* prev;
        };

    int sizeOfStudentList;
    StudentListNode* head;

    StudentListNode *find(int index);
};


class LibrarySystem {

    public:
        LibrarySystem();
        ~LibrarySystem();
        void addBook( const int bookId, const string title, const int year );
        void deleteBook( const int bookId );
        void addStudent( const int studentId, const string name );
        void deleteStudent( const int studentId );
        void checkoutBook( const int bookId, const int studentId );
        void returnBook( const int bookId );
        void showAllBooks();
        void showBook( const int bookId );
        void showStudent( const int studentId );
        bool doesCheckedOut(int bookId);

    private:
        BookList* listOfBooks;
        StudentList* listOfStudents;

};



#endif // LIBRARYSYSTEM_H_INCLUDED
