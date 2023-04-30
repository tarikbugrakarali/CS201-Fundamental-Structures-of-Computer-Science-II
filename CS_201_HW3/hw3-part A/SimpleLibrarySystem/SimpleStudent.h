
#ifndef SIMPLESTUDENT_H
#define SIMPLESTUDENT_H
#include <string>

using namespace std;



class Student
{
    public:
        Student(const int id, const string studentName);
        ~Student();
        bool isEmpty() const;
        int getStudentId();
        //BookList* getBorrowedBooks();
        string getName();
        void display();

    private:
        const int studentId;
        const string name;
       // BookList* borrowedBooks;
};
#endif // SIMPLESTUDENT_H
