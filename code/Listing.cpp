#include "Listing.h"
#include <iostream>

// Static variable
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

// Parameterized constructor
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
    // FIX: Increment totalCreated for new listings
    listingCode = ++totalCreated;
    vehicle1 = v;
    seller1 = s;
    approved = false;
    rejected = false;
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
        vehicle1->displayDetails();  // Polymorphism call
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
    // Static function - give total listings 
    return totalCreated;
}

//== operator - compare listings by vehicle ID
bool Listing::operator==(const Listing &other) const
{
    // FIX: Compare by listing code instead of vehicle ID to avoid false duplicates
    return this->listingCode == other.listingCode;
}

// Friend function: gives Admin full read access to private listing - Admin audit requires rejected/approved status & vehicle details
void auditListing(const Listing &l)
{
    cout << "[AUDIT] Listing #" << l.listingCode
         << " | Approved: " << (l.approved ? "Yes" : "No")
         << " | Rejected: " << (l.rejected ? "Yes" : "No") << endl;
}