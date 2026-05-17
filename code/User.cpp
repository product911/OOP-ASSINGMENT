#include "User.h"
#include <iostream>

// Default constructor: used when no user details are available yet
User::User()
{
    id = 0000;
    name = "Admin";
    city = "Unknown";
    phone = "0000000000";
    email = "admin@system.com";
}

// Parameterized constructor: full initialization from provided details
User::User(int id, string name, string city, string phone, string email)
{
    this->id = id;
    this->name = name;
    this->city = city;
    this->phone = phone;
    this->email = email;
}

// Copy constructor: needed when User object is passed into derived class constructors
User::User(const User &obj)
{
    id = obj.id;
    name = obj.name;
    city = obj.city;
    phone = obj.phone;
    email = obj.email;
}

void User::display() const
{
    cout << "User: " << name << " | City: " << city << " | Email: " << email << endl;
}

string User::getName() const { return name; }
string User::getCity() const { return city; }
int User::getId() const { return id; }
void User::setPhone(string p) { phone = p; }
void User::setEmail(string e) { email = e; }

// Friend function implementation: prints private user info
// Justified: Listing needs to show seller contact without User exposing all getters
void printUserInfo(const User &u)
{
    cout << "Name: " << u.name << " | Phone: " << u.phone
         << " | Email: " << u.email << endl;
}
