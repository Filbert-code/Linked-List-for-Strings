#ifndef SLLSTRING_H
#define SLLSTRING_H
#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

class SLLString
{
private:
    Node *head;
    int size = 0;

public:
    SLLString() { head = NULL; }    // default constructor
    SLLString(const string &other); // copy constructor taking a C++ string as parameter
    ~SLLString();
    SLLString(const SLLString &other);
    SLLString &operator=(const SLLString &other);
    int length();
    SLLString &operator+=(const string &other);


    void print()
    {
        Node *current = head;
        cout << "Head->";
        while (current != NULL)
        {
            cout << current->data << "->";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

#endif