#ifndef SIMPLELIBRARYSYSTEM_H_INCLUDED
#define SIMPLELIBRARYSYSTEM_H_INCLUDED
#include <string>
#include "SimpleStudent.h"
using namespace std;

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


class SimpleLibrarySystem {

    public:
        SimpleLibrarySystem();
        ~SimpleLibrarySystem();
        void addStudent( const int studentId, const string name );
        void deleteStudent( const int studentId );
        void showStudent( const int studentId );

    private:
        StudentList* listOfStudents;

};



#endif // SIMPLELIBRARYSYSTEM_H_INCLUDED
