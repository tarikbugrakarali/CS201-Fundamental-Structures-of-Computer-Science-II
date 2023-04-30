#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "Book.h"

using namespace std;

/*
**
** Name: Tarýk Buðra Karali
** ID: 21703937
** Section :2
**
*/
class BookList
 {
    private:
        struct BookListNode{
            Book* item;
            BookListNode *next;
            ~BookListNode();
        };
    int sizeOfList;
    BookListNode* head;


    public:
        BookList();
        ~BookList();

        bool isEmpty() const;
        int getLength() const;
        BookListNode* find(int index);
        Book* retrieve(int index);
        void removeBook(int bookId);
        void addBook(int bookId, string name, int year, int);
        bool doesExist(int bookId);
        void display();
        int findBookIndex(int bookId);
};

class Student
{
    public:
        Student(const int id, const string studentName);
        ~Student();
        bool isEmpty() const;
        int getStudentId();
        BookList* getBorrowedBooks();
        string getName();
        void display();

    private:
        const int studentId;
        const string name;
        BookList* borrowedBooks;
};
#endif // STUDENT_H

