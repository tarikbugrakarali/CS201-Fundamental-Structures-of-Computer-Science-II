#include "SimpleStudent.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

Student::Student (const int id, const string studentName): studentId(id),name(studentName)
{
}

Student:: ~Student()
{
}

int Student::getStudentId()
{
    return this->studentId;
}

string Student::getName()
{
    return name;
}


void Student::display()
{
    cout << "Student id: " << studentId << "     Student name: " << name << endl;

}


