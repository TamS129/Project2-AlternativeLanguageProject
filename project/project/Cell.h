#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <set>
#include "Column.h"


using namespace std;

class Cell {
private:

    unordered_map<int, Column> newCol;
    vector<string> getStringValues(const string& infoNeed);
    vector<float> getValues(string infoNeed);

public:
    void addColumns(int colNum, Column col);
    int printChart();
    float findSD(string infoNeed);
    float findMean(string infoNeed);
    float findMedian(string infoNeed);
    string countUniqueValues(string infoNeed);
    void deleteColumns(int colNum);

};
#endif // CELL_H


