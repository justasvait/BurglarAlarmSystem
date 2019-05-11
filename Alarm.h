/* Alarm.h
   The alarm class header which is responsible for activation
   and deactivation of the whole alarm system.

   Created by Justas Vaitkevicius on 06/02/2017.
*/

#ifndef ALARM_H_INCLUDED
#define ALARM_H_INCLUDED

class Alarm
{
private:
    bool status;    // alarm status ( true - alarm is active; false - alarm is inactive).
public:
    // constructor: default
    Alarm();
    // constructor: with parameters
    Alarm( bool );
    // functions:
    void activateAlarm();   // function to change status to active.
    void deactivateAlarm(); // function to change status to inactive.
    bool getStatus();       // function to get status (boolean) value.
};

#endif // ALARM_H_INCLUDED
