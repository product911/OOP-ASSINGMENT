#ifndef ILISTABLE_H
#define ILISTABLE_H

// Abstract class: forces all listable entities to implement displayDetails()
// This hides implementation details and exposes only essential display behavior
class IListable
{
public:
    virtual void displayDetails() const = 0; // pure virtual
    virtual ~IListable() {}
};

#endif
