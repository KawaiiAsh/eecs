#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;

void testToUpperCase();

void testRemoveNonAlphas();

void testCharToInt();

void testRemoveDuplicate();

void testShiftAlphaCharacter();

void testCaesarCipher();

void testVigenereCipher();

void testMixKey();

void testFillGrid();

void testFindInGrid();

void testPolybiusSquare();

void startTests() {
    testToUpperCase();
    testRemoveNonAlphas();
    testCharToInt();
    testRemoveDuplicate();
    testShiftAlphaCharacter();
    testCaesarCipher();
    testVigenereCipher();
    testMixKey();
    testFillGrid();
    testFindInGrid();
    testPolybiusSquare();
}

void testToUpperCase() {
    cout << "Testing toUpperCase()" << endl;
    cout << "Input: 'aBc123', Expected: 'ABC123', Actual: " << toUpperCase("aBc123") << endl;
}

void testRemoveNonAlphas() {
    cout << "Testing removeNonAlphas()" << endl;
    cout << "Input: 'aBc123', Expected: 'aBc', Actual: " << removeNonAlphas("aBc123") << endl;
}

void testCharToInt() {
    cout << "Testing charToInt()" << endl;
    cout << "Input: '5', Expected: 5, Actual: " << charToInt('5') << endl;
}

void testRemoveDuplicate() {
    cout << "Testing removeDuplicate()" << endl;
    cout << "Input: 'AABBCC', Expected: 'ABC', Actual: " << removeDuplicate("AABBCC") << endl;
    cout << "Input: 'AAB1B2CC3', Expected: 'AB123C', Actual: " << removeDuplicate("AAB1B2CC3") << endl;
    cout << "Input: '', Expected: '', Actual: '" << removeDuplicate("") << "'" << endl;
    cout << "Input: 'ABC123', Expected: 'ABC123', Actual: '" << removeDuplicate("ABC123") << "'" << endl;
}


void testShiftAlphaCharacter() {
    cout << "Testing shiftAlphaCharacter()" << endl;
    cout << "Input: ('a', 1), Expected: 'b', Actual: " << shiftAlphaCharacter('a', 1) << endl;
    cout << "Input: ('a', -1), Expected: 'z', Actual: " << shiftAlphaCharacter('a', -1) << endl;
    cout << "Input: ('a', 26), Expected: 'a', Actual: " << shiftAlphaCharacter('a', 26) << endl;
    cout << "Input: ('A', 2), Expected: 'C', Actual: " << shiftAlphaCharacter('A', 2) << endl;
}

void testCaesarCipher() {
    cout << "Testing caesarCipher()" << endl;
    cout << "Input: ('ABC', 3, true), Expected: 'DEF', Actual: " << caesarCipher("ABC", 3, true) << endl;
    cout << "Decrypting 'DEF' with key 3, Expected: 'ABC', Actual: " << caesarCipher("DEF", 3, false) << endl;
    cout << "Encrypting 'XYZ' with key -3, Expected: 'UVW', Actual: " << caesarCipher("XYZ", -3, true) << endl;
    cout << "Encrypting 'ABC' with key 29, Expected: 'DEF', Actual: " << caesarCipher("ABC", 29, true) << endl;
}

void testVigenereCipher() {
    cout << "Testing vigenereCipher()" << endl;
    cout << "Input: ('ATTACKATDAWN', 'LEMON', true), Expected: 'LXFOPVEFRNHR', Actual: "
         << vigenereCipher("ATTACKATDAWN", "LEMON", true) << endl;
}

void testMixKey() {
    cout << "Testing mixKey()" << endl;
    cout << "Input: 'LEMON', Expected starts with 'LEMON', Actual: " << mixKey("LEMON") << endl;
}

void testFillGrid() {
    cout << "Testing fillGrid()" << endl;
    char grid[SIZE][SIZE];
    fillGrid(grid, "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
    cout << "First cell, Expected: 'A', Actual: " << grid[0][0] << endl;
}

void testFindInGrid() {
    cout << "Testing findInGrid()" << endl;
    char grid[SIZE][SIZE] = {{'A', 'B', 'C', 'D', 'E', 'F'},
                             {'G', 'H', 'I', 'J', 'K', 'L'},
                             {'M', 'N', 'O', 'P', 'Q', 'R'},
                             {'S', 'T', 'U', 'V', 'W', 'X'},
                             {'Y', 'Z', '0', '1', '2', '3'},
                             {'4', '5', '6', '7', '8', '9'}};
    cout << "Input: 'A', Expected: '00', Actual: " << findInGrid('A', grid) << endl;
}

void testPolybiusSquare() {
    cout << "Testing polybiusSquare()" << endl;
    char grid[SIZE][SIZE];
    string key = mixKey("KEYWORD");
    fillGrid(grid, key);
    cout << "Input: ('HELLO WORLD', 'KEYWORD', true), Expected: Encrypted output, Actual: "
         << polybiusSquare(grid, key, "HELLO WORLD", true) << endl;
}