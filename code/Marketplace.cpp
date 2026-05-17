#include "Marketplace.h"
#include <iostream>

int Marketplace::systemListings = 0;

Marketplace::Marketplace()
{
    totalListings = 0;
}

void Marketplace::addListing(Listing l)
{
    // Check for duplicate before adding using overloaded == operator
    for (int i = 0; i < totalListings; i++)
    {
        if (listings[i] == l)
        {
            cout << "Duplicate listing detected. Not added." << endl;
            return;
        }
    }
    listings[totalListings] = l;
    totalListings++;
    systemListings++;
}

void Marketplace::removeListing(int vehicleId)
{
    for (int i = 0; i < totalListings; i++)
    {
        if (listings[i].getVehicle() != nullptr &&
            listings[i].getVehicle()->getId() == vehicleId)
        {
            for (int j = i; j < totalListings - 1; j++)
                listings[j] = listings[j + 1];
            totalListings--;
            cout << "Listing removed from marketplace." << endl;
            return;
        }
    }
    cout << "Listing not found." << endl;
}

void Marketplace::searchByBrand(string brand) const
{
    bool found = false;
    for (int i = 0; i < totalListings; i++)
    {
        if (listings[i].getVehicle() != nullptr &&
            listings[i].getVehicle()->getBrand() == brand &&
            listings[i].isApproved())
        {
            listings[i].displayListing();
            found = true;
        }
    }
    if (!found)
        cout << "No approved listings found for brand: " << brand << endl;
}

void Marketplace::searchByModel(string model) const
{
    bool found = false;
    for (int i = 0; i < totalListings; i++)
    {
        if (listings[i].getVehicle() != nullptr &&
            listings[i].getVehicle()->getModel() == model &&
            listings[i].isApproved())
        {
            listings[i].displayListing();
            found = true;
        }
    }
    if (!found)
        cout << "No listings found for model: " << model << endl;
}

void Marketplace::filterByPrice(float minPrice, float maxPrice) const
{
    bool found = false;
    for (int i = 0; i < totalListings; i++)
    {
        if (listings[i].getVehicle() != nullptr && listings[i].isApproved())
        {
            float p = listings[i].getVehicle()->getPrice();
            if (p >= minPrice && p <= maxPrice)
            {
                listings[i].displayListing();
                found = true;
            }
        }
    }
    if (!found)
        cout << "No listings found in price range." << endl;
}

void Marketplace::filterByYear(int minYear) const
{
    bool found = false;
    for (int i = 0; i < totalListings; i++)
    {
        if (listings[i].getVehicle() != nullptr && listings[i].isApproved() &&
            listings[i].getVehicle()->getYear() >= minYear)
        {
            listings[i].displayListing();
            found = true;
        }
    }
    if (!found)
        cout << "No listings found from year " << minYear << " onward." << endl;
}

void Marketplace::filterByMileage(int maxMileage) const
{
    bool found = false;
    for (int i = 0; i < totalListings; i++)
    {
        if (listings[i].getVehicle() != nullptr && listings[i].isApproved() &&
            listings[i].getVehicle()->getMileage() <= maxMileage)
        {
            listings[i].displayListing();
            found = true;
        }
    }
    if (!found)
        cout << "No listings found under " << maxMileage << " mileage." << endl;
}

void Marketplace::displayAll() const
{
    cout << "\n=== All Approved Listings ===" << endl;
    for (int i = 0; i < totalListings; i++)
        listings[i].displayListing();
}

void Marketplace::totalSystemListings()
{
    cout << "Total Listings Added to System: " << systemListings << endl;
}

int Marketplace::getTotal() const { return totalListings; }
Listing *Marketplace::getListings() { return listings; }
