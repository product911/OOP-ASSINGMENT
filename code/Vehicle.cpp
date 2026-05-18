#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(int id, string b, string m, int y, float p, int mil)
    : vehicleId(id), engine1()
{
    brand = b;
    model = m;
    year = y;
    price = p;
    mileage = mil;
}

void Vehicle::displayVehicle() const
{
    cout << "ID: " << vehicleId << " | " << brand << " " << model
         << " | Year: " << year << " | Price: " << price
         << " | Mileage: " << mileage << endl;
    engine1.displaySpecs();
}

bool Vehicle::matchesSearch(string keyword) const
{
    return (brand == keyword || model == keyword);
}

string Vehicle::getBrand() const { return brand; }
string Vehicle::getModel() const { return model; }
float Vehicle::getPrice() const { return price; }
int Vehicle::getYear() const { return year; }
int Vehicle::getMileage() const { return mileage; }
int Vehicle::getId() const { return vehicleId; }
void Vehicle::setPrice(float p) { price = p; }
void Vehicle::setMileage(int m) { mileage = m; }

// == operator: two vehicles are equal if their price matches
//for duplicate listing detection
bool Vehicle::operator==(const Vehicle &other) const
{
    return (price == other.price && brand == other.brand && model == other.model);
}

// + operator: gives combined mileage
int Vehicle::operator+(const Vehicle &other) const
{
    return this->mileage + other.mileage;
}

// Friend: checks if two vehicles are the same using private fields directly
bool compareVehicles(const Vehicle &v1, const Vehicle &v2)
{
    return (v1.brand == v2.brand && v1.model == v2.model && v1.year == v2.year);
}
