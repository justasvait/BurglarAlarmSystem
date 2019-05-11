/* WindowSensor.h
   Window sensor class header which includes its unique ID and status paramteres.
   It has functions to trigger alarm system, set a new ID and get its status.

   Created by Justas Vaitkevicius on 06/02/2017.
*/

#ifndef WINDOWSENSOR_H_INCLUDED
#define WINDOWSENSOR_H_INCLUDED

class WindowSensor
{
protected:
    int ID;     // unique ID
    bool windowOpen;    // windows status (true - window is open; false - closed).
public:
    // constructors
    WindowSensor();
    WindowSensor( int, bool );
    // functions
    void triggerAlarm();    // function to trigger alarm.
    void setID( int );  // function to set a new ID.
    int getID();        // function to get sensor unique ID.
    bool getStatus();   // function which returns status.
};


#endif // WINDOWSENSOR_H_INCLUDED
