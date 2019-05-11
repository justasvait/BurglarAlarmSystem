//Body for the Data Log Class
//Author: Daulet Alzhanov
//The class was designed to keep track of logs by appending and displaying them.
#include "DataLog.h"        //Calling the Data Log h file
#include <iostream>         //Used to operate cout and cin
#include <string>           //Used to string operations
#include <iomanip>          //Used for the setw function
#include <fstream>          //Used to open and close FILEs
#include <stdlib.h>         //Used for string conversion purposes
using namespace std; //Used to make codes shorter
////////////////////////////////////////////////////////////
//Constructors
DataLog::DataLog()
{
        FILE log;
        string message = "";
}
////////////////////////////////////////////////////////////
//
DataLog::DataLog(FILE filename, string letter)
{
    message = letter;
    log = filename;
}
/////////////////////////////////////////////////////////////
//updateLog is used to append new infromation with given time
void DataLog::updateLog(string logString, string time)
{//logString is the information that is being passed
 //time is the variable that that information had occurred at
    ofstream writing; //declaring the writing FILE
    writing.open("logs.txt", ios_base::app); //openning the logs.txt file and appending the info
    writing << left << setw(10) << setfill(' ') << time; //inputting time info and having 10 spaces for next column
    writing << setw(20) << logString << endl; //inputting the information that was carried forward
    writing.close(); //Closing the writing to save memory
}
//////////////////////////////////////////////////////////////
//getlog method is used to read and display logs on the screen
string DataLog::getLog()
{
    string content; //used as a temporary holder for data
    ifstream reading; //declaring the reading FILE
    reading.open("logs.txt"); //opening the logs.txt file
    cout << left << setw(10) << setfill(' ') << "Time"; //Creating the heading for time with 10 spacings for recent activity or changes
    cout << setw(20) << "Recent Activity" << endl; //Creating the second heading for Recent Activity
    while(getline(reading, content)) //using the while loop to read the text file onto the contents
    {
        cout << content << endl; //displaying the contents on the screen
    }
    reading.close(); //closing the FILE
    return content; //used to read the last line
}
