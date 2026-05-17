#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
using namespace std;

class Message
{
    string text;
    string sender;
    string receiver;

public:
    // Parameterized constructor: a message always needs sender, receiver, text
    Message(string s = "", string r = "", string t = "");

    void displayMessage() const;
    string getSender() const;
    string getReceiver() const;

    // Friend function: allows Buyer to directly inspect message internals
    // for logging or audit purposes without exposing private fields as getters
    friend void logMessage(const Message &m);
};

#endif
