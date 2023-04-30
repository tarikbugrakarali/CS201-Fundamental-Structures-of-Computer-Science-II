#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Stack.h"
Stack :: Stack()
{

}
Stack :: ~Stack()
{

}

void Stack :: push(string data)
{

    struct Node* temp;
    temp = new Node();
    if (!temp)
    {
        cout << "\nHeap Overflow";
        exit(1);
    }

    temp->data = data;
    temp->link = top;
    top = temp;
}

int Stack :: isEmpty()
{
    return top == NULL;
}


string Stack :: peek()
{

    if (!isEmpty())
        return top->data;
    else
        exit(1);
}

void Stack :: pop()
{
    struct Node* temp;

    if (top == NULL)
    {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    else
    {
        temp = top;
        top = top->link;
        temp->link = NULL;
        free(temp);
    }
}


void Stack :: display()
{
    struct Node* temp;

    if (top == NULL)
    {
        cout << "\nStack Underflow";
        exit(1);
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
            cout << temp->data << "-> ";
            temp = temp->link;
        }
    }
}


