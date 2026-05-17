#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Listing.h"
#include <string>
using namespace std;

// Admin inherits User — identity managed by base class
// Admin manages listing approvals and system-level operations
class Admin : public User
{
    static int approvedCount;   // STATIC: shared across all Admin instances
    static int rejectedCount;   // STATIC: system-wide rejection counter
    string accessLevel;         // e.g., "SuperAdmin", "Moderator"

public:
    // Parameterized constructor: admin must have identity and access level
    Admin(int id, string name, string city, string phone, string email,
          string level = "Moderator");

    void approveListing(Listing &l);
    void rejectListing(Listing &l);
    void auditSystem(Listing *listings, int count) const;

    // Overrides User::display() to include access level
    void display() const override;

    // Static functions: report system-wide data — justified as static because
    // this info belongs to the system, not any single admin
    static void showApproved();
    static void showRejected();

    string getAccessLevel() const;
};

#endif
