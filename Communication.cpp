/* Communication.cpp
   Communication class

   Holds a contact number, which can be changed. This class also has function to
   contact the owner and the police. Since this program is a simulation, the actual message sending function
   is replaced with a print message.

   Created by Justas Vaitkevicius on 06/02/2017.
*/

#include "Communication.h"
#include <iostream>
#include <string>
using namespace std;

// constructor: default
Communication::Communication()
{
    // by default the phone number is undefined and thus, does not notify anybody in case of burglary.
    phoneNumber = "undefined";
}
// constructor: with parameters
Communication::Communication( string inputPhoneNumber )
{
    // by initialising this number, the system will be able to send SMS to this number in case of burglary.
    phoneNumber = inputPhoneNumber;
}
// functions:

// this function is printing out messages to a screen.
// In real life, this function would be used to send SMS to the specified number.
void Communication::notifyNumber()
{
    cout << "Sending message to the owner..." << endl;
    // pretend it sent SMS
    cout << "Pretending it sends SMS..." << endl;
    // END of pretending...
    cout << "The owner is notified." << endl;
}

// this function is printing out messages to a screen.
// In real life, this function would send SMS message to the police.
void Communication::notifyPolice()
{
    cout << "Sending message to the police..." << endl;
    // pretend it sent SMS
    cout << "Pretending it sends SMS..." << endl;
    // END of pretending...
    cout << "The police is notified." << endl;
}

// this function is used to change a phone number.
void Communication::changeNumber( string inputPhoneNumber )
{
    phoneNumber = inputPhoneNumber;
}

// function which returns current phone number.
string Communication::getPhoneNumber()
{
    return phoneNumber;
}
