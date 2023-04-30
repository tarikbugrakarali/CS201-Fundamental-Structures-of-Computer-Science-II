#include "SimpleLibrarySystem.h"
#include <iostream> // for NULL
#include <stdexcept>
#include <string>
#include <iomanip>
using namespace std;

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
        //if ( sizeOfStudentList == 0 )
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
           //     StudentListNode* next = head ->next;
               // StudentListNode* last = head ->prev;
                //StudentListNode* toDelete = head;
                //cur= find(index);
                cur = head;
                head = head ->next;
                head ->next-> prev = head ->prev;
                head ->prev -> next = head ->next;
               // delete toDelete;
               // toDelete = NULL;
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

int StudentList::getIndexById(int studentId)
{
    StudentListNode* cur = head;

    for(int i = 1; i < getLength() +1;i++)
    {
           if(cur->item->getStudentId() == studentId)
           {
              return i;
              break;
           }

           cur = cur -> next;
    }

    return -1;
}

void StudentList::display()
{
    if(getLength() == 0)
    {
        cout<<"list is empty" <<endl;
    }

    else
    {
        StudentListNode* cur = head;

        for( int i = 1; i < sizeOfStudentList + 1; i++)
        {
            cur->item->display();
            cur = cur-> next;
        }
    }
}

SimpleLibrarySystem::SimpleLibrarySystem()
{
    listOfStudents = new StudentList();
}

SimpleLibrarySystem:: ~SimpleLibrarySystem()
{
    delete listOfStudents;
}

void SimpleLibrarySystem::addStudent( const int studentId, const string name )
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

void SimpleLibrarySystem::deleteStudent( const int studentId )
{
    if(listOfStudents->doesExist(studentId))
    {

        listOfStudents->removeNode(listOfStudents->getIndexById(studentId));
        cout << "Student " << studentId << " has been deleted." << endl;
    }

    else
    {
        cout << "Student " << studentId << " does not exist" << endl;
    }
}




void SimpleLibrarySystem::showStudent( const int studentId )
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

