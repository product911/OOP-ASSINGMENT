# PakWheels Car Marketplace — Assignment 02
**Subject:** Object Oriented Programming (CS1004)  
**Instructor:** Talha Shahid  
**University:** FAST-NUCES Karachi | Spring 2026

---

## Overview

This project extends Assignment 01 by applying advanced OOP concepts to the PakWheels-inspired Car Marketplace System. The system allows sellers to list vehicles, buyers to search and save favorites, and admins to approve or reject listings — all built using proper OOP design.

**Concepts applied in A2:**
- Inheritance
- Polymorphism (overloading + overriding)
- Abstraction (pure virtual / abstract classes)
- Operator Overloading
- Friend Functions

---

## Directory Structure

```
A2/
├── IListable.h          # Abstract interface: display behavior
├── ISearchable.h        # Abstract interface: search behavior
├── IMessagable.h        # Abstract interface: messaging behavior
├── IApprovable.h        # Abstract interface: approval behavior
├── User.h / .cpp        # Base class for all users
├── Seller.h / .cpp      # Inherits User, implements IMessagable
├── Buyer.h / .cpp       # Inherits User, implements IMessagable
├── Admin.h / .cpp       # Inherits User, manages approvals
├── Engine.h / .cpp      # Composition inside Vehicle
├── Vehicle.h / .cpp     # Abstract base for Car and Bike
├── Car.h / .cpp         # Inherits Vehicle, concrete class
├── Bike.h / .cpp        # Inherits Vehicle, concrete class
├── Listing.h / .cpp     # Implements IApprovable
├── Favorite.h / .cpp    # Aggregation with Vehicle
├── Message.h / .cpp     # Messaging with friend function
├── Marketplace.h / .cpp # Holds and filters all listings
└── main.cpp             # Full demo of all features
```

---

## How to Compile and Run

```bash
g++ -std=c++17 -o marketplace main.cpp User.cpp Message.cpp Engine.cpp Vehicle.cpp Car.cpp Bike.cpp Listing.cpp Seller.cpp Buyer.cpp Admin.cpp Marketplace.cpp Favorite.cpp

./marketplace
```

---

## 1. Inheritance (5–6 Relationships)

Inheritance allows derived classes to reuse and extend base class behavior. Here `User` is the base for all user types, and `Vehicle` is the base for vehicle types.

**Hierarchy:**

```
User
├── Seller    (IS-A User with shop and listings)
├── Buyer     (IS-A User with favorites and budget)
└── Admin     (IS-A User with approval authority)

Vehicle  (abstract)
├── Car       (IS-A Vehicle with doors, transmission)
└── Bike      (IS-A Vehicle with bikeType, gears)
```

**Code Snippet — User as base:**
```cpp
class Seller : public User, public IMessagable
{
    // Seller-specific: shopName, rating, listings[]
    Seller(int id, string name, string city, string phone, string email,
           string shopName, float rating)
        : User(id, name, city, phone, email)  // passes to base constructor
    { ... }
};
```

**Justification:** Seller, Buyer, and Admin all share identity fields (id, name, city, phone, email). Putting these in `User` and inheriting removes duplication. Each derived class only adds what is unique to its role.

---

## 2. Polymorphism

### Function Overriding (Runtime Polymorphism)

`displayDetails()` is a pure virtual function in `Vehicle`. Car and Bike both override it differently.

**Code Snippet:**
```cpp
// In main — same base pointer, different output
Vehicle *vPtr = &car1;
vPtr->displayDetails();  // calls Car::displayDetails()

vPtr = &bike1;
vPtr->displayDetails();  // calls Bike::displayDetails()
```

**Output:**
```
-- CAR LISTING --
ID: 101 | Toyota Yaris | Year: 2022 ...
Doors: 4 | Transmission: Automatic | Sunroof: No

-- BIKE LISTING --
ID: 201 | Yamaha YBR125 | Year: 2023 ...
Type: Standard | Fairing: No | Gears: 5
```

### Function Overloading (Compile-time Polymorphism)

`matchesSearch()` in `Car` is overloaded — one version takes a keyword string, another takes a price range.

```cpp
bool matchesSearch(string keyword) const;         // search by name
bool matchesSearch(float minPrice, float maxPrice) const; // search by price range
```

---

## 3. Abstraction (4 Abstract Classes)

Abstract classes define interfaces that hide implementation and force derived classes to provide specific behavior.

### IListable
```cpp
class IListable {
public:
    virtual void displayDetails() const = 0;
};
```
**Why:** Forces every vehicle type to implement its own display logic. Marketplace and Listing call `displayDetails()` without caring whether it is a Car or Bike.

### ISearchable
```cpp
class ISearchable {
public:
    virtual bool matchesSearch(string keyword) const = 0;
};
```
**Why:** Marketplace search works uniformly on any vehicle type.

### IMessagable
```cpp
class IMessagable {
public:
    virtual void sendMessage(string receiver, string text) = 0;
};
```
**Why:** Both Buyer and Seller can send messages. The interface ensures both implement it consistently.

### IApprovable
```cpp
class IApprovable {
public:
    virtual void approve() = 0;
    virtual void reject() = 0;
    virtual bool isApproved() const = 0;
};
```
**Why:** Admin works with `IApprovable` so it is not tightly coupled to the `Listing` class specifically.

---

## 4. Operator Overloading

### `==` on Vehicle — Duplicate Detection
```cpp
bool Vehicle::operator==(const Vehicle &other) const
{
    return (price == other.price && brand == other.brand && model == other.model);
}
```
**Justification:** Marketplace uses this to detect duplicate listings before adding them. Makes comparison logic readable: `if (listings[i] == newListing)`.

### `+` on Vehicle — Combined Mileage
```cpp
int Vehicle::operator+(const Vehicle &other) const
{
    return this->mileage + other.mileage;
}
```
**Justification:** Useful for fleet total reporting. Allows `int total = car1 + car2` which is intuitive.

### `==` on Listing — Duplicate Listing Check
```cpp
bool Listing::operator==(const Listing &other) const
{
    return vehicle1->getId() == other.vehicle1->getId();
}
```
**Justification:** Prevents the same vehicle from being listed twice in the Marketplace.

---

## 5. Friend Functions

Friend functions access private members without making them fully public. Used here for audit and cross-class inspection purposes.

### `printUserInfo(const User &u)` — in User
```cpp
friend void printUserInfo(const User &u);
```
**Justification:** Listing needs to display seller contact (phone, email) without `User` exposing those as public getters. Friend gives controlled access.

### `logMessage(const Message &m)` — in Message
```cpp
friend void logMessage(const Message &m);
```
**Justification:** Admin logging needs to see message content (sender, receiver, text) internally without breaking encapsulation of the Message class.

### `compareVehicles(const Vehicle &v1, const Vehicle &v2)` — in Vehicle
```cpp
friend bool compareVehicles(const Vehicle &v1, const Vehicle &v2);
```
**Justification:** Compares brand, model, and year across two vehicles using private fields directly. Needed by Marketplace deduplication logic.

### `auditListing(const Listing &l)` — in Listing
```cpp
friend void auditListing(const Listing &l);
```
**Justification:** Admin audit requires reading both `approved` and `rejected` private state together in one call. Adding two separate getters just for audit purposes would unnecessarily widen the public interface.

---

## 6. Key OOP Features from Assignment 01 (Retained)

| Feature | Where Used |
|---|---|
| Composition | Engine inside Vehicle; User inside Seller/Buyer/Admin via inheritance |
| Aggregation | Vehicle pointer in Listing; Seller pointer in Listing; Vehicle pointer in Favorite |
| Static Members | `Admin::approvedCount`, `Admin::rejectedCount`, `Marketplace::systemListings`, `Listing::totalCreated` |
| Array of Objects | `Listing listings[10]` in Seller; `Favorite favorites[10]` in Buyer; `Listing listings[50]` in Marketplace |
| Constructors | Default, parameterized, and copy constructors used across User, Engine, Vehicle, Message |

---

## Website Reference — PakWheels

The system is modeled after [PakWheels.com](https://www.pakwheels.com), Pakistan's largest car marketplace.

**Features replicated:**

| PakWheels Feature | Implementation |
|---|---|
| Browse by brand/model | `searchByBrand()`, `searchByModel()` in Marketplace |
| Filter by price | `filterByPrice(min, max)` in Marketplace |
| Filter by year | `filterByYear()` in Marketplace |
| Filter by mileage | `filterByMileage()` in Marketplace |
| Save to favorites | `saveFavorite()` in Buyer |
| Message seller | `sendMessage()` in Buyer and Seller |
| Admin listing approval | `approveListing()` / `rejectListing()` in Admin |
| Seller profile | `shopName`, `rating` in Seller |

---

## Sample Output (Excerpt)

```
--- Polymorphism Demo (Vehicle pointer) ---
-- CAR LISTING --
ID: 101 | Toyota Yaris | Year: 2022 | Price: 500000 | Mileage: 25000
Doors: 4 | Transmission: Automatic | Sunroof: No

-- BIKE LISTING --
ID: 201 | Yamaha YBR125 | Year: 2023 | Price: 150000 | Mileage: 5000
Type: Standard | Fairing: No | Gears: 5

--- Buyer Sends Message ---
Khan -> Safi : Is the Toyota Yaris still available?
[LOG] From: Khan To: Safi | Text: Is the Toyota Yaris still available?

Total Approved Listings: 2
Total Rejected Listings: 1
Total Listings Added to System: 3
```
