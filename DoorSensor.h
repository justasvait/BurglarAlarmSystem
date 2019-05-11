/* DoorSensor.h
   Door sensor class header which has its unique ID parameter and
   boolean doorOpen parameter which indicates if doors are open or closed.

   This class has functions to detect if the doors are open or closed
   (this is based on sensor information which is not available in this program).

   This class also includes functions to trigger alarm system, setting a new ID and
   getting status of the sensor.

   Created by Justas Vaitkevicius on 06/02/2017.
*/

#ifndef DOORSENSOR_H_INCLUDED
#define DOORSENSOR_H_INCLUDED

class DoorSensor
{
protected:
    int ID; // unique ID variable.
    bool doorOpen;  // variable to store status of doors (true - open doors; false - closed doors)
public:
    // constructors
    DoorSensor();
    DoorSensor( int, bool );

    // functions:
    void detectOpen();  // function which detects open doors.
    void detectClose(); // function which detects closed doors.
    void triggerAlarm();    // function to trigger alarm system.
    void setID(int);    // function to set a unique ID.
    int getID();        // funtion to get sensors unique ID.
    bool getStatus();   // function to get status of the door.
};

#endif // DOORSENSOR_H_INCLUDED
