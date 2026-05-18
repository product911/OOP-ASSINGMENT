#include "Buyer.h"
#include "Message.h"
#include <iostream>

// Parameterized constructor - Buyer IS a User shares all info
Buyer::Buyer(int id, string name, string city, string phone, string email,
             float budget, string brand)
    : User(id, name, city, phone, email)
{
    favCount = 0;
    this->budget = budget;
    preferredBrand = brand;
}

void Buyer::saveFavorite(Vehicle *v)
{
    if (favCount < 10)
    {
        favorites[favCount++].addFavorite(v);
        cout << "Vehicle saved to favorites." << endl;
    }
    else
    {
        cout << "Favorites list is full." << endl;
    }
}

void Buyer::removeFavorite(int vehicleId)
{
    for (int i = 0; i < favCount; i++)
    {
        if (favorites[i].getVehicle() != nullptr &&
            favorites[i].getVehicle()->getId() == vehicleId)
        {
            for (int j = i; j < favCount - 1; j++)
                favorites[j] = favorites[j + 1];
            favCount--;
            cout << "Removed from favorites." << endl;
            return;
        }
    }
    cout << "Vehicle not in favorites." << endl;
}

void Buyer::viewFavorites() const
{
    if (favCount == 0)
    {
        cout << "No favorites saved." << endl;
        return;
    }
    for (int i = 0; i < favCount; i++)
        favorites[i].showFavorite();
}

// Implements IMessagable (buyer sends message to seller)
void Buyer::sendMessage(string receiver, string text)
{
    Message m(name, receiver, text);
    m.displayMessage();
    logMessage(m); // Friend function call
}

// Overrides User::display()
void Buyer::display() const
{
    User::display();
    cout << "Budget: " << budget << " | Preferred Brand: " << preferredBrand << endl;
}

float Buyer::getBudget() const { return budget; }
string Buyer::getPreferredBrand() const { return preferredBrand; }
