/* Communication.h
   Communication class header which includes private attribute of owner's phone number.
   This class has functions to notify an owner to a given phone number and the police.
   The user is able to get existing phone number and to change it.

   Created by Justas Vaitkevicius on 06/02/2017.
*/

#ifndef COMMUNICATION_H_INCLUDED
#define COMMUNICATION_H_INCLUDED

#include <string>
using namespace std;

class Communication
{
private:
    string phoneNumber; // Owner's phone number. Used to notify in case of alarm system activation.
public:
    // constructors
    Communication();
    Communication( string );
    // functions:
    void notifyNumber();    // function to send SMS message to the owner.
    void notifyPolice();    // function to send SMS message to the police.
    void changeNumber( string );    // function to change existing phone number.
    string getPhoneNumber();    // function that returns owner's phone number.
};

#endif // COMMUNICATION_H_INCLUDED
