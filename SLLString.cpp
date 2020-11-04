// Author: Alex Filbert
// Date: 11/1/2020
// Course: CS 300B
// Assignment: Homework 4
#include "SLLString.h"
using namespace std;

/* 
*  Copy constructor that returns a SLLString object with a deep copy of the
*  given SLLString argument.
*/
SLLString::SLLString(const string &other)
{
    head = NULL;   // call the default constructor
    Node *endNode; // keeps track of Node at the end of the linked list

    // get the last Node of the current linked list if the string is empty
    if (this->size != 0)
    {
        Node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        endNode = current;
    }

    /*
    *   iterating through the string argument to add the new string to the 
    *   end of the current linked list
    */
    for (char letter : other)
    {
        Node *newNode = new Node;
        // base case for when the linked list is initially empty
        if (head == NULL)
        {
            head = newNode;
            newNode->data = letter;
            endNode = head;
        }
        // appending the new Node to the end of the linked list
        else
        {
            newNode->data = letter;
            endNode->next = newNode;
            endNode = newNode;
        }
        size++;
    }
}
// The destructor; deletes the linked list Nodes.
SLLString::~SLLString()
{
    Node *current = head;
    while (current->next != NULL)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    delete current;
}

// Copy constructor; returns a deep copy with the current SLLString state
SLLString::SLLString(const SLLString &other)
{
    *this = other;
}

// Overloaded assignment operator; returns a deep copy with the current SLLString state
SLLString &SLLString::operator=(const SLLString &other)
{
    head = NULL;
    Node *endNode;                // keeps track of the last Node in the linked list
    Node *otherNode = other.head; // head of the SLLString argument
    while (otherNode->next != NULL)
    {
        Node *newNode = new Node;
        // assign head to otherNode when the current linked list is empty
        if (head == NULL)
        {
            head = otherNode;
            endNode = head;
        }
        // append the Node to the end of the current linked list
        else
        {
            newNode = otherNode;
            endNode->next = newNode;
            endNode = newNode;
        }
        size++;
        otherNode = otherNode->next;
    }
    return *this;
}

// Returns the length of linked list.
int SLLString::length()
{
    return size + 1; // add 1 due to 0-indexing
}

/*
*   Concatenates two SLLString linked lists and returns the new state of the current 
*   linked list.
*/
SLLString &SLLString::operator+=(const SLLString &other)
{
    Node *endNode; // keeps track of Node at the end of the linked list
    Node *current = head;
    Node *otherNode = other.head;

    // get the last Node of the current linked list if the string is empty
    if (this->size != 0)
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        endNode = current;
    }

    // iterating through the string argument to add the new string to the
    // end of the current linked list
    while (otherNode != NULL)
    {
        Node *newNode = new Node;
        // base case for when the linked list is initially empty
        if (head == NULL)
        {
            head = newNode;
            newNode->data = otherNode->data;
            endNode = head;
        }
        // appending the new Node to the end of the linked list
        else
        {
            newNode->data = otherNode->data;
            endNode->next = newNode;
            endNode = newNode;
        }
        size++;
        otherNode = otherNode->next;
    }
    return *this;
}

/*
*   Overloaded operator that returns a char-type found at the index given 
*   as an argument.
*/
char &SLLString::operator[](const int n)
{
    // boundary checks for the argument
    if (n > size || n < 0)
    {
        cout << "Index out of range" << endl;
        exit(0);
    }
    int index;
    Node *current = head;
    // search through the linked list for the matching char if there is one
    while (current->next != NULL)
    {
        if (n == index)
        {
            break; // we found the character and can exit the loop
        }
        current = current->next;
        index++;
    }
    return current->data;
}

// Returns the starting index of a substring inside the current string
int SLLString::findSubstring(const SLLString &substring)
{
    int index;
    Node *currNode = head;
    // iterate through the linked list
    while (currNode->next != NULL)
    {
        Node *subNode = substring.head;
        /*
        *   if the first char of the string is found, start another
        *   loop to check if the rest of the substring is there
        */
        while (currNode->data == subNode->data)
        {
            if (subNode->next == NULL)
            {
                return index; // substring found
            }
            // reached the end of the current linked list
            else if (currNode->next == NULL)
            {
                cout << "Substring not found." << endl;
                return -1; // substring not found
            }
            currNode = currNode->next;
            subNode = subNode->next;
        }
        currNode = currNode->next;
        index++;
    }
    cout << "Substring not found." << endl;
    return -1;
}

// Erase all occurances of character c from the current string.
void SLLString::erase(char c)
{
    Node *current = head;
    // iterate through the current linked list
    while (current->next != NULL)
    {
        // special case for if the data if found at the head Node
        if (current == head && current->data == c)
        {
            Node *temp = current;
            head = current->next;
            delete temp;
            current = head;
        }
        // case for if the char is found in the rest of the linked list
        if (current->next->data == c)
        {
            // temporary Node to store the Node to be deleted
            Node *temp = current->next;
            // iterate through the list and check the data of the next Node
            if (current->next->next != NULL)
            {
                // point the current Node to skip the next Node if the char is found
                while (current->next->data == c)
                    current->next = current->next->next;
            }
            else
            {
                delete current->next;
                current->next = NULL;
                break;
            }
            delete temp;
        }
        current = current->next;
    }
}
