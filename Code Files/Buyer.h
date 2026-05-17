#ifndef BUYER_H
#define BUYER_H

#include "User.h"
#include "Favorite.h"
#include "IMessagable.h"
#include <string>
using namespace std;

// Buyer inherits User — gets identity from base class
// Implements IMessagable since buyers send messages to sellers
class Buyer : public User, public IMessagable
{
    Favorite favorites[10]; // ARRAY OF OBJECTS: stores saved vehicles
    int favCount;
    float budget;
    string preferredBrand;

public:
    // Parameterized constructor: buyer must have identity and budget info
    Buyer(int id, string name, string city, string phone, string email,
          float budget = 0, string brand = "Any");

    void saveFavorite(Vehicle *v);
    void removeFavorite(int vehicleId);
    void viewFavorites() const;

    // Implements IMessagable pure virtual
    void sendMessage(string receiver, string text) override;

    // Overrides User::display() to add buyer-specific info
    void display() const override;

    float getBudget() const;
    string getPreferredBrand() const;
};

#endif
