#ifndef LISTING_H
#define LISTING_H

#include "Vehicle.h"
#include "IApprovable.h"
#include <string>
using namespace std;

// Forward declaration to avoid circular dependency
class Seller;

// Listing implements IApprovable — admin can approve or reject it
// Composition with Vehicle (vehicle lives with listing)
// Aggregation with Seller (seller exists independently)
class Listing : public IApprovable
{
    Vehicle *vehicle1;  // AGGREGATION: Vehicle is passed in, not owned
    Seller *seller1;    // AGGREGATION: Seller exists outside Listing
    bool approved;
    bool rejected;
    int listingCode;        // Set once at creation — treated as read-only by convention
    static int totalCreated; // STATIC: shared count across all Listing objects

public:
    // Default constructor: creates empty listing slot
    Listing();

    // Parameterized constructor: sets vehicle and seller immediately
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

    // Static function: total listings created system-wide
    static int getTotalCreated();

    // Operator ==: two listings are equal if they point to the same vehicle ID
    // Justified: prevents duplicate listings in Marketplace
    bool operator==(const Listing &other) const;

    // Friend: Admin needs raw access to listing internals for audit
    // Justified: avoids exposing rejected state through public getters unnecessarily
    friend void auditListing(const Listing &l);
};

#endif
