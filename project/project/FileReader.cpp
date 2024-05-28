
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>
#include "Cell.h"
#include "FileReader.h"

using namespace std;

void FileReader::ReadCSV(std::string fileName) {
    std::ifstream inputFile;
    inputFile.open(fileName);

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return;
    }
    Cell newMap;
    int colNum = 0;

    std::string line = "";
    while (getline(inputFile, line)) {
        std::string oem, model, launch_status, body_dimensions, body_sim, display_type, display_resolution, feature_sensors, platform_os, temp;
        int launch_announced;
        float body_weight, display_size;

        std::stringstream inputString(line);

        getline(inputString, temp, ','); oem = checkString(temp.c_str());
        getline(inputString, temp, ','); model = checkString(temp.c_str());
        getline(inputString, temp, ','); launch_announced = checkYear(temp.c_str());
        getline(inputString, temp, ','); launch_status = checkStatus(temp.c_str());
        getline(inputString, temp, ','); body_dimensions = checkString(temp.c_str());
        getline(inputString, temp, ','); body_weight = checkWeight(temp.c_str());
        getline(inputString, temp, ','); body_sim = checkSim(temp.c_str());
        getline(inputString, temp, ','); display_type = checkString(temp.c_str());
        getline(inputString, temp, ','); display_size = checkDisplaySize(temp.c_str());
        getline(inputString, temp, ','); display_resolution = checkString(temp.c_str());
        getline(inputString, temp, ','); feature_sensors = checkString(temp.c_str());
        getline(inputString, temp, ','); platform_os = checkPOS(temp.c_str());

        Column newCol(oem, model, launch_announced, launch_status, body_dimensions, body_weight, body_sim, display_type, display_size, display_resolution, feature_sensors, platform_os);
        newMap.addColumns(colNum, newCol);
        colNum++;

       
    }

    newMap.printChart();
}


/*
Checks to see if a oem or model is null. If null it returns a string called "Null". Else it returns the String.
Parameters:
const string token - String to check the name.
Returns the token or "Null"
*/

string FileReader::checkString(string token) {
    if (token == "-") {
        return "Null";
    }

    else {
        return token;
    }
}

/*
Checks to see if the realease year is in correct format and converts it to a integer. If not return -1 for Null.
Parameters:
const string token - String to check the year.
Returns integer of the year or -1 for Null.
*/

int FileReader::checkYear(string token) {
    //Regex is a function that allows for data to be placed within a specfic format/pattern.
    regex year_regex(R"(\b(\d{4})\b)");
    //Smatch allows for regex patterns to be matched up with strings. 
    smatch match;

    if (regex_search(token, match, year_regex)) {
        //Stoi function turns strings into integers. str -> string 1 -> is our token.
        return stoi(match.str(1));

    }
    return -1;
}

/*
Checks the launch status of the phone and returns the status.
Parameters:
const string token - String to check the status.
Returns String of the status or Null.
*/

string FileReader::checkStatus(string token) {
    if (token == "Discontinued" || token == "Cancelled" || regex_match(token, regex(R"(Available\. Released \d{4})"))) {

        return token;
    }

    else {
        return "Null";

    }
}

/*
Checks to see if the weight of the body is correct and converts it into a float.
Parameters:
const string token - String to check the weight.
Returns a float for the weight or -1.0 to represent Null.
*/

float FileReader::checkWeight(string token) {
    regex weight_regex(R"((\d+\.?\d*) g)");
    smatch match;

    if (regex_search(token, match, weight_regex)) {

        //stof works simular to stoi but instead turns strings into floats rather than integers.
        return stof(match.str(1));

    }
    else {
        return -1.0;
    }
}

/*
Checks returns the SIM of the phone, if the column has "Yes" or "No" it returns "NULL"
Parameters:
const string token - String to check the SIM.
Returns string of SIM or Null.
*/

string FileReader::checkSim(string token) {
    if (token == "Yes" || token == "No") {
        return "Null";

    }
    else {
        return token;
    }
}

/*
Checks to see if the display size of the phone in a set pattern in inches.
Parameters:
const string token - String to check the display size.
Returns float of the display size or returns -1.0 to represent Null.
*/

float FileReader::checkDisplaySize(string token) {

    regex ds_regex(R"((\d+\.?\d*) inches)");
    smatch match;

    if (regex_search(token, match, ds_regex)) {
        return stof(match.str(1));
    }
    return -1.0;
}

/*
Checks to get the full name of the POS and returns the POS information.
Parameters:
const string token - String to check the year.
Returns string of POS.
*/

string FileReader::checkPOS(string token) {
    size_t pos = token.find(',');
    return (pos == string::npos) ? token : token.substr(0, pos);
}
