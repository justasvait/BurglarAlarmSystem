/* VibrationSensor.h
   Vibration sensor class

   Vibration sensor is a child class of WindowSensor which additionally receives signal from a sensor that can trigger the
   alarm system (only when activated).

   Created by Justas Vaitkevicius on 06/02/2017.
*/

#include "VibrationSensor.h"

// constructor: default
VibrationSensor::VibrationSensor() : WindowSensor()
{
    // initialisation of parental class
    ID = 0;
    windowOpen = false;
}
// constructor: with parameters
VibrationSensor::VibrationSensor( int inputID, bool inputWinOpen ) : WindowSensor( inputID, inputWinOpen )
{
    // initialisation of parental class
    ID = inputID;
    windowOpen = inputWinOpen;
}
// Functions

// this function receives signal from a sensor. If sensor is activated it triggers alarms system
// (NOTE: it won't activate if system is OFFLINE).
void VibrationSensor::detect(bool sensorReading)
{
    if ( sensorReading == true)
        WindowSensor::triggerAlarm();
}
