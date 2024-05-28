#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>
#include "Cell.h"

using namespace std;

class FileReader {

    public:

    void ReadCSV(string fileName);


    /*
    Checks to see if a oem or model is null. If null it returns a string called "Null". Else it returns the String.
    Parameters:
    const string token - String to check the name.
    Returns the token or "Null"
    */

    string checkString(string token);

    /*
    Checks to see if the realease year is in correct format and converts it to a integer. If not return -1 for Null.
    Parameters:
    const string token - String to check the year.
    Returns integer of the year or -1 for Null.
    */

    int checkYear(string token);
    /*
    Checks the launch status of the phone and returns the status.
    Parameters:
    const string token - String to check the status.
    Returns String of the status or Null.
    */

    string checkStatus(string token);
    /*
    Checks to see if the weight of the body is correct and converts it into a float.
    Parameters:
    const string token - String to check the weight.
    Returns a float for the weight or -1.0 to represent Null.
    */

    float checkWeight(string token);

    /*
    Checks returns the SIM of the phone, if the column has "Yes" or "No" it returns "NULL"
    Parameters:
    const string token - String to check the SIM.
    Returns string of SIM or Null.
    */

    string checkSim(string token);

    /*
    Checks to see if the display size of the phone in a set pattern in inches.
    Parameters:
    const string token - String to check the display size.
    Returns float of the display size or returns -1.0 to represent Null.
    */

    float checkDisplaySize(string token);
    /*
    Checks to get the full name of the POS and returns the POS information.
    Parameters:
    const string token - String to check the year.
    Returns string of POS.
    */

    string checkPOS(string token);
}; 
#endif //FILEREADER_H

