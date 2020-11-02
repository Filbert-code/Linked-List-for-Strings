#ifndef SLLSTRING_H
#define SLLSTRING_H
#include "Node.h"
#include <string>

using namespace std;

class SLLString
{
private:
    Node *head = NULL;
    int length = 0;

public:
    SLLString() { head = NULL; }    // default constructor
    SLLString(const string &other); // copy constructor taking a C++ string as parameter
    SLLString &operator+=(const string &other);
    void print()
    {
        Node *current = head;
        cout << "Head->";
        while (current != NULL)
        {
            cout << current->data << "->";
        }
        cout << "NULL" << endl;
    }
};

#endif