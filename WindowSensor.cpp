/* WindowSensor.cpp
   Window sensor class

   Window sensor class has an ID for identification as well as state for open and closed window. The class can also
   trigger the alarm.

   Created by Justas Vaitkevicius on 06/02/2017.
*/

#include "WindowSensor.h"
#include <iostream>
using namespace std;

// constructor: default
WindowSensor::WindowSensor()
{
    // by default ID is set to 0 (unspecified) and window status to "closed window".
    ID = 0;
    windowOpen = false;
}
// constructor: with parameters
WindowSensor::WindowSensor( int inputID, bool inputWinOpen )
{
    ID = inputID;
    windowOpen = inputWinOpen;
}
// functions
void WindowSensor::triggerAlarm()
{
    windowOpen = true;

    // call alert system
    cout << "Window sensor \"" << ID << "\" has been triggered\n" << endl;
}

// function to set a new unique ID.
void WindowSensor::setID(int inputID)
{
    ID = inputID;
}

// function to get sensor unique ID.
int WindowSensor::getID()
{
    return ID;
}

// function to get window status.
bool WindowSensor::getStatus()
{
    return windowOpen;
}
