#include "Car.h"
#include <iostream>

Car::Car(int id, string b, string m, int y, float p, int mil,
         int doors, string trans, bool sunroof)
    : Vehicle(id, b, m, y, p, mil)
{
    numDoors = doors;
    transmission = trans;
    isSunroof = sunroof;
}

// Overrides pure virtual from IListable by Vehicle - Displays car-specific details
void Car::displayDetails() const
{
    cout << "-- CAR LISTING --" << endl;
    displayVehicle();
    cout << "Doors: " << numDoors << " | Transmission: " << transmission
         << " | Sunroof: " << (isSunroof ? "Yes" : "No") << endl;
}

//Override: string search (inherited behavior)
bool Car::matchesSearch(string keyword) const
{
    return Vehicle::matchesSearch(keyword) || transmission == keyword;
}

// Overloaded - search by price
bool Car::matchesSearch(float minPrice, float maxPrice) const
{
    return (price >= minPrice && price <= maxPrice);
}

int Car::getNumDoors() const { return numDoors; }
string Car::getTransmission() const { return transmission; }
