#ifndef 7_5_h
#define 7_5_h

#include <iostream>
#include <string>

class Person
{
public:
    string getName() const { return name; }
    string getAddress() const { return address; }
public:
    std::string name;
    std::string address;
}

#endif
