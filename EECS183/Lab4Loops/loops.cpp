#include "loops.h"
#include <iostream>

using namespace std;

/** 
 * TODO
 * Implement all loops.h functions:
 * printRectangle, printRight, printRightJustified, printIsosceles
 */
// Implementation of printRectangle
void printRectangle(int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "*";
        }
        cout << endl; // Ensures there's an endl after each row
    }
}

// Implementation of printRight
void printRight(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << "*";
        }
        cout << endl; // Ensures there's an endl after each row
    }
}

// Implementation of printRightJustified
void printRightJustified(int n) {
    for (int i = 1; i <= n; ++i) {
        // Print leading spaces
        for (int j = 0; j < n - i; ++j) {
            cout << " ";
        }
        // Print asterisks
        for (int j = 0; j < i; ++j) {
            cout << "*";
        }
        cout << endl; // Ensures there's an endl after each row
    }
}

// Implementation of printIsosceles
void printIsosceles(int n) {
    for (int i = 1; i <= n; ++i) {
        // Print leading spaces
        for (int j = 1; j <= n - i; ++j) {
            cout << " ";
        }
        // Print asterisks
        for (int k = 1; k <= 2 * i - 1; ++k) {
            cout << "*";
        }
        cout << endl; // Ensures there's an endl after each row
    }
}