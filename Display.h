//Header file for the Display Class
#ifndef DISPLAY_H_INCLUDED 
#define DISPLAY_H_INCLUDED

#include<iostream>  //Used for general programming

using namespace std; //Used for shortcuts

class Display //Name of the Class
{
    private://Atributes
        string message; //The latest message
        string time;    //Time on the interface
        bool status;    //Displaying whether active or not
    public:
        Display();      //Constructor
        Display(string, string, bool);//Constructor
        void displayMessage(string); //Displaying the message on the screen
        void updateInterface(string); //Adding more data to the screen
        void face(int); //Interface
        string intToString(int); //interger to string conversion
};

#endif // DISPLAY_H_INCLUDED
