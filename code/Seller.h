#ifndef SELLER_H
#define SELLER_H

#include "User.h"
#include "Listing.h"
#include "IMessagable.h"

// Seller inherits User — gets id, name, city, phone, email from base
// Also implements IMessagable since sellers can reply to buyers
class Seller : public User, public IMessagable
{
    Listing listings[10];   // ARRAY OF OBJECTS: holds up to 10 listings
    int listingCount;
    float rating;           // seller rating out of 5
    string shopName;

public:
    // Default constructor: used when seller details aren't available yet
    Seller();

    // Parameterized constructor: pass User base details + seller-specific info
    Seller(int id, string name, string city, string phone, string email,
           string shopName = "My Shop", float rating = 0.0);

    void addListing(Vehicle *v);
    void removeListing(int vehicleId);
    void updateListing(int vehicleId, float newPrice);

    Listing *getListings();
    int getCount() const;

    // Overrides User::display() to include seller-specific info
    void display() const override;

    // Implements IMessagable pure virtual
    void sendMessage(string receiver, string text) override;

    float getRating() const;
    string getShopName() const;
};

#endif
