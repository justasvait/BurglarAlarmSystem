//
//  Authenticate.h
//  Burgular Alarm pin authentication header which includes change pin and check pin
//  as well as get trials and reset trials
//
//  Created by Joseph Cresswell on 05/02/2017.
//  Copyright © 2017 Joseph Cresswell. All rights reserved.
//



#include <iostream> //Including relevent libraries
#include <string>

using namespace std;

class Authenticate
{
private:        //Attributes that can only be accessed by this class
    string pin; //the pin saved as a string and number of trials as integer
    int trials;
public:         //Public methods as they need to be accessed by main
    Authenticate();     //Class constructor
    bool changePin();    //Method to change the pin
    bool checkPin(string);   //Method to check user entered pin is correct
    int getTrials();        //method to return number of trials
    void resetTrials();
};
