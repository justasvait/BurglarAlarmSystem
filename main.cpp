/**
Name: Burglar Alarm System
      (C++ assignment)

Author: Khaled Saad

Description: This program simulates a burglar alarm system in  house. It defines
             different sensors, along with all the interactions between the sub-systems.
             Please view the documentation for more details.

NOTE: The format of the "ID" is a 3 digit number:

      1st digit is the floor (we have 2 floors)

      2nd digit is the type
      (1 --> doors, 2 --> windows vibration sensor, 3 --> windows magnetic sensor, 4 --> garage door)

      3rd digit is the number of the thing
**/

//===========================================Libraries========================================
#include <string>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include <iostream>

//===========================================Header files=====================================
#include "WindowSensor.h"
#include "VibrationSensor.h"
#include "MagneticSensor.h"
#include "DoorSensor.h"
#include "GarageDoorSensor.h"
#include "Alarm.h"
#include "Communication.h"
#include "Authenticate.h"
#include "Display.h"
#include "DataLog.h"
#include "keyPad.h"
#include "controlPanel.h"

using namespace std;

/*
The format of the"ID" is a 3 digit number
1st digit is the floor (we have 2 floors)
2nd digit is the type (1 --> doors, 2 --> windows vibration sensor, 3 --> windows magnetic sensor, 4 --> garage door)
3rd digit is the number of the thing
*/


//================================================================================================================

int main()
{
    //=======================Initialising Objects=================
    VibrationSensor VibWinSen[2]; //Vibration Window Sensors
    VibWinSen[0].setID(121);
    VibWinSen[1].setID(222);

    MagneticSensor MagWinSen[2];  //Magnetic Window Sensors
    MagWinSen[0].setID(131);
    MagWinSen[1].setID(232);

    DoorSensor DoorSen[2];        //Door sensors
    DoorSen[0].setID(111);
    DoorSen[1].setID(112);

    GarageDoorSensor GarDoorSen;  //Garage door sensor
    GarDoorSen.setID(141);

    Alarm alarm1;                 //Alarm System

    Communication comm;           //Communication System

    Authenticate auth;            //Authentication System

    Display screen;               //Touch screen

    controlPanel cPanel;          //Control Panel

    keyPad numPad;                //Key Pad

    DataLog Log;                  //Logs
    //==============================================================

    int input = 0;  //This variable is used to simulate touch-screen input

    //=====================MAIN INFINTE LOOP=========================
    //This is an infinite loop to keep the program running until it is closed by the user
    while(true)
    {
// ======================================================================================
// TIME FUNCTION
        SYSTEMTIME time;
        GetSystemTime(&time);
        int time_h = time.wHour;
        int time_m = time.wMinute;

        string currentTime = "";
        if (time_h<10)
            currentTime = string("0"+screen.intToString(time_h));
        else
            currentTime = screen.intToString(time_h);
        if (time_m<10)
            currentTime += string(":0"+screen.intToString(time_m));
        else
            currentTime += string(":"+screen.intToString(time_m));
        if (currentTime.length()==5)
            cPanel.changeTime(currentTime);
// ======================================================================================
        //If the system is armed
        if(cPanel.getSystemStatus() == true)
        {
            screen.displayMessage("The System is Activated.\n");
            screen.displayMessage("Enter the ID of a sensor to activate it.\n");
            screen.displayMessage("***Available sensors: 121, 222, 131, 232, 111, 112, 141.\n");
            screen.displayMessage("Enter 1 to to simulate \"OPEN\" button on remote controller.");
            screen.displayMessage("Enter 2 to to simulate \"CLOSE\" button on remote controller.");
            screen.displayMessage("Or enter '0' to access keypad.\n");

            cin >> input;

            //Check input through sensors/touch screen

            if(input == 0)  //Enter pin
            {
                while(true) //Infinite loop
                {
                    //This simulates touching the screen to input the pin to disarm the system
                    screen.updateInterface(cPanel.getTime(), cPanel.getSystemStatus());
                    while(auth.getTrials() < 3)        //3 trials to enter the pin
                    {
                        screen.displayMessage("Please enter the pin: ");
                        if(auth.checkPin(numPad.inputNum())) //Correct pin
                            break;  //break out of the loop
                        screen.displayMessage("Wrong pin. Number of trials left: " + screen.intToString(3 - auth.getTrials()));
                    }

                    //After exiting the while(trials < 3) loop
                    if(auth.checkPin(numPad.getNum()))     //If correct pin is entered...
                    {
                        Log.updateLog("System deactivated", cPanel.getTime());
                        alarm1.deactivateAlarm();       //Deactivate the alarm
                        cPanel.deactivate();            //If correct pin is entered, deactivate the system
                        auth.resetTrials();              //Reset number of attempts
                        Sleep(2000);                     //Pause for 2 seconds to see message
                        break;                          //Exit infinite loop
                    }

                    else                                //If incorrect pin is entered...
                    {
                        if(!alarm1.getStatus())     //Run this if alarm is NOT activated
                        {
                            alarm1.activateAlarm();         //Activate Alarm
                            comm.notifyNumber();            //Notify the owner
                            comm.notifyPolice();            //Notify the police
                        }

                        cout << "Incorrect pin. System is locked for 3 minutes" << endl;
                        Sleep(180000);                  //3 minute delay
                        auth.resetTrials();             //Reset trials
                    }
                }   //End of infinite loop
            }   //End of if condition


            else if(input == 121 || input == 222 || input == 131 || input == 232 || input == 111 || (input == 141 && GarDoorSen.getGarageStatus())) //Sensors
            {
                { // new block for temporary newString storage.
                    // generates message with respect to sensor ID
                    string newString = "Sensor ID=";
                    if (input == 121) newString += screen.intToString(VibWinSen[0].getID());
                    if (input == 222) newString += screen.intToString(VibWinSen[1].getID());
                    if (input == 131) newString += screen.intToString(MagWinSen[0].getID());
                    if (input == 232) newString += screen.intToString(VibWinSen[1].getID());
                    if (input == 111) newString += screen.intToString(DoorSen[0].getID());
                    if (input == 141) newString += screen.intToString(GarDoorSen.getID());

                    newString += " is triggered. Alarm activated";
                    // updates logs
                    Log.updateLog(newString, cPanel.getTime());
                } // end of the block
                alarm1.activateAlarm();                     //Activate Alarm
                comm.notifyNumber();                        //Notify the owner
                comm.notifyPolice();                        //Notify the police
                while(true)
                {
                    while(auth.getTrials() < 3)        //3 trials to enter the pin
                    {
                        screen.displayMessage("Please enter the pin to deactivate the alarm: ");
                        if(auth.checkPin(numPad.inputNum())) //Correct pin
                            break;
                        screen.displayMessage("Wrong pin. Number of trials left: " + screen.intToString(3 - auth.getTrials()));
                    }

                    //After exiting the while(trials < 3) loop
                    if(auth.checkPin(numPad.getNum()))         //If correct pin is entered...
                    {
                        Log.updateLog("System deactivated", cPanel.getTime());
                        alarm1.deactivateAlarm();       //Deactivate the alarm
                        cPanel.deactivate();            //If correct pin is entered, deactivate the system
                        auth.resetTrials();              //Reset number of attempts
                        break;                          //Exit infinite loop
                    }

                    else                                //If incorrect pin is entered...
                    {
                        cout << "Incorrect pin. System is locked for 3 minutes" << endl;
                        Sleep(180000);                  //3 minute delay
                        auth.resetTrials();             //Reset trials
                    }
                }   //End of infinite loop
            }   //End of if condition


           else if(input == 112)    //Main Door
           {
               //30 seconds delay here
               Log.updateLog("Main door opened", cPanel.getTime());
               while(true) //Infinite loop
                {
                    //This simulates touching the screen to input the pin to disarm the system
                    while(auth.getTrials() < 3)        //3 trials to enter the pin
                    {
                        if(auth.checkPin(numPad.timedInput(auth.getTrials()))) //Correct pin
                        {
                            break;  //break out of the loop
                        }
                        if(numPad.gettimedout()==1)     //If the 30 seconds has ended break out of the loop
                        {
                            break;
                        }
                    }
                    //After exiting the while(trials < 3) loop
                    screen.updateInterface(cPanel.getTime(), cPanel.getSystemStatus());
                    if(auth.checkPin(numPad.getNum()))     //If correct pin is entered...
                    {
                        Log.updateLog("System deactivated", cPanel.getTime());
                        alarm1.deactivateAlarm();       //Deactivate the alarm
                        cPanel.deactivate();            //If correct pin is entered, deactivate the system
                        auth.resetTrials();              //Reset number of attempts
                        numPad.reset();                 //reset keypad attributes
                        Sleep(2000);                     //Pause for 2 seconds to see message
                        break;                          //Exit infinite loop
                    }

                    else                                //If incorrect pin is entered...
                    {
                        if(!alarm1.getStatus())     //Run this if alarm is NOT activated
                        {
                            alarm1.activateAlarm();         //Activate Alarm
                            comm.notifyNumber();            //Notify the owner
                            comm.notifyPolice();            //Notify the police
                        }
                        cout << "Incorrect pin. System is locked for 3 minutes" << endl;
                        Sleep(180000);                  //3 minute delay
                        auth.resetTrials();             //Reset trials
                        numPad.reset();                 //reset keypad attributes

                    }
                }   //End of infinite loop
          }    //End of if condition

          // Open garage door
          else if (input == 141 && !GarDoorSen.getGarageStatus()) // garage doors are triggered, but garage system is inactive.
          {
              screen.displayMessage("Garage alarm system is deactivated.");
              system("pause");
              screen.updateInterface(cPanel.getTime(), cPanel.getSystemStatus()); // clears screen to have another option
          }
          else if (input == 1)  // Remote controller "OPEN" button is pressed.
          {
                GarDoorSen.receiveOpenSignal(); // Automatically turn off the alarm system and opens garage doors.
                system("pause");    // pause to see messages.
                screen.updateInterface(cPanel.getTime(), cPanel.getSystemStatus()); // clears screen to have another option
                // updates log file
                Log.updateLog("Remote controller signal received", cPanel.getTime());
                Log.updateLog("Garage alarm system deactivated", cPanel.getTime());
                Log.updateLog("Garage doors are open", cPanel.getTime());
          }
          else if (input == 2)  // Remote controller "CLOSE" button is pressed.
          {
                GarDoorSen.receiveCloseSignal(); // Automatically closes the garage doors and turns on alarm system.
                system("pause");    // pause to see messages.
                screen.updateInterface(cPanel.getTime(), cPanel.getSystemStatus()); // clears screen to have another option
                // updates log file
                Log.updateLog("Remote controller signal received", cPanel.getTime());
                Log.updateLog("Garage alarm system activated", cPanel.getTime());
                Log.updateLog("Garage doors are closed", cPanel.getTime());
          }

          else
            {
                screen.displayMessage("Invalid input.");
                system("pause");
                screen.updateInterface(cPanel.getTime(), cPanel.getSystemStatus()); // clears the screen
            }

        }   //END OF CONDITION FOR SYSTEM BEING ARMED

        else
        {
            //SYSTEM IS DE-ACTIVATED


            screen.updateInterface(cPanel.getTime(), cPanel.getSystemStatus());  //Reset interface after every iteration
            screen.face(0);                       //Display main menu

            cin >> input;                               //Take input from touch-screen
            screen.updateInterface(cPanel.getTime(), cPanel.getSystemStatus());  //Reset interface
            if(input > 0 && input <3)                   //Check if input is within menu range
                screen.face(input);               //Display the interface of the chosen option

            switch(input)   //Main Menu switch
            {

            case 1:
                //Logs
                screen.displayMessage(Log.getLog());   //Get logs as a string and display them
                system("pause");                        //"Press any key to continue..."
                break;

            case 2:
                //Activate the system
                cPanel.activate();                      //Activate the system
                screen.updateInterface(cPanel.getTime(), cPanel.getSystemStatus()); //Run again to show new status
                break;


            case 3:
                //Settings menu
                screen.displayMessage("Please enter pin to access settings");
                if(!auth.checkPin(numPad.inputNum()))   //Check for pin before accessing the settings menu
                {
                    screen.displayMessage("Wrong pin.");
                    break;
                }
                auth.resetTrials();      //Reset number of attempts
                screen.updateInterface(cPanel.getTime(), cPanel.getSystemStatus());  //Reset interface
                screen.face(3);     //Display menu interface
                cin >> input;                               //Take input from touch-screen
                screen.updateInterface(cPanel.getTime(), cPanel.getSystemStatus());  //Reset interface
                if(input == 7)                              //Return to main menu
                    continue;
                if(input > 3 && input <7)                   //Check if input is within menu range
                    screen.face(input);               //Display the interface of the chosen option

                switch (input)  //Settings Menu switch
                {
                case 4:
                    //Change pin
                    while(auth.getTrials()<3)   //3 trials to enter pin
                    {
                        screen.displayMessage("Please enter current pin:");
                        if(auth.checkPin(numPad.inputNum()))    //Enter current pin to be able to change the pin
                        {
                            screen.updateInterface(cPanel.getTime(), cPanel.getSystemStatus());
                            auth.changePin();   //Change the pin
                            Log.updateLog("Password has been changed", cPanel.getTime());
                            break;
                        }
                        else
                            screen.displayMessage("Wrong pin. Number of trials left: " + screen.intToString(3 - auth.getTrials()));
                    }
                    auth.resetTrials();      //Reset number of attempts
                    break;

                case 5:
                    //Change time
                    {
                        string previousTime = cPanel.getTime();
                    if(!cPanel.changeTime(numPad.inputNum()))    //Take input through keypad and check for invalid format
                    {
                        screen.displayMessage("Invalid format/time");
                        Sleep(3000); //Pause for a second to allow the user to read the message
                    }
                    else
                        Log.updateLog(string("Time has been changed from " + previousTime + " to " + cPanel.getTime()),cPanel.getTime());
                    }
                    break;

                case 6:
                    //Contact number
                    {
                        /*additional options*/
                        char choice = ' ';
                        do
                        {
                            cin >> choice;
                            if (choice == '1' || choice == '2' || choice == '3')
                                break;  // correct input, continues with a program.
                            else
                                screen.displayMessage("Invalid choice! Please enter 1,2 or 3.");
                                // incorrect input, asks for additional input.
                        }
                        while (true);

                        switch (choice)
                        {
                        case '1':
                            // show current number
                            screen.displayMessage(string("Current number is: " + comm.getPhoneNumber()));
                            system("pause");
                            break;
                        case '2':
                            // change number
                            {
                                // temporary variable for previous phone number storage
                                string previousPhoneNo = comm.getPhoneNumber();
                                screen.displayMessage("Please enter new phone number:");
                                comm.changeNumber(numPad.inputNum());      //Take input through keypad
                                // updates log file
                                Log.updateLog(string("Contact phone number is changed from \"" + previousPhoneNo + "\" to \"" + comm.getPhoneNumber() + "\""),cPanel.getTime());
                            }
                            break;
                        case '3':
                            // return to main menu
                            break;
                        default:
                            // invalid input
                            screen.displayMessage("invalid input");
                        }
                    }
                    break;

                default:
                    //invalid input
                    screen.displayMessage("invalid input");
                }
                break;

            default:
                //Invalid input
                screen.displayMessage("invalid input");
            }
        }
    }
    return 0;
}
