/**
Name: Control Panel Class
      (C++ assignment)

Author: Khaled Saad

Description: This class is used to simulate the control panel of the burglar alarm system.
             It contains all the central information of the system, such as status and time.
**/

#include "controlPanel.h"
#include <string>

void controlPanel::activate()   //Changes the status of the system to active.
{
    systemStatus = true;
}

void controlPanel::deactivate() //Changes the status of the system to inactive.
{
    systemStatus = false;
}

bool controlPanel::changeTime(string t) //Changes the system time
{
    string h, m;        //Temporary strings to hold hours and minutes
    h = t.substr(0,2);  //Extract hours sub-string
    m = t.substr(3,5);  //Extract minutes sub-string

    if(t.length()!=5)   //Checks to ensure the entered string is 5 characters long "hh:mm"
        return false;   //Time has NOT been changed

    if(t[2]!=':')       //Checks to ensure the colon is present
        return false;   //Time has NOT been changed

    if(h >= "00" && h < "25" && m >= "00" && m < "60")    //Checks to ensure entered time is within range
    {
        time = t;       //Changes time
        return true;    //Time has been changed
    }
    else
        return false;   //Time has NOT been changed
}

bool controlPanel::getSystemStatus()    //Returns the status of the system
{
    return systemStatus;
}
string controlPanel::getTime()          //Returns the time
{
    return time;
}
