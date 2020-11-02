#include "SLLString.h"

SLLString::SLLString(const string &other)
{
    SLLString();
    
}

SLLString &SLLString::operator+=(const string &other)
{
    for(char letter: other)
    {
        Node *current = head;
        // iterate to the end of the linked list
        while(current->next != NULL)
        {
            current = current->next;
        }
        // create a new Node with the new letter and point the 
        // letter to the last node of the linked list
        Node newNode;
        newNode.data = letter;
        newNode.next = current;
    }
}