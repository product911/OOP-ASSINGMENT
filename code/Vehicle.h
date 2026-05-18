#ifndef VEHICLE_H
#define VEHICLE_H

#include "Engine.h"
#include "IListable.h"
#include "ISearchable.h"
using namespace std;

// Vehicle is an abstract base it implements IListable and ISearchable
// Car and Bike inherit from Vehicle
class Vehicle : public IListable, public ISearchable
{
protected:
    int vehicleId;
    Engine engine1;     // COMPOSITION
    string brand;
    string model;
    int year;
    float price;
    int mileage;

public:
    // Default + parameterized constructor using initializer list
    Vehicle(int id = 0, string b = "Unknown", string m = "Unknown",
            int y = 0, float p = 0, int mil = 0);

    // Pure virtual
    virtual void displayDetails() const = 0;

    // Virtual display kept for backward compatibility with A1 code
    virtual void displayVehicle() const;

    // Search by keyword
    virtual bool matchesSearch(string keyword) const override;

    string getBrand() const;
    string getModel() const;
    float getPrice() const;
    int getYear() const;
    int getMileage() const;
    int getId() const;

    void setPrice(float p);
    void setMileage(int m);

    // Operator overloading compare two vehicles by price
    bool operator==(const Vehicle &other) const;

    // Operator overloading: combine mileage
    int operator+(const Vehicle &other) const;

    // Friend function: compares two vehicles across private fields
    // as Marketplace needs to compare without exposing all internals
    friend bool compareVehicles(const Vehicle &v1, const Vehicle &v2);

    virtual ~Vehicle() {}
};

#endif
