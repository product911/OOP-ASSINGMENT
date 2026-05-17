#include "Listing.h"
#include <iostream>

// Static variable definition — tracks all listing objects ever created
int Listing::totalCreated = 0;

// Default constructor
Listing::Listing()
{
    listingCode = ++totalCreated;
    vehicle1 = nullptr;
    seller1 = nullptr;
    approved = false;
    rejected = false;
}

// Parameterized constructor: listing is created with vehicle and seller attached
Listing::Listing(Vehicle *v, Seller *s)
{
    listingCode = ++totalCreated;
    vehicle1 = v;
    seller1 = s;
    approved = false;
    rejected = false;
}

void Listing::setListing(Vehicle *v, Seller *s)
{
    vehicle1 = v;
    seller1 = s;
}

void Listing::approve()
{
    approved = true;
    rejected = false;
}

void Listing::reject()
{
    approved = false;
    rejected = true;
}

bool Listing::isApproved() const { return approved; }
bool Listing::isRejected() const { return rejected; }

void Listing::displayListing() const
{
    if (approved && vehicle1 != nullptr)
    {
        cout << "[Listing #" << listingCode << "] ";
        vehicle1->displayDetails();  // Polymorphic call — works for Car and Bike
    }
    else
    {
        cout << "[Listing #" << listingCode << "] Not approved yet." << endl;
    }
}

Vehicle *Listing::getVehicle() const { return vehicle1; }
Seller *Listing::getSeller() const { return seller1; }
int Listing::getListingCode() const { return listingCode; }

int Listing::getTotalCreated()
{
    // Static function: reports total listings ever created, not just active ones
    // Justified as static: this data belongs to the class, not any one instance
    return totalCreated;
}

// == operator: compare listings by vehicle ID to detect duplicates
bool Listing::operator==(const Listing &other) const
{
    if (vehicle1 == nullptr || other.vehicle1 == nullptr)
        return false;
    return vehicle1->getId() == other.vehicle1->getId();
}

// Friend function: gives Admin full read access to private listing state
// Justified: Admin audit requires seeing rejected/approved status + vehicle details
void auditListing(const Listing &l)
{
    cout << "[AUDIT] Listing #" << l.listingCode
         << " | Approved: " << (l.approved ? "Yes" : "No")
         << " | Rejected: " << (l.rejected ? "Yes" : "No") << endl;
}
