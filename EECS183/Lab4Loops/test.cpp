#include "loops.h"

#include <iostream>
using namespace std;

void testPrintRectangle();
void testPrintRight();
void testPrintRightJustified();
void testPrintIsosceles();

int main() {
    
    // TODO
    // Once you have completed the testing functions
    // call them such that the tests actually get run
    testPrintRectangle();
    testPrintRight();
    testPrintRightJustified();
    testPrintIsosceles();
    return 0;
}

void testPrintRectangle() {
    cout << "Testing printRectangle()" << endl;
    printRectangle(8, 8);
    
}

// TODO
// Implement your other test_functions

void testPrintRight() {
    cout << "Testing printRight()" << endl;
    printRight(5);
}

void testPrintRightJustified() {
    cout << "Testing printRightJustified()" << endl;
    printRightJustified(5);
}

void testPrintIsosceles() {
    cout << "Testing printIsosceles()" << endl;
    printIsosceles(5);
}