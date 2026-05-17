#ifndef MARKETPLACE_H
#define MARKETPLACE_H

#include "Listing.h"
#include <string>
using namespace std;

// Marketplace holds all approved listings and handles search/filter operations
class Marketplace
{
    Listing listings[50];   // ARRAY OF OBJECTS: up to 50 listings
    int totalListings;
    static int systemListings;  // STATIC: tracks total added system-wide

public:
    Marketplace();

    void addListing(Listing l);
    void removeListing(int vehicleId);

    // Search and filter functions
    void searchByBrand(string brand) const;
    void searchByModel(string model) const;
    void filterByPrice(float minPrice, float maxPrice) const;
    void filterByYear(int minYear) const;
    void filterByMileage(int maxMileage) const;

    void displayAll() const;

    // Static: shows total ever added, independent of current state
    static void totalSystemListings();

    int getTotal() const;
    Listing *getListings();
};

#endif
