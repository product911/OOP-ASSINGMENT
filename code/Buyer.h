#ifndef BUYER_H
#define BUYER_H

#include "User.h"
#include "Favorite.h"
#include "IMessagable.h"
using namespace std;

// Buyer inherits User - Implements IMessagable (buyers send messages to sellers)
class Buyer : public User, public IMessagable
{
    Favorite favorites[10]; // ARRAY OF OBJECTS
    int favCount;
    float budget;
    string preferredBrand;

public:
    // Parameterized constructor
    Buyer(int id, string name, string city, string phone, string email,
          float budget = 0, string brand = "Any");

    void saveFavorite(Vehicle *v);
    void removeFavorite(int vehicleId);
    void viewFavorites() const;

    // Implements IMessagable pure virtual
    void sendMessage(string receiver, string text) override;

    // Overrides User::display()
    void display() const override;

    float getBudget() const;
    string getPreferredBrand() const;
};

#endif
