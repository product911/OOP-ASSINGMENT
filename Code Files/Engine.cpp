#include "Engine.h"
#include <iostream>

Engine::Engine(int power, string fuelType, int capacity)
{
    this->power = power;
    this->fuelType = fuelType;
    this->capacity = capacity;
}

void Engine::displaySpecs() const
{
    cout << "Engine: " << power << "HP | " << fuelType << " | " << capacity << "cc" << endl;
}

int Engine::getPower() const { return power; }
string Engine::getFuelType() const { return fuelType; }
int Engine::getCapacity() const { return capacity; }
