#include "Seller.h"
#include "Message.h"
#include <iostream>

// Default constructor
Seller::Seller() : User()
{
    listingCount = 0;
    rating = 0.0;
    shopName = "My Shop";
}

// Parameterized  constructor
//Seller IS a User
Seller::Seller(int id, string name, string city, string phone, string email,
               string sName, float r)
    : User(id, name, city, phone, email)
{
    listingCount = 0;
    shopName = sName;
    rating = r;
}

void Seller::addListing(Vehicle *v)
{
    if (listingCount < 10)
    {
        listings[listingCount].setListing(v, this);
        listingCount++;
        cout << "Listing added by " << name << endl;
    }
    else
    {
        cout << "Listing limit reached for " << name << endl;
    }
}

void Seller::removeListing(int vehicleId)
{
    for (int i = 0; i < listingCount; i++)
    {
        if (listings[i].getVehicle() != nullptr &&
            listings[i].getVehicle()->getId() == vehicleId)
        {
            // Shift remaining listings down
            for (int j = i; j < listingCount - 1; j++)
                listings[j] = listings[j + 1];
            listingCount--;
            cout << "Listing removed." << endl;
            return;
        }
    }
    cout << "Vehicle not found in listings." << endl;
}

void Seller::updateListing(int vehicleId, float newPrice)
{
    for (int i = 0; i < listingCount; i++)
    {
        if (listings[i].getVehicle() != nullptr &&
            listings[i].getVehicle()->getId() == vehicleId)
        {
            listings[i].getVehicle()->setPrice(newPrice);
            cout << "Price updated to " << newPrice << endl;
            return;
        }
    }
    cout << "Vehicle not found." << endl;
}

Listing *Seller::getListings() { return listings; }
int Seller::getCount() const { return listingCount; }
float Seller::getRating() const { return rating; }
string Seller::getShopName() const { return shopName; }

// Overrides User::display()
void Seller::display() const
{
    User::display();
    cout << "Shop: " << shopName << " | Rating: " << rating << "/5" << endl;
}

// Implements IMessagable::sendMessage (seller can reply to buyers)
void Seller::sendMessage(string receiver, string text)
{
    Message m(name, receiver, text);
    m.displayMessage();
}
