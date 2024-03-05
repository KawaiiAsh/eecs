#include <iostream>
#include <string>

using namespace std;

bool isValidPin(int pin);

void testisValidPin() {
    if (isValidPin(1234)) {
        cout << "FAILED: Test with PIN 1234 (fewer than five digits should be invalid)." << endl;
    } else {
        cout << "PASSED: Test with PIN 1234." << endl;
    }

    if (isValidPin(123456)) {
        cout << "FAILED: Test with PIN 123456 (more than five digits should be invalid)." << endl;
    } else {
        cout << "PASSED: Test with PIN 123456." << endl;
    }

    if (isValidPin(11234)) {
        cout << "FAILED: Test with PIN 11234 (repeating digits should be invalid)." << endl;
    } else {
        cout << "PASSED: Test with PIN 11234." << endl;
    }

    if (!isValidPin(12345)) {
        cout << "FAILED: Test with PIN 12345 (valid PIN was not accepted)." << endl;
    } else {
        cout << "PASSED: Test with PIN 12345." << endl;
    }
}