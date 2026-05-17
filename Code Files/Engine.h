#ifndef ENGINE_H
#define ENGINE_H

#include <string>
using namespace std;

class Engine
{
    int power;
    string fuelType;
    int capacity;

public:
    // Default + parameterized combined using default argument values
    // Used this way because Engine is always created with Vehicle — defaults make sense
    Engine(int power = 100, string fuelType = "Petrol", int capacity = 1300);

    void displaySpecs() const;
    int getPower() const;
    string getFuelType() const;
    int getCapacity() const;
};

#endif
