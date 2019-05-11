/**
Name: Key Pad Class
      (C++ assignment)

Author: Khaled Saad & Joseph Cresswell

Description: This class is used to simulate the key pad for the burglar alarm system.
             It takes in and returns input from the user.
**/

#include "keyPad.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>

using namespace std;

keyPad::keyPad()        //Constructor for keyPad to set attributes to a initial value
{
    start=0;
    num="";
    timedout=0;
}
string keyPad::inputNum()   //Takes in input from the user and returns it
{
    cin >> num;
    return num;
}

string keyPad::getNum()    //Returns most recent input
{
    return num;
}

void keyPad::reset()    //Resets input variables to be able to use timed input again
{
    num.clear();
    start=0;
    timedout=0;
}

bool keyPad::gettimedout()  //Get the value of timedout
{
    return timedout;
}

string keyPad::timedInput(int trials) //Timed input for cases where the user should only be allowed a limited time to
{                                     //enter the pin
    int secrun = 0;
    cin.clear();
    num.clear();
    time_t now;
    if(start==0)
    {
     start=time(&now);
    }
    while((time(&now)-start)<30) //while time currently is not 30s more than the time the function was called
    {
        system("cls");            //Clear terminal screen
        if(secrun == 1)           //If past the first run
        {
        if(trials>0)              //If trials is larger than 0 print the number of trials the user has left
            {
            cout<<"Wrong pin. Number of trials left: "<< 3 - trials<<endl;
            }
          cout << "Please enter the pin: "<<endl;    //Prompt user to enter the pin
        }


        if(GetAsyncKeyState('1') != 0)            //If the '1' key has been pressed add one to the end of the pin string
        {
            num+="1";
        }
        if(GetAsyncKeyState('2') != 0)       //If the '2' key has been pressed add one to the end of the pin string
        {
            num+="2";
        }
        if(GetAsyncKeyState('3') != 0)       //If the '3' key has been pressed add one to the end of the pin string
        {
            num+="3";
        }
        if(GetAsyncKeyState('4') != 0)       //If the '4' key has been pressed add one to the end of the pin string
        {
            num+="4";
        }
        if(GetAsyncKeyState('5') != 0)       //If the '5' key has been pressed add one to the end of the pin string
        {
            num+="5";
        }
        if(GetAsyncKeyState('6') != 0)       //If the '6' key has been pressed add one to the end of the pin string
        {
            num+="6";
        }
        if(GetAsyncKeyState('7') != 0)       //If the '7' key has been pressed add one to the end of the pin string
        {
            num+="7";
        }
        if(GetAsyncKeyState('8') != 0)       //If the '8' key has been pressed add one to the end of the pin string
        {
            num+="8";
        }
        if(GetAsyncKeyState('9') != 0)       //If the '9' key has been pressed add one to the end of the pin string
        {
            num+="9";
        }
        if(GetAsyncKeyState('0') != 0)       //If the '0' key has been pressed add one to the end of the pin string
        {
            num+="0";
        }
        if (GetAsyncKeyState(VK_RETURN) != 0)    //If enter key is pressed
        {
            if(secrun == 1)                     //If past first run, print the entered pin and return it to main
            {
                cout<<num<<endl;
                cin.clear();
                return num;
            }
            else                                //If still on the first run set second run variable to 1 and clear num
            {
                secrun = 1;
                num.clear();
            }

        }
        if(secrun == 1)                     //If past the first run output the number the user has entered so far
        {
            cout << num << endl;

        }
        else{                              //If not past first run set second run variable to 1 and clear num
            secrun=1;
            num.clear();
        }
        Sleep(100);                        //Sleep for 100ms to just allow a buffer before the loop is started again to
    }                                      //stop the screen flickering
    timedout=1;                            //If 30s has ended make timeout =1
    return "0";                            //When 30s is don return "0"
}
