// Author: Alex Filbert
// Date: 11/1/2020
// Course: CS 300B
// Assignment: Homework 4
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