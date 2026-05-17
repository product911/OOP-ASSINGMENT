#ifndef ISEARCHABLE_H
#define ISEARCHABLE_H

#include <string>
using namespace std;

// Abstract class: any class that supports searching must implement matchesSearch()
// Ensures consistent search behavior across different types (Car, Bike, etc.)
class ISearchable
{
public:
    virtual bool matchesSearch(string keyword) const = 0; // pure virtual
    virtual ~ISearchable() {}
};

#endif
