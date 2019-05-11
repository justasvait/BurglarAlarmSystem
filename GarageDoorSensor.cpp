/* GarageDoorSensor.h
    Garage door sensor class

    A child class of DoorSensor which additionally has remote control functions that open or close garage doors with a signal.
    When garage doors are opened with remote controller, the alarm system is disabled for the garage part, but if the garage
    doors are opened without remote controller (i.e. like simple doors), the alarm is triggered.

   Created by Justas Vaitkevicius on 06/02/2017.
*/

#include "GarageDoorSensor.h"
#include <iostream>
using namespace std;

// constructor: default
GarageDoorSensor::GarageDoorSensor() : DoorSensor()
{
    // parental initialisation
    ID = 0;
    doorOpen = false;

    // start with armed garage, as doors are closed.
    status = true;     // true - garage armed; false - garage disarmed
}
// constructor: with parameters
GarageDoorSensor::GarageDoorSensor( int inputID, bool inputDoorOpen, bool inputStatus ) : DoorSensor( inputID, inputDoorOpen )
{
    // parental initialisation
    ID = inputID;
    doorOpen = inputDoorOpen;

    // garage alarm system status initialisation
    status = inputStatus;
}
// functions
void GarageDoorSensor::openDoor()
{
    DoorSensor::doorOpen = true;    // sets door status to open.
    cout << "Garage doors are open." << endl;   // prints a message to indicate open doors.
}
void GarageDoorSensor::closeDoor()
{
    DoorSensor::doorOpen = false;   // sets door status to close.
    cout << "Garage doors are closed." << endl; // prints message to indicate closed doors.
}

// function which is activated by remote controller. This function disarms
// the alarms system within the garage and opens the doors.
void GarageDoorSensor::receiveOpenSignal()
{
    cout << "Signal received." << endl; // prints a message to indicate the system received the signal.
    status = false;     // disarming garage.
    GarageDoorSensor::openDoor();       // opens garage doors.
}
void GarageDoorSensor::receiveCloseSignal()
{
    cout << "Signal received." << endl; // prints a message to indicate the system received the signal.
    GarageDoorSensor::closeDoor();      // closes garage doors.
    status = true;      // alarms garage.
}

// function which returns garage alarm system status.
bool GarageDoorSensor::getGarageStatus()
{
    return status;
}
