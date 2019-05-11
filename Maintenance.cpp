#include "Maintenance.h"
#include <iostream>
using namespace std;

void Maintenance::menu()
{
    char choice;
    bool temp;
    cout << "%Menu: a b c d" << endl;
    cin >> choice;
    switch (choice)
    {
    case 'a':
        temp = WindowSensor.getStatus();
        cout << "%Windows status: " << temp << endl;
        VibrationSensor.detect();
        cout << "%Vibration sensors detected." << endl;
        cout << "%Windows status: " << WindowSensor::getStatus() << endl;
        WindowSensor::windowOpen = false;
        cout << "%Reset windows status: " << WindowSensor::getStatus() << endl;
        MagneticSensor::detect();
        cout << "%Magnetic sensors detected." << endl;
        cout << "%Windows status: " << WindowSensor::getStatus() << endl;


        break;
    case 'b':

        break;
    case 'c':

        break;
    case 'd':

        break;
    default:
        break;
    }

}
