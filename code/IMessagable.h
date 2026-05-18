#ifndef IMESSAGABLE_H
#define IMESSAGABLE_H

#include <string>
using namespace std;

// Abstract class: any user type that can communicate must implement sendMessage() - This abstracts messaging behavior so Buyer and Seller can both support it
class IMessagable
{
public:
    virtual void sendMessage(string receiver, string text) = 0; // pure virtual
    virtual ~IMessagable() {}
};

#endif
