// Author: Alex Filbert
// Date: 11/1/2020
// Course: CS 300B
// Assignment: Homework 4
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
    SLLString() { head = NULL; }                   // default constructor
    SLLString(const string &other);                // copy constructor taking a C++ string as parameter
    ~SLLString();                                  // destructor; deletes the linked list Nodes
    SLLString(const SLLString &other);             // copy constructor
    SLLString &operator=(const SLLString &other);  // overloaded assignment operator
    int length();                                  // returns the length of the linked list
    SLLString &operator+=(const SLLString &other); // concatenates two SLLString linked lists
    char &operator[](const int n);                 // get character at index n
    // find the index of the first occurrence of substring in the current string. Returns -1 if not found
    int findSubstring(const SLLString &substring); // returns the index of the substring in the current string
    void erase(char c);                            // erase all occurances of character c from the current string.
    // overloaded insertion operator allows for the output of the state of the linked list to the console
    friend ostream &operator<<(ostream &output, SLLString &s)
    {
        Node *current = s.head;
        while (current != NULL)
        {
            output << current->data;
            current = current->next;
        }
        return output;
    }
};

#endif