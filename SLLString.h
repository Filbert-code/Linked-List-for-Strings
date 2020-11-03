#ifndef SLLSTRING_H
#define SLLSTRING_H
#include "Node.h"
#include <iostream>
#include <string>
#include <ostream>

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
    SLLString &operator+=(const SLLString &other);
    char &operator[](const int n); // get character at index n
    // find the index of the first occurrence of substring in the current string. Returns -1 if not found.
    int findSubstring(const SLLString &substring);
    void erase(char c); // erase all occurances of character c from the current string.
    friend ostream &operator<<(ostream &output, SLLString &s)
    {
        Node *current = s.head;
        output << "Head->";
        while (current != NULL)
        {
            output << current->data << "->";
            current = current->next;
        }
        output << "NULL" << endl;
        return output;
    }
};

#endif