#ifndef  STACK_H
#define  STACK_H
#include <string>
#include <iomanip>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Stack
{
      private:

           struct Node
            {
               string data;
               struct Node* link;
            };

            struct Node* top;
      public:
            Stack();
            ~Stack();
            void push(string data);
            int isEmpty();
            string peek();
            void pop();
            void display();



};
#endif
