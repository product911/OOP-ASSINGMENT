#ifndef ILISTABLE_H
#define ILISTABLE_H

// Abstract class: all listable entities to implement displayDetails() - This hides implementation details and show only display
class IListable
{
public:
    virtual void displayDetails() const = 0; // pure virtual
    virtual ~IListable() {}
};

#endif
