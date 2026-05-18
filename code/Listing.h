#ifndef LISTING_H
#define LISTING_H

#include "Vehicle.h"
#include "IApprovable.h"
using namespace std;

// Forward declaration to avoid circular dependency
class Seller;

// Listing implements IApprovable - Admin can approve or reject it
class Listing : public IApprovable
{
    Vehicle *vehicle1;  // AGGREGATION
    Seller *seller1;    // AGGREGATION
    bool approved;
    bool rejected;
    int listingCode;        // Set once
    static int totalCreated; // STATIC
public:
    // Default constructor
    Listing();

    // Parameterized constructor
    Listing(Vehicle *v, Seller *s);

    void setListing(Vehicle *v, Seller *s);

    // Implements IApprovable pure virtuals
    void approve() override;
    void reject() override;
    bool isApproved() const override;

    bool isRejected() const;

    void displayListing() const;
    Vehicle *getVehicle() const;
    Seller *getSeller() const;
    int getListingCode() const;

    // Static function
    static int getTotalCreated();

    // Operator ==: two listings are equal if they point to the same vehicle ID
    // prevents duplicate listings in Marketplace
    bool operator==(const Listing &other) const;

    // Friend function - Admin needs raw access to listing internals for audit
    // avoids exposing rejected state through public getters unnecessarily
    friend void auditListing(const Listing &l);
};

#endif
