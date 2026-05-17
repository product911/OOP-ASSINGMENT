#include <iostream>
#include "User.h"
#include "Seller.h"
#include "Buyer.h"
#include "Admin.h"
#include "Car.h"
#include "Bike.h"
#include "Listing.h"
#include "Marketplace.h"
using namespace std;

int main()
{
    cout << "==============================" << endl;
    cout << "   PakWheels Marketplace      " << endl;
    cout << "==============================\n" << endl;

    // --- Creating Users via Inheritance ---
    // Seller, Buyer, Admin all inherit from User
    Seller seller(1, "Safi", "Karachi", "03001234567", "safi@gmail.com", "Safi Motors", 4.5);
    Buyer buyer(101, "Khan", "Peshawar", "03219876543", "khan@gmail.com", 800000, "Toyota");
    Admin admin(201, "Admin", "Lahore", "03339920066", "admin@pakwheels.com", "SuperAdmin");

    cout << "--- Seller Info ---" << endl;
    seller.display();       // Overridden display — shows shop info too

    cout << "\n--- Buyer Info ---" << endl;
    buyer.display();        // Overridden display — shows budget info

    cout << "\n--- Admin Info ---" << endl;
    admin.display();        // Overridden display — shows access level

    // Friend function: printUserInfo accesses private User fields directly
    cout << "\n--- Seller Contact (via friend function) ---" << endl;
    printUserInfo(seller);

    // --- Creating Vehicles via Inheritance ---
    // Car and Bike both inherit from Vehicle
    Car car1(101, "Toyota", "Yaris", 2022, 500000, 25000, 4, "Automatic", false);
    Car car2(102, "Honda", "Civic", 2021, 650000, 30000, 4, "Automatic", true);
    Bike bike1(201, "Yamaha", "YBR125", 2023, 150000, 5000, "Standard", false, 5);

    // --- Operator Overloading: == to compare vehicles ---
    cout << "\n--- Operator Overloading Demo ---" << endl;
    if (car1 == car2)
        cout << "car1 and car2 are the same listing." << endl;
    else
        cout << "car1 and car2 are different listings." << endl;

    // Friend function: compareVehicles accesses private Vehicle fields
    cout << "Are car1 and car2 the same model? "
         << (compareVehicles(car1, car2) ? "Yes" : "No") << endl;

    // Operator +: combine mileage of two vehicles
    int combinedMileage = car1 + car2;
    cout << "Combined mileage of car1 + car2: " << combinedMileage << " km" << endl;

    // --- Seller adds listings ---
    cout << "\n--- Adding Listings ---" << endl;
    seller.addListing(&car1);
    seller.addListing(&car2);
    seller.addListing(&bike1);

    // --- Admin approves listings ---
    cout << "\n--- Admin Approving Listings ---" << endl;
    Listing *sellerListings = seller.getListings();
    admin.approveListing(sellerListings[0]);  // approve car1
    admin.approveListing(sellerListings[1]);  // approve car2
    admin.rejectListing(sellerListings[2]);   // reject bike1

    // --- Add to Marketplace ---
    cout << "\n--- Adding to Marketplace ---" << endl;
    Marketplace market;
    market.addListing(sellerListings[0]);
    market.addListing(sellerListings[1]);
    market.addListing(sellerListings[2]); // rejected — won't display

    // --- Search and Filter ---
    cout << "\n--- Search by Brand: Toyota ---" << endl;
    market.searchByBrand("Toyota");

    cout << "\n--- Filter by Price (400000 - 600000) ---" << endl;
    market.filterByPrice(400000, 600000);

    cout << "\n--- Filter by Year (2021+) ---" << endl;
    market.filterByYear(2021);

    cout << "\n--- Filter by Mileage (under 28000 km) ---" << endl;
    market.filterByMileage(28000);

    // --- Polymorphism: displayDetails() on base pointer ---
    cout << "\n--- Polymorphism Demo (Vehicle pointer) ---" << endl;
    Vehicle *vPtr = &car1;
    vPtr->displayDetails();  // calls Car::displayDetails()
    vPtr = &bike1;
    vPtr->displayDetails();  // calls Bike::displayDetails()

    // --- Buyer saves favorites ---
    cout << "\n--- Buyer Favorites ---" << endl;
    buyer.saveFavorite(&car1);
    buyer.saveFavorite(&bike1);
    buyer.viewFavorites();    // polymorphic display in Favorite::showFavorite()

    // --- Buyer sends message to Seller ---
    cout << "\n--- Buyer Sends Message ---" << endl;
    buyer.sendMessage("Safi", "Is the Toyota Yaris still available?");

    // --- Seller replies ---
    cout << "\n--- Seller Replies ---" << endl;
    seller.sendMessage("Khan", "Yes it is! Come visit Safi Motors.");

    // --- Update and Remove Listing ---
    cout << "\n--- Seller Updates Price of car1 ---" << endl;
    seller.updateListing(101, 480000);
    car1.displayDetails();

    cout << "\n--- Seller Removes car2 ---" << endl;
    seller.removeListing(102);
    cout << "Remaining seller listings: " << seller.getCount() << endl;

    // --- Marketplace removal ---
    cout << "\n--- Marketplace Removes car2 Listing ---" << endl;
    market.removeListing(102);

    // --- Admin system audit ---
    cout << "\n--- Admin System Audit ---" << endl;
    admin.auditSystem(market.getListings(), market.getTotal());

    // --- Static member demo ---
    cout << endl;
    Admin::showApproved();
    Admin::showRejected();
    Marketplace::totalSystemListings();
    cout << "Total Listings Ever Created: " << Listing::getTotalCreated() << endl;

    return 0;
}
