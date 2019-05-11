/* GarageDoorSensor.h
    GarageDoorSensor is a child class for DoorSensor.

    It includes functions such as openDoor and closeDoor to change door status.

    Functions receiveSignal & returnSignal is used as an input from remote controller
    which turns on/off the alarm system within the garage and then opens or closes the doors.

   Created by Justas Vaitkevicius on 06/02/2017.
*/

#ifndef GARAGEDOORSENSOR_H_INCLUDED
#define GARAGEDOORSENSOR_H_INCLUDED

#include "DoorSensor.h"

class GarageDoorSensor : public DoorSensor
{
private:
    bool status;    // this is a status of garage alarm system which is separate from main alarm system.
public:
    // constructors
    GarageDoorSensor();
    GarageDoorSensor( int, bool, bool );
    //functions:
    void openDoor();    // function to open the doors.
    void closeDoor();   // function to close the doors.
    void receiveOpenSignal();   // function which receives the "open" button signal from remote controller.
    void receiveCloseSignal();    // function which receives the "close" button signal from remote controller.
    bool getGarageStatus(); // function to return garage alarm system status.

};


#endif // GARAGEDOORSENSOR_H_INCLUDED
