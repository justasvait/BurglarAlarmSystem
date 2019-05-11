//
//  Authenticate.cpp
//  Burgular Alarm authentication class
//
//  Created by Joseph Cresswell on 05/02/2017.
//  Copyright © 2017 Joseph Cresswell. All rights reserved.
//

#include "Authenticate.h"       //Including the authenticate header
#include <iostream>             //Including relevent libraries

using namespace std;

Authenticate::Authenticate()    //Authenticate constructor
{
    trials=0;                   //Initially set the trials to 0 and pin to 9999
    pin="9999";
}

bool Authenticate::changePin()  //Method to change the current pin
{
    int wrong=0;                //Declaring variables to be used
    int check=0;
    string x="0", xcheck="0";

    while(check!=1)                        //If check dosen't = 1
    {
        x="0";
        while(x.size()<4||x.size()>16)    //Make sure only a pin of 4 - 16 charectors is entered
        {
            cout<<"Please enter a new pin of 4-16 digits"<<endl;        //Get user to enter a new pin
            cin>>x;
        }
        cout<<"Please re-enter this new pin"<<endl;     //Get user to re-enter this new pin
        cin>>xcheck;
        if(xcheck==x)                                   //If both equal change the pin to user entered one
        {
            check=1;
            pin=x;
            cout<<endl<<"Pin successfully changed"<<endl<<endl;
        }
        else cout<<"Pins don't match, please try again"<<endl<<endl;        //If don't match get user to try again
    }

    return true;                       //Return true if pin successfilly changed
}

bool Authenticate::checkPin(string user)        //Method used to check user enters the correct pin
{
    if(user!=pin)                               //If entered pin not correct return 0 and add 1 to number of trials
    {
        trials++;
        return 0;
    }
    else                                        //If entered pin correct, reset number of trials and return 1
    {
        trials=0;
        return 1;
    }
}

int Authenticate::getTrials()                   //method to get the number of trials- number of times user got the pin wrong
{
    return trials;
}

void Authenticate::resetTrials()                //Mwthod to reset the number of trials back to 0
{
    trials=0;
}
