#ifndef IAPPROVABLE_H
#define IAPPROVABLE_H

// Abstract class: anything that can be approved/rejected in the marketplace
// Admin works with IApprovable so it doesn't depend on specific listing types
class IApprovable
{
public:
    virtual void approve() = 0;   // pure virtual
    virtual void reject() = 0;    // pure virtual
    virtual bool isApproved() const = 0; // pure virtual
    virtual ~IApprovable() {}
};

#endif
