#ifndef MESSAGE_H
#define MESSAGE_H
using namespace std;

class Message
{
    string text;
    string sender;
    string receiver;

public:
    // Parameterized constructor
    Message(string s = "", string r = "", string t = "");

    void displayMessage() const;
    string getSender() const;
    string getReceiver() const;

    // Friend function: allows Buyer to directly inspect message internals
    friend void logMessage(const Message &m);
};

#endif
