#include <iostream>
#include <string>

using namespace std;

int calculateFrequency(int num, int d);

/**
* Requires: pin has no leading zeros
* Modifies: nothing
* Effects : (1) returns false if pin has less than five digits;
*           (2) returns false if pin has more than five digits;
*           (3) returns false if pin has a repeating digit;
*           (4) returns true if pin contains exactly five
*               non-repeating digits;
**/
bool isValidPin(int pin) {

    // TODO: implement
    string pinStr = to_string(pin);
    if (pinStr.length() != 5) {
        return false; // PIN is not exactly five digits
    }
    for (int i = 0; i < pinStr.length(); ++i) {
        for (int j = i + 1; j < pinStr.length(); ++j) {
            if (pinStr[i] == pinStr[j]) {
                return false; // Found a repeating digit
            }
        }
    }
    return true; // PIN is valid
}