/* DoorSensor.cpp
   Door sensor class child from WindowSensor class.

   Door sensor has an ID by which the specific door can be identified, as well as its state: open or closed, and alarm trigger
   function which displays a message.

   Created by Justas Vaitkevicius on 06/02/2017.
*/

#include "DoorSensor.h"
#include <iostream>
using namespace std;

// constructor: default
DoorSensor::DoorSensor()
{
    // by default ID is set to 0 (in other words, unspecified) and door status to "closed doors".
    ID = 0;
    doorOpen = false;
}
// constructor: with parameters
DoorSensor::DoorSensor( int inputID, bool inputDoorOpen )
{
    ID = inputID;
    doorOpen = inputDoorOpen;
}
// functions

// function to detect forced door entry.
void DoorSensor::detectOpen()
{
    doorOpen = true;
    triggerAlarm();
}

// function to detect when doors are closed.
void DoorSensor::detectClose()
{
    doorOpen = false;
}
void DoorSensor::triggerAlarm()
{
    // call alert system
    cout << "Door sensor has been triggered\n" << endl;
}

// function to set a new unique ID.
void DoorSensor::setID(int inputID)
{
    ID = inputID;
}

// function to get sensors unique ID.
int DoorSensor::getID()
{
    return ID;
}

// function to get door status.
bool DoorSensor::getStatus()
{
    return doorOpen;
}
