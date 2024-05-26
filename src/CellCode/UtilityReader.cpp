#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <regex>
#include <unordered_set>

#include "Column.cpp"
#include "Cell.cpp"


using namespace std;

// Note: There are some notes throughout this code to help me conceptualize Java to C++. 

class UtilityReader {
public:
    /*
    Reads the inputted CSV and converts the columns in a column object to be read in Cell. 
    Parameters:
    const string fileName - Name of the file. 
    */
    void ReadCSV(const string& fileName) {
        //ifstream -> Scanner in Java. line contains the token(characters between the commas in the CSV), ColNum to be generatred.
        ifstream file(fileName);
        string line = "";
        int colNum = 0;
        
        //First check to see if the file can be found.
        if (!file.is_open()){
            //Cerr -> Exception Error handling
            cerr << "CSV File cannot be found." << endl;
            return;
        }

        while(getline(file, line)){
            //lineStream -> getNextLine() in Scanners.
            // Vector in C++ -> Arraylist in Java
            istringstream lineStream(line);
            string token;
            vector<string> tokens;
            
            //While to place the list of tokens from the parsed file into a vector of tokens.
        
            while (std::getline(lineStream, token, ',')) {
                tokens.push_back(token);
             }
        

            
            //Places each token within it's respective type. 
            string oem = checkString(tokens[0]);
            string model = checkString(tokens[1]);
            int launch_announced = checkYear(tokens[2]);
            string launch_status = checkStatus(tokens[3]);
            string body_dimensions = checkString(tokens[4]);
            float body_weight = checkWeight(tokens[5]);
            string body_sim = checkSim(tokens[6]);
            string display_type = checkString(tokens[7]);
            float display_size = checkDisplaySize(tokens[8]);
            string display_resolution = checkString(tokens[9]);
            string feature_sensors = checkString(tokens[10]);
            string platform_os = checkPOS(tokens[11]);

            //Duplicate Prevention:
            //Unordered_set -> HashSet which is simular to a HashMap
            unordered_set<string> seenColumns;
           //Plaves all of the variables into a string and checks if there are any columns that may be a duplicate.
            string columnStr = oem + model + to_string(launch_announced) + launch_status + body_dimensions +  to_string(body_weight) + body_sim + display_type + to_string(display_size) + display_resolution + feature_sensors + platform_os;

            //If a column is a duplicate it skips the column. 
            if (seenColumns.find(columnStr) != seenColumns.end()) {
                continue; 
            }

            // if the column is not a duplicate it adds it to a seen column. 
            seenColumns.insert(columnStr);
            

            //Places the found items into a new column object. Then places them into a unordered map (Aka Hashmap)
            Column newCol(oem, model, launch_announced, launch_status, body_dimensions, body_weight, body_sim, display_type, display_size, display_resolution, feature_sensors, platform_os);
            Cell newMap;
            newMap.addColumns(colNum, newCol);
            colNum++;
        }
    }

    /*
    Checks to see if a oem or model is null. If null it returns a string called "Null". Else it returns the String.
    Parameters:
    const string token - String to check the name.
    Returns the token or "Null"
    */

   string checkString(string token){
    if(token == "-"){
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

   int checkYear(string token){
    //Regex is a function that allows for data to be placed within a specfic format/pattern.
    regex year_regex(R"(\b(\d{4})\b)");
    //Smatch allows for regex patterns to be matched up with strings. 
    smatch match;

    if(regex_search(token, match, year_regex)){
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

   string checkStatus(string token){
        if(token == "Discontinued" || token == "Cancelled" || regex_match(token,regex(R"(Available\. Released \d{4})"))){
            
            return token;
        }

        else{
            return "Null";

        }

   }

    /*
    Checks to see if the weight of the body is correct and converts it into a float.
    Parameters:
    const string token - String to check the weight.
    Returns a float for the weight or -1.0 to represent Null.
    */

   float checkWeight(string token){
        regex weight_regex(R"((\d+\.?\d*) g)");
        smatch match;

        if(regex_search(token, match, weight_regex)){
            
            //stof works simular to stoi but instead turns strings into floats rather than integers.
            return stof(match.str(1));

        }
        else{
            return -1.0;
        }

   }

    /*
    Checks returns the SIM of the phone, if the column has "Yes" or "No" it returns "NULL"
    Parameters:
    const string token - String to check the SIM.
    Returns string of SIM or Null.
    */

   string checkSim(string token){
        if(token == "Yes" || token == "No"){
            return "Null";

        }
        else{
            return token;
        }

   }

    /*
    Checks to see if the display size of the phone in a set pattern in inches. 
    Parameters:
    const string token - String to check the display size.
    Returns float of the display size or returns -1.0 to represent Null.
    */

   float checkDisplaySize(string token){
        regex ds_regex(R"((\d+\.?\d*) inches)");
        smatch match; 

        if(regex_search(token, match, ds_regex)){
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

   string checkPOS(string token){
        size_t pos = token.find(',');
        return (pos == string::npos) ? token : token.substr(0, pos);
   }

};


