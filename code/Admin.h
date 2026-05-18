#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Listing.h"
using namespace std;

// Admin inherits User and Admin manages listing approvals and operations
class Admin : public User
{
    static int approvedCount;   // STATIC: shared across all Admin instances
    static int rejectedCount;   // STATIC: system-wide rejection counter
    string accessLevel;         // e.g., "SuperAdmin", "Moderator"

public:
    // Parameterized constructor
    Admin(int id, string name, string city, string phone, string email,
          string level = "Moderator");

    void approveListing(Listing &l);
    void rejectListing(Listing &l);
    void auditSystem(Listing *listings, int count) const;

    // Overrides User::display() 
    void display() const override;

    // Static functions- show data
    static void showApproved();
    static void showRejected();
    string getAccessLevel() const;
};

#endif
