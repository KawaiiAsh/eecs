#include "polybius.h"
#include <string>
using namespace std;

//************************************************************************
// Implement the functions below this line.
//************************************************************************

string mixKey(string key) {
    // TODO: implement
    const string ALNUM = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string result;

    result += key;

    for (int i = 0; i < ALNUM.length(); ++i) {
        if (key.find(ALNUM[i]) == string::npos) {
            result += ALNUM[i];
        }
    }
    return result;
}

void fillGrid(char grid[SIZE][SIZE], string content) {
    // TODO: implement
    int index = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            grid[i][j] = content[index++];
        }
    }
    return;
}

string findInGrid(char c, char grid[SIZE][SIZE]) {
    // TODO: implement
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (grid[i][j] == c) {
                return string(1, '0' + i) + string(1, '0' + j);
            }
        }
    }
    return "";
}

string polybiusSquare(char grid[SIZE][SIZE], string key, 
                      string original, bool encrypt) {
    // TODO: implement
    string result;
    string mixedKey = mixKey(key);
    fillGrid(grid, mixedKey);

    if (encrypt) {
        for (char c : original) {
            if (c == ' ') {
                result += ' ';
            } else {
                result += findInGrid(c, grid);
            }
        }
    } else {
        for (size_t i = 0; i < original.length(); i += 2) {
            if (original[i] == ' ') {
                result += ' ';
                i--;
            } else {
                int row = original[i] - '0';
                int col = original[i + 1] - '0';
                result += grid[row][col];
            }
        }
    }
    return result;
}