#include <iostream>
#include "FileReader.h"
#include "Cell.h"

int main() {
    FileReader read;
    read.ReadCSV("src\\Files\\cells.csv");


    Cell cell;
    cell.printChart();
    
    return 0;
}