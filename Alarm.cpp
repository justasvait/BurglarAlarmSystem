/* Alarm.cpp
   Alarm system class

   Alarm has a state and can be activated or deactivated.
   As this is simulation, activation and deactivation just changes state and prints a message.

   Created by Justas Vaitkevicius on 06/02/2017.
*/
#include "Alarm.h"
#include <iostream>
using namespace std;

// constructor: default
Alarm::Alarm()
{
    // by default, the alarm is inactive. That means no sirens are on, no alerts, etc...
    status = false;
}
// constructor: with parameters
Alarm::Alarm( bool inputStatus )
{
    status = inputStatus;
}
// functions
void Alarm::activateAlarm()
{
    status = true;  //activates alarm system.

    // Prints out activation message.
    // In real life situation this part would be for turning on sirens, alert flash lights, etc...
    cout << "Alarm is activated.\n" << endl;
}
void Alarm::deactivateAlarm()
{
    status = false; // deactivates the alarm system.

    // Prints out deactivation message.
    cout << "Alarm is deactivated.\n" << endl;
}
bool Alarm::getStatus()
{
    return status;  // returns a boolean value of status.
}
