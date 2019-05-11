/* VibrationSensor.h
   Vibration sensor class header which includes detect function.

   Created by Justas Vaitkevicius on 06/02/2017.
*/

#ifndef VIBRATIONSENSOR_H_INCLUDED
#define VIBRATIONSENSOR_H_INCLUDED

#include "WindowSensor.h"

class VibrationSensor : public WindowSensor
{
public:
    // constructors
    VibrationSensor();
    VibrationSensor( int, bool );
    // functions
    void detect(bool); // function to detect triggered sensor.
};


#endif // VIBRATIONSENSOR_H_INCLUDED
