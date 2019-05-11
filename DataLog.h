//Header file for the DataLog Class
#define DATALOG_H               //defining the class
#include<iostream>              //used for coding purposes
using namespace std;            //used for shortcuts

class DataLog //Name of the class
{
    private: //Attributes
        FILE log; //the text file that is being stored
        string message; //The latest message

    public:
        //Contructors
        DataLog(); //Initialization
        DataLog(FILE, string);

        void updateLog(string, string); //used to record data and recent changes
        string getLog(); //used to record changes on the screen
};
