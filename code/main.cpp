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
    cout << "===PakWheels Marketplace===" << endl;

   //Creating Users, Seller, Buyer, Admin ( Inheritance )
    Seller seller(1, "Safi", "Karachi", "03001234567", "safi@gmail.com", "Safi Motors", 4.5);
    Buyer buyer(101, "Khan", "Peshawar", "03219876543", "khan@gmail.com", 800000, "Toyota");
    Admin admin(201, "Admin", "Lahore", "03339920066", "admin@pakwheels.com", "SuperAdmin");

    cout << "===Seller Information===" << endl;
    seller.display();    //Overridding shows shop info 

    cout << "===Buyer Information===" << endl;
    buyer.display();     //Overridding shows budget info

    cout << "===Admin Information===" << endl;
    admin.display();      // Overridding shows access level

    //Friend function (printUserInfo) accesses private User directly
    cout << "===Seller Contact===" << endl;
    printUserInfo(seller);

    //Inheritance perform Car and Bike both inherit from Vehicle
    Car car1(101, "Toyota", "Yaris", 2022, 500000, 25000, 4, "Automatic", false);
    Car car2(102, "Honda", "Civic", 2021, 650000, 30000, 4, "Automatic", true);
    Bike bike1(201, "Yamaha", "YBR125", 2023, 150000, 5000, "Standard", false, 5);

    //Operator Overloading (==) to compare vehicles
    cout << "===Vehicle Comparsion===" << endl;
    if (car1 == car2)
        cout << "Car 1 and Car 2 are the same listing." << endl;
    else
        cout << "Car 1 and Car 2 are different listings." << endl;

    //Friend function (compareVehicles) called for accessing private Vehicle
    cout << "Are Car 1 and Car 2 the same model? "<< (compareVehicles(car1, car2) ? "Yes" : "No") << endl;

    // Operator Pverloading (+) combine mileag
    int combinedMileage = car1 + car2;
    cout << "Combined mileage of Car 1 + Car 2: " << combinedMileage << " km" << endl;

    //Seller Adds 
    cout << "===Add Listings===" << endl;
    seller.addListing(&car1);
    seller.addListing(&car2);
    seller.addListing(&bike1);

    //Admin approval listings
    cout << "===Admin Approving Listings===" << endl;
    Listing *sellerListings = seller.getListings();
    admin.approveListing(sellerListings[0]);  // approve 
    admin.approveListing(sellerListings[1]);  // approve
    admin.rejectListing(sellerListings[2]);   //rejected

    //Adding to Marketplace
    cout << "===Adding to Marketplace===" << endl;
    Marketplace market;
    market.addListing(sellerListings[0]);
    market.addListing(sellerListings[1]);
    market.addListing(sellerListings[2]); // will not be displayed as rejected

    //Searching/Filtering===
    cout << "===Search by Brand===" << endl;
    market.searchByBrand("Toyota");

    cout << "===Filter by Price (300000 - 600000)===" << endl;
    market.filterByPrice(300000, 600000);

    cout << "===Filter by Year===" << endl;
    market.filterByYear(2020);

    cout << "===Filter by Mileage (under 25000 km)===" << endl;
    market.filterByMileage(25000);

    //Polymorphism phenomenon using base pointer
    cout << "===Polymorphism" << endl;
    Vehicle *vchlptr = &car1;
    vchlptr->displayDetails();  // calling Car->displayDetails()
    vchlptr = &bike1;
    vchlptr->displayDetails();  // calling Bike->displayDetails()

    //Buyer Saved/Favourite
    cout << "===Buyer Favorites===" << endl;
    buyer.saveFavorite(&car1);
    buyer.saveFavorite(&bike1);
    buyer.viewFavorites();    // polymorphism

    //Buyer message
    cout << "===Buyer Message===" << endl;
    buyer.sendMessage("Hi Safi", "Is the Toyota Yaris still available in best condition?");

    //Seller reply
    cout << "===Seller Reply===" << endl;
    seller.sendMessage("Hi Khan", "Yes it is still available, You can visit Safi Motors");

    //Updating Listing===
    cout << "===Updating Price of Car===" << endl;
    seller.updateListing(101, 450000);
    car1.displayDetails();

    cout << "===Removing Car===" << endl;
    seller.removeListing(102);
    cout << "Remaining Seller listings: " << seller.getCount() << endl;

    //Marketplace removal
    cout << "===Marketplace Removes Car Listing===" << endl;
    market.removeListing(102);

    //Admin system
    cout << "===Admin System Audit===" << endl;
    admin.auditSystem(market.getListings(), market.getTotal());

    //Static member implementation
    cout << endl;
    Admin::showApproved();
    Admin::showRejected();
    Marketplace::totalSystemListings();
    cout << "Total Listings Created: " << Listing::getTotalCreated() << endl;
    return 0;
}
