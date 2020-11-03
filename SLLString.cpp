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

char &SLLString::operator[](const int n)
{
    if (n > size)
    {
        cout << "Index out of range" << endl;
        exit(0);
    }
    int index;
    Node *current = head;
    while (current->next != NULL)
    {
        if (n == index)
        {
            break; // we found the character and can exit the loop
        }
        current = current->next;
    }
    return current->data;
}

int SLLString::findSubstring(const SLLString &substring)
{
    int index;
    Node *currNode = head;
    while (currNode->next != NULL)
    {
        Node *subNode = substring.head;
        while (currNode->data == subNode->data)
        {
            if (subNode->next == NULL)
            {
                return index;
            }
            else if (currNode->next == NULL)
            {
                cout << "Substring not found." << endl;
                return -1;
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

void SLLString::erase(char c)
{
    Node *current = head;
    while (current->next != NULL)
    {
        if (current == head && current->data == c)
        {
            Node *temp = current;
            head = current->next;
            delete temp;
            current = head;
        }
        if (current->next->data == c)
        {
            Node *temp = current->next;
            if (current->next->next != NULL)
            {
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
