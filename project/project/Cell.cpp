#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>

#include "Cell.h"

void Cell::addColumns(int colNum, Column col) {

    pair<int, Column> insertCol = make_pair(colNum, col);
    newCol.insert(insertCol);

};

void Cell::deleteColumns(int colNum) {
    auto iter = newCol.find(colNum);
    if (iter != newCol.end()) {
        newCol.erase(iter);
    }
    else {
        cout << "Cannot find column. Please try again." << endl;
    }

}



float Cell::findSD(string infoNeed) {
    vector<float> values = getValues(infoNeed);
    if (values.empty()) {
        return 0;
    }
    float mean = findMean(infoNeed);
    float sum = 0;

    for (float value : values) {
        sum += (value - mean) * (value - mean);

    }
    return sqrt(sum / values.size());

}

float Cell::findMean(string infoNeed) {
    vector<float> values = getValues(infoNeed);

    if (values.empty()) {
        return 0;
    }

    float sum = 0;
    for (float value : values) {
        sum += value;
    }

    return sum / values.size();

}

float Cell::findMedian(string infoNeed) {
    std::vector<float> values = getValues(infoNeed);
    if (values.empty()) return 0;

    sort(values.begin(), values.end());

    size_t size = values.size();
    if (size % 2 == 0) {

        return (values[size / 2 - 1] + values[size / 2]) / 2;

    }
    else {

        return values[size / 2];
    }
}


string Cell::countUniqueValues(string infoNeed) {
    return "Null";

}

int Cell::printChart() {
    cout << "Chart:\n";
    cout << "--------------------------\n";
    for (const auto& pair : newCol) {
        cout << pair.first << ":\t" << endl;

    }
    std::cout << "--------------------------\n";
    return 0;

};

vector<float> Cell::getValues(string infoNeed) {
    std::vector<float> values;
    for (const auto& pair : newCol) {
        const Column& col = pair.second;
        if (infoNeed == "body_weight") {
            values.push_back(col.getBodyWeight());
        }
        else if (infoNeed == "display_size") {
            values.push_back(col.getDisplaySize());
        }
        // Add more fields as needed
    }
    return values;
}

vector<string> Cell::getStringValues(const string& infoNeed) {
    std::vector<std::string> values;
    for (const auto& pair : newCol) {
        const Column& col = pair.second;
        if (infoNeed == "oem") {
            values.push_back(col.getOem());
        }
        else if (infoNeed == "model") {
            values.push_back(col.getModel());
        }
       

    }
    return values;
}

