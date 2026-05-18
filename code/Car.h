#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include <string>
using namespace std;

// Car inherits Vehicle - Implements the pure virtual displayDetails()
class Car : public Vehicle
{
    int numDoors;
    string transmission;  // Manual or Automatic
    bool isSunroof;

public:
    // Parameterized constructor
    Car(int id = 0, string b = "Unknown", string m = "Unknown",
        int y = 0, float p = 0, int mil = 0,
        int doors = 4, string trans = "Manual", bool sunroof = false);

    // Overrides pure virtual from Vehicle
    void displayDetails() const override;

    // Function overloading: by string OR by price
    bool matchesSearch(string keyword) const override;
    bool matchesSearch(float minPrice, float maxPrice) const;

    int getNumDoors() const;
    string getTransmission() const;
};

#endif
