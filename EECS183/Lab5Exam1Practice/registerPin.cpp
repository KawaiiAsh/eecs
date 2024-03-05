#include <iostream>
#include <string>

using namespace std;

bool isValidPin(int pin);

/**
* Requires: nothing
* Modifies: nothing
* Effects : repeatedly prompt a user until they enter a valid pin
*
* Sample run: user input is followed by <enter> 
*             denoting the user presseing enter
* 
*   Please enter a pin:
*   123<enter>
*   Invalid pin. Use exactly five non-repeating digits.
*   Please enter a pin:
*   11335<enter>
*   Invalid pin. Use exactly five non-repeating digits.
*   Please enter a pin:
*   12345<enter>
*   Your pin has been registered. Thank you!
**/
void registerPin() {
    int pin;
    bool valid;
    do {
        cout << "\nPlease enter a pin:";
        cin >> pin;
        valid = isValidPin(pin);
        if (!valid) {
            cout << "\nInvalid pin. Use exactly five non-repeating digits.";
        }
    } while (!valid);
    cout << "\nYour pin has been registered. Thank you!" << endl;
}