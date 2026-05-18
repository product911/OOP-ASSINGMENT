#include "Favorite.h"
#include <iostream>

Favorite::Favorite() { vehicle = nullptr; }

void Favorite::addFavorite(Vehicle *v) { vehicle = v; }

void Favorite::showFavorite() const
{
    if (vehicle != nullptr)
        vehicle->displayDetails();  // Polymorphism: shows Car or Bike
    else
        cout << "No favorite saved." << endl;
}

Vehicle *Favorite::getVehicle() const { return vehicle; }
