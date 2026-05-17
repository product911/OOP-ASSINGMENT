#include "Admin.h"
#include <iostream>

// Static variable definitions
// Static: these counters are shared across ALL Admin objects in the system
int Admin::approvedCount = 0;
int Admin::rejectedCount = 0;

// Parameterized constructor: passes identity to User, sets access level
// Inheritance justification: Admin IS a User with elevated privileges
Admin::Admin(int id, string name, string city, string phone, string email, string level)
    : User(id, name, city, phone, email)
{
    accessLevel = level;
}

void Admin::approveListing(Listing &l)
{
    l.approve();
    approvedCount++;
    cout << "[Admin: " << name << "] Listing approved." << endl;
    auditListing(l); // friend function — directly reads private listing state
}

void Admin::rejectListing(Listing &l)
{
    l.reject();
    rejectedCount++;
    cout << "[Admin: " << name << "] Listing rejected." << endl;
    auditListing(l);
}

void Admin::auditSystem(Listing *listings, int count) const
{
    cout << "\n=== System Audit by " << name << " ===" << endl;
    for (int i = 0; i < count; i++)
        auditListing(listings[i]);
}

void Admin::display() const
{
    User::display();
    cout << "Access Level: " << accessLevel << endl;
}

// Static function: shows total approvals — no instance needed to check system stats
void Admin::showApproved()
{
    cout << "Total Approved Listings: " << approvedCount << endl;
}

void Admin::showRejected()
{
    cout << "Total Rejected Listings: " << rejectedCount << endl;
}

string Admin::getAccessLevel() const { return accessLevel; }
