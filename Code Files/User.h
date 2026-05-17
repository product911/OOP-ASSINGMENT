#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

// Base class for all user types (Buyer, Seller, Admin)
// Holds shared identity data so derived classes don't repeat it
class User
{
protected:
    int id;
    string name;
    string city;
    string phone;
    string email;

public:
    // Default constructor: creates a generic admin placeholder
    User();

    // Parameterized constructor: full user setup
    User(int id, string name, string city, string phone, string email);

    // Copy constructor: used when passing User by value into derived classes
    User(const User &obj);

    virtual void display() const;   // virtual so derived classes can override
    string getName() const;
    string getCity() const;
    int getId() const;
    void setPhone(string p);
    void setEmail(string e);

    // Friend function: allows Listing to read private user data for display
    // without exposing a full getter for every field
    friend void printUserInfo(const User &u);

    virtual ~User() {}
};

#endif
