#ifndef NODE_H
#define NODE_H
#include <cstddef>

class Node
{
public:
    char data;
    Node *next = NULL;
};
#endif