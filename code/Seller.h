#ifndef SELLER_H
#define SELLER_H

#include "User.h"
#include "Listing.h"
#include "IMessagable.h"

// Seller inherits User
//implements IMessagable (sellers can reply to buyers)
class Seller : public User, public IMessagable
{
    Listing listings[10];   // ARRAY
    int listingCount;
    float rating;           // seller rating
    string shopName;

public:
    // Default constructor
    Seller();

    // Parameterized constructor
    Seller(int id, string name, string city, string phone, string email,
           string shopName = "My Shop", float rating = 0.0);

    void addListing(Vehicle *v);
    void removeListing(int vehicleId);
    void updateListing(int vehicleId, float newPrice);

    Listing *getListings();
    int getCount() const;

    // Overrides User::display()
    void display() const override;

    // Implements IMessagable pure virtual
    void sendMessage(string receiver, string text) override;

    float getRating() const;
    string getShopName() const;
};

#endif
