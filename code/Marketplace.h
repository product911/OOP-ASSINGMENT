#ifndef MARKETPLACE_H
#define MARKETPLACE_H

#include "Listing.h"
using namespace std;

// Marketplace holds all approved listings and handles search/filter operations
class Marketplace
{
    Listing listings[50];   // ARRAY
    int totalListings;
    static int systemListings;  // STATIC

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

    // Static: shows total ever added
    static void totalSystemListings();

    int getTotal() const;
    Listing *getListings();
};

#endif
