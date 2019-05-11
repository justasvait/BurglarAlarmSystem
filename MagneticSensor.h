/* MagneticSensor.h
   Magnetic sensor class header which includes detect function.

   Created by Justas Vaitkevicius on 06/02/2017.
*/

#ifndef MAGNETICSENSOR_H_INCLUDED
#define MAGNETICSENSOR_H_INCLUDED

#include "WindowSensor.h"

class MagneticSensor : public WindowSensor
{
public:
    // constructors
    MagneticSensor();
    MagneticSensor( int, bool );
    // functions:
    void detect(bool);  // function to detect triggered sensor.
};


#endif // MAGNETICSENSOR_H_INCLUDED
