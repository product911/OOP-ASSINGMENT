#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include <string>
using namespace std;

// Car inherits Vehicle — adds car-specific attributes like doors and transmission
// Implements the pure virtual displayDetails() from Vehicle/IListable
class Car : public Vehicle
{
    int numDoors;
    string transmission;  // Manual or Automatic
    bool isSunroof;

public:
    // Parameterized constructor: Car always needs complete details at creation
    Car(int id = 0, string b = "Unknown", string m = "Unknown",
        int y = 0, float p = 0, int mil = 0,
        int doors = 4, string trans = "Manual", bool sunroof = false);

    // Overrides pure virtual from Vehicle — shows car-specific info
    void displayDetails() const override;

    // Function overloading: search by keyword OR by price range
    bool matchesSearch(string keyword) const override;
    bool matchesSearch(float minPrice, float maxPrice) const;

    int getNumDoors() const;
    string getTransmission() const;
};

#endif
