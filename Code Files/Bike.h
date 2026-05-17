#ifndef BIKE_H
#define BIKE_H

#include "Vehicle.h"
#include <string>
using namespace std;

// Bike inherits Vehicle — adds bike-specific attributes
// Implements displayDetails() differently from Car (polymorphism)
class Bike : public Vehicle
{
    string bikeType;    // Sports, Cruiser, Off-road
    bool hasFairing;    // full fairing or not
    int numGears;

public:
    // Parameterized constructor: Bike is always created with known specs
    Bike(int id = 0, string b = "Unknown", string m = "Unknown",
         int y = 0, float p = 0, int mil = 0,
         string bType = "Standard", bool fairing = false, int gears = 5);

    // Overrides pure virtual — shows bike-specific info
    void displayDetails() const override;

    bool matchesSearch(string keyword) const override;

    string getBikeType() const;
    int getNumGears() const;
};

#endif
