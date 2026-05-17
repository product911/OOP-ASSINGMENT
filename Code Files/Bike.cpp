#include "Bike.h"
#include <iostream>

Bike::Bike(int id, string b, string m, int y, float p, int mil,
           string bType, bool fairing, int gears)
    : Vehicle(id, b, m, y, p, mil)
{
    bikeType = bType;
    hasFairing = fairing;
    numGears = gears;
}

// Overrides pure virtual — demonstrates polymorphism with Car
// Same function call, different output based on object type
void Bike::displayDetails() const
{
    cout << "-- BIKE LISTING --" << endl;
    displayVehicle();
    cout << "Type: " << bikeType << " | Fairing: " << (hasFairing ? "Yes" : "No")
         << " | Gears: " << numGears << endl;
}

bool Bike::matchesSearch(string keyword) const
{
    return Vehicle::matchesSearch(keyword) || bikeType == keyword;
}

string Bike::getBikeType() const { return bikeType; }
int Bike::getNumGears() const { return numGears; }
