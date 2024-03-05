#include "utility.h"
#include <iostream>

//************************************************************************
// Implement the functions below this line.
//************************************************************************

string toUpperCase(string original) {
    // TODO: implement
    for (int i = 0; i < original.length(); ++i) {
        original[i] = toupper(original[i]);
    }
    return original;
}

string removeNonAlphas(string original) {
    // TODO: implement
    string result;
    for (char c : original) {
        if (isalpha(c)) {
            result += c;
        }
    }
    return result;
}

int charToInt(char original) {
    // TODO: implement
    return original - '0';
}

string removeDuplicate(string original) {
    // TODO: implement
    string result;
    for (char c : original) {
        if (result.find(c) == string::npos) {
            result += c;
        }
    }
    return result;
}

////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}
