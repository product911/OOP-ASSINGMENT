# PakWheels Car Marketplace — Assignment 02

**Subject:** Object Oriented Programming (CS1004)  
**Instructor:** Talha Shahid  
**University:** FAST-NUCES Karachi | Spring 2026

---

## What This Is

This project is a console-based Car Marketplace system inspired by PakWheels.com.

---

## Repo Structure

```
repo/
├── README.md
├── main.cpp
├── screenshots/
│   ├── Filter_By_Model_Brand.png
│   ├── Filter_By_Price__Year_Mileage.png
│   ├── Seller_Details.png
│   └── Saved-Favourite.png
└── code/
    ├── IListable.h
    ├── ISearchable.h
    ├── IMessagable.h
    ├── IApprovable.h
    ├── User.h / User.cpp
    ├── Seller.h / Seller.cpp
    ├── Buyer.h / Buyer.cpp
    ├── Admin.h / Admin.cpp
    ├── Engine.h / Engine.cpp
    ├── Vehicle.h / Vehicle.cpp
    ├── Car.h / Car.cpp
    ├── Bike.h / Bike.cpp
    ├── Listing.h / Listing.cpp
    ├── Favorite.h / Favorite.cpp
    ├── Message.h / Message.cpp
    └── Marketplace.h / Marketplace.cpp
```

---

## Website Reference — PakWheels.com

The features below were taken from PakWheels and replicated in code.

---

### 1. Search by Make / Model

PakWheels homepage has a search bar where users type a car make or model and optionally select a price range before searching.

![Search by Brand and Model](screenshots/Filter_By_Model_Brand.png)


```cpp
//In Marketplace.cpp
void Marketplace::searchByBrand(string brand) const
{
    for (int i = 0; i < totalListings; i++)
    {
        if (listings[i].getVehicle()->getBrand() == brand && listings[i].isApproved())
            listings[i].displayListing();
    }
}

void Marketplace::searchByModel(string model) const
{
    for (int i = 0; i < totalListings; i++)
    {
        if (listings[i].getVehicle()->getModel() == model && listings[i].isApproved())
            listings[i].displayListing();
    }
}
```

---

### 2. Filter by Price Range, Year and Mileage

On official website of PakWheels, it shows a sidebar with Price Range, Year, and Mileage (KM) filters-

![Filter by Price, Year and Mileage](screenshots/Filter_By_Price__Year_Mileage.png)


```cpp
//In Marketplace.cpp
void Marketplace::filterByPrice(float minPrice, float maxPrice) const
{
    for (int i = 0; i < totalListings; i++)
    {
        if (listings[i].isApproved())
        {
            float p = listings[i].getVehicle()->getPrice();
            if (p >= minPrice && p <= maxPrice)
                listings[i].displayListing();
        }
    }
}

void Marketplace::filterByYear(int minYear) const
{
    for (int i = 0; i < totalListings; i++)
    {
        if (listings[i].isApproved() &&
            listings[i].getVehicle()->getYear() >= minYear)
            listings[i].displayListing();
    }
}

Each one loops through approved listings and only shows results that match.

void Marketplace::filterByMileage(int maxMileage) const
{
    for (int i = 0; i < totalListings; i++)
    {
        if (listings[i].isApproved() &&
            listings[i].getVehicle()->getMileage() <= maxMileage)
            listings[i].displayListing();
    }
}
```


`matchesSearch()` is also overloaded in `Car` for price-based search, implementing function overloading:

```cpp
// In Car.cpp
bool Car::matchesSearch(float minPrice, float maxPrice) const
{
    return (price >= minPrice && price <= maxPrice);
}
```

---

### 3. Send Message to Seller

On any car listing page, PakWheels have a "Send Message" button along with the seller's name and contact details.

![Seller Details and Send Message](screenshots/Seller_Details.png)


```cpp
// Buyer.cpp
void Buyer::sendMessage(string receiver, string text)
{
    Message m(name, receiver, text);
    m.displayMessage();
    logMessage(m);  // friend function logs the message
}

// Seller.cpp
void Seller::sendMessage(string receiver, string text)
{
    Message m(name, receiver, text);
    m.displayMessage();
}
```

`Buyer` and `Seller` implementing the `IMessagable` interface which ensures both to provide `sendMessage()`. The `Message` class makes sender, receiver, and text private. `logMessage()` a friend function that reads those private fields for logging without making them public:

```cpp
//in Message.cpp
void logMessage(const Message &m)
{
    cout << "[LOG] From: " << m.sender << " To: " << m.receiver
         << " | Text: " << m.text << endl;
}
```

The seller's contact info (phone, email) is private in `User`. The friend function `printUserInfo()` accesses it directly — similar PakWheels Website

```cpp
// User.cpp
void printUserInfo(const User &u)
{
    cout << "Name: " << u.name << " | Phone: " << u.phone
         << " | Email: " << u.email << endl;
}
```

---

### 4. Save to Favourites (My Saved Ads)

PakWheels has a "My Saved Ads" section, where listings saved by the buyer appear with a heart icon.

![My Saved Ads](screenshots/Saved-Favourite.png)

```cpp
//In Buyer.cpp
void Buyer::saveFavorite(Vehicle *v)
{
    if (favCount < 10)
        favorites[favCount++].addFavorite(v);
}

void Buyer::viewFavorites() const
{
    for (int i = 0; i < favCount; i++)
        favorites[i].showFavorite();
}
```

```cpp
// Favorite.cpp
void Favorite::showFavorite() const
{
    if (vehicle != nullptr)
        vehicle->displayDetails();  // polymorphism
}
```

** implementation is through a `Favorite` class that stores a pointer to a `Vehicle` (aggregation ). The `Buyer` holds an array of 10 `Favorite` objects. When `viewFavorites()` is called, each calls `displayDetails()` polymorphism as same call can works for both `Car` and `Bike`.

---

## OOP Concepts Summary

### Inheritance (5 Relationships)

| Derived | Base    | Reason |

| Seller  | User    | Seller is a user with a shop and listings |
| Buyer   | User    | Buyer is a user with favorites and a budget |
| Admin   | User    | Admin is a user with approval authority |
| Car     | Vehicle | Car is a vehicle with doors and transmission |
| Bike    | Vehicle | Bike is a vehicle with type and gears |

### Abstraction (4 Abstract Classes)

| Interface   | Pure Virtual                      | Used |

| IListable   | displayDetails()                  | Vehicle → Car, Bike |
| ISearchable | matchesSearch()                   | Vehicle → Car, Bike |
| IMessagable | sendMessage()                     | Buyer, Seller |
| IApprovable | approve(), reject(), isApproved() | Listing |

### Polymorphism

- **Overriding:** `displayDetails()` in Car and Bike behave differently when called through a `Vehicle*` pointer
- **Overloading:** `matchesSearch()` in Car has two versions for overloading — one takes string, one takes a price

### Operator Overloading

| Operator | Class   | Purpose |
| ==       | Vehicle | Checks if two vehicles are the same (brand + model + price) |
| +        | Vehicle | Returns combined mileage of two vehicles |
| ==       | Listing | Checks if two listings point to the same vehicle ID |

### Friend Functions

| Function          | Class   | Reason |
| printUserInfo()   | User    | Access private phone/email for seller contact display |
| logMessage()      | Message | Access private sender/receiver/text for admin logging |
| compareVehicles() | Vehicle | Compare brand/model/year without adding extra getters |
| auditListing()    | Listing | Read approved/rejected state together for admin audit |

### Static Members

- `Admin::approvedCount` — tracks total approvals across all admin objects
- `Admin::rejectedCount` — tracks total rejections system-wide
- `Marketplace::systemListings` — total listings ever added to marketplace
- `Listing::totalCreated` — total listing objects ever created

These are static as the data belongs to the class as a whole, not to any single object.
