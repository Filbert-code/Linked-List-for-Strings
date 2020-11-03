#include "SLLString.h"
using namespace std;

SLLString::SLLString(const string &other)
{
    head = NULL;       // call the default constructor
    operator+=(other); // keeps track of Node at the end of the linked list
}

SLLString::~SLLString()
{
    cout << "Deleting String..." << endl;
    Node *current = head;
    while (current->next != NULL)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    delete current;
}

SLLString::SLLString(const SLLString &other)
{
    *this = other;
}

SLLString &SLLString::operator=(const SLLString &other)
{
    // deep copy
    head = NULL;
    Node *endNode;
    Node *otherNode = other.head;
    while (otherNode->next != NULL)
    {
        Node *newNode = new Node;
        if (head == NULL)
        {
            head = otherNode;
            endNode = head;
        }
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

int SLLString::length()
{
    return size;
}

SLLString &SLLString::operator+=(const string &other)
{
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

    // iterating through the string argument to add the new string to the
    // end of the current linked list
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
    return *this;
}


