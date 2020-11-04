// Author: Alex Filbert
// Date: 11/1/2020
// Course: CS 300B
// Assignment: Homework 4
#include <iostream>
#include "SLLString.h"

using namespace std;

int main()
{

    SLLString str("Hello World!");

    SLLString newStr;
    newStr = str;

    newStr += SLLString("CS@BC");
    newStr[6] = 'W';

    cout << newStr << endl;

    // sample prints 18 but should actually print 17 since there's
    // no space between str and "CS@BC" in the code but it exists in the sample
    cout << newStr.length() << endl;

    int loc = newStr.findSubstring(SLLString("World"));
    cout << loc << endl;

    newStr.erase('l');
    cout << newStr << endl;

    newStr.erase('C');
    cout << newStr << endl;

    return 0;
}
