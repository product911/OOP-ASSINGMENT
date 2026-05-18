#include "Message.h"
#include <iostream>

Message::Message(string s, string r, string t)
{
    sender = s;
    receiver = r;
    text = t;
}

void Message::displayMessage() const
{
    cout << sender << " -> " << receiver << " : " << text << endl;
}

string Message::getSender() const { return sender; }
string Message::getReceiver() const { return receiver; }

// Friend function: prints full message info including private fields
// needed for admin-level logging without making all fields public
void logMessage(const Message &m)
{
    cout << "[LOG] From: " << m.sender << " To: " << m.receiver
         << " | Text: " << m.text << endl;
}
