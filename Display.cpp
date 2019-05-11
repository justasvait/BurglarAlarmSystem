//Body for the Display class
//Author: Daulet Alzhanov

//The class was designed to build the interface for the user to interact with.
#include "Display.h"        //Name of the header file
#include "iomanip"          //Used for setw and fill functions in presenting data
#include <iostream>         //Used for cin and cout
#include <string>           //Used for string manupilations
#include <stdlib.h>         //Used for coding purposes
#include <sstream>          //String conversion

using namespace std;        //Used as a shortcut

////////////////////////////////////////////////////////////////////
//Constructors
Display::Display()
{
    message = "";                       //Latest data presented to the user
    time = "";                          //Time to displayed on the interface
}

Display::Display(string newMessage, string newTime, bool newStatus)
{
    message = newMessage;
    time = newTime;
}

////////////////////////////////////////////////////////////////////
//Used to Display messages on the screen
void Display::displayMessage(string newMessage)
{
    cout << newMessage << endl;         //newMessage is the string that is sent to the user
}

////////////////////////////////////////////////////////////////////
//Used to update the screen by wiping the previous activity, show time and status
void Display::updateInterface(string t, bool status)
{
    system("Cls");                                              //Clearing the screen for housekeeping
    cout << left << "Time: " << setw(50) << setfill(' ') << t;  //Inputting the time
    //As the status will be Boolean, true will indicate active and false will indicate inactive
    if(status)                                                  //When status is active
        cout << "Status: Active" << endl;                       //Returning Active Status 
    else                                                        //When status is Inactive
        cout << "Status: Inactive" << endl;                     //Returning Inactive Status
    cout << "===========================================================================" << endl;
}//Used to seperate the inface from the rest of the code.

////////////////////////////////////////////////////////////////////
//Converting integer to string
string Display::intToString(int x)
{
    ostringstream convert;                                      //conversion declerations
    convert << x;                                               //the variable being converted
    return  convert.str();                                      //returning the string
}

///////////////////////////////////////////////////////////////////
//Used to display various interfaces and options
void Display::face(int option)
{
    if (option==0) //Show menu
    {//Used to navigate through the menu
        cout << "Please select one of the options from the menu." << endl << "Menu:" << endl;
        cout << "1. Logs" << endl << "2. System Activation" << endl << "3. Settings" << endl << endl;
    }
    else if(option==1) //Logs
    {//Used to display the logs headings
        cout << "Logs" << endl << "-----" << endl;
        cout << left << setw(10) << setfill(' ') << "Time";
        cout << setw(20) << "Recent Activity" << endl;
    }
    else if(option==2) //Activate
    {//Unused
        //nothing to see here
    }
    else if(option==3) //Settings menu
    {//The interface for the menu
        cout << "Please select the following options from the Settings" << endl;
        cout << "4. Change Pin" << endl << "5. Adjust Time" << endl << "6. Contact Info" << endl << "7. Return to main menu" << endl << endl;
    }
    else if(option==4)//Changing the pin
    {
        //nothing to see here
    }
    else if(option==5)//Selecting the new time
    {
        cout << "Please enter new time in this format: 'hh:mm' ";
    }
    else if(option==6)//Changing the contact number
    {
//        cout << "Please enter the contact number through keypad: ";
        cout << "Please enter 1 to check current phone number," << endl;
        cout << "             2 to change phone number," << endl;
        cout << "             3 to exit: " << endl;

    }
}
