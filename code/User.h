#ifndef USER_H
#define USER_H

using namespace std;

// Base class for all
class User
{
protected:
    int id;
    string name;
    string city;
    string phone;
    string email;

public:
    // Default constructor
    User();

    // Parameterized constructor
    User(int id, string name, string city, string phone, string email);

    // Copy constructor: used when passing User by value into derived classes
    User(const User &obj);

    virtual void display() const;   // virtual as derived classes can override
    string getName() const;
    string getCity() const;
    int getId() const;
    void setPhone(string p);
    void setEmail(string e);

    // Friend function: allows Listing to read private user data for display
    friend void printUserInfo(const User &u);

    virtual ~User() {}
};

#endif
