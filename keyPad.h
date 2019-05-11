/**
Name: Key Pad Header file
      (C++ assignment)

Author: Khaled Saad

Description: This is the header file for the key pad class, which is used to simulate the key pad
             for the burglar alarm system. It takes in and returns input from the user.
**/

#ifndef KEYPAD_H_INCLUDED
#define KEYPAD_H_INCLUDED

#include <string>

using namespace std;

class keyPad
{
    private:
        string num;     //stores the input
        long int start; //Stores start time of method check pin called
        bool timedout;

    public:
        keyPad();
        string timedInput(int);    //Takes in input from the user and returns it within 30 sec
        string inputNum();      //Takes in input from the user and returns it
        string getNum();        //Returns most recent input
        bool gettimedout();
        void reset();        //Resets input
};

#endif // KEYPAD_H
