#pragma once
#include <iostream>
#include <string>

using namespace std;

const int MAX_CITIES = 10;

class City
{
private:
    string name; // Name of the city
    int id;      // Unique identifier for the city
public:
    // Default constructor
    City() : name("NULL"), id(0)
    {}

    // Parameterized constructor
    City(string name, int id) : name(name), id(id)
    {}

    // Function to get the name of the city
    string getName()
    {
        return this->name;
    }

    // Function to get the unique identifier of the city
    int getId()
    {
        return this->id;
    }
};
