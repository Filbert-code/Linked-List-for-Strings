#ifndef SLLSTRING_H
#define SLLSTRING_H
#include "Node.h"

template <class T>
class SLLString
{
private:
    Node<T> *head = NULL;
    int length = 0;

public:
    SLLString() { head = NULL; } // default constructor
};

#endif