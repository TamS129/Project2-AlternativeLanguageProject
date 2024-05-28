#include <iostream>
#include "FileReader.h"
#include "Cell.h"

int main() {
    FileReader read;
    read.ReadCSV("C:\\Users\\Terra\\Documents\\src\\Files\\cells.csv");


    Cell cell;
    cell.printChart();
    
    return 0;
}