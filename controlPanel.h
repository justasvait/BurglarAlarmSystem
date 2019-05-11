/**
Name: Control Panel Header file
      (C++ assignment)

Author: Khaled Saad

Description: This header file contains information about the control panel class, which is
             used to simulate the control panel of the burglar alarm system. It contains
             all the central information of the system, such as status and time.
**/

#ifndef CONTROLPANEL_H_INCLUDED
#define CONTROLPANEL_H_INCLUDED

#include<iostream>

using namespace std;

class controlPanel
{
    private:
        bool systemStatus = false; //The status of the system
        string time = "12:00";     //Time, initially set as 12:00

    public:
        void activate();           //Activate the system
        void deactivate();         //Deactivate the system
        bool changeTime(string);   //Change the time
        bool getSystemStatus();    //Return the system status
        string getTime();          //Return the time
};

#endif // CONTROLPANEL_H_INCLUDED
