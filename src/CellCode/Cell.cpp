
#include <iostream>
#include <unordered_map>
#include <string>
#include "Column.cpp"
using namespace std;


class Cell {
private:
    unordered_map<int, Column> cellObj;

public:
     void addColumns(int colNum, Column col) {
        cellObj[colNum] = col;
    }

    void toString() {
     
    }
};


