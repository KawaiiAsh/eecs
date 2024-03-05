#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;

//************************************************************************
// Implement the functions below this line.
//************************************************************************

void ciphers() {
    // TODO: implement
    string cipherCode;
    string encOrDec;
    string originalMsg;
    string key;
    int caesarKey;
    char grid[6][6];

    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): " << endl;
    getline(cin, cipherCode);
    cipherCode = toUpperCase(cipherCode);

// Decide whether cipher is valid
    if (cipherCode != "CAESAR" && cipherCode != "C" && cipherCode != "VIGENERE"
        && cipherCode != "V" && cipherCode != "POLYBIUS" && cipherCode != "P") {
        cout << "Invalid cipher!";
    }
// Decide which encryption and print out the encrypted message
    else {
        cout << "Encrypt or decrypt: " << endl;
        getline(cin, encOrDec);
        encOrDec = toUpperCase(encOrDec);
        if (encOrDec != "ENCRYPT" && encOrDec != "DECRYPT"
            && encOrDec != "E" && encOrDec != "D") {
            cout << "Invalid mode!";
        } else {
            cout << "Enter a message: " << endl;
            getline(cin, originalMsg);
            if (cipherCode == "CAESAR" || cipherCode == "C") {
                cout << "What is your key: " << endl;
                cin >> caesarKey;
                if (encOrDec == "ENCRYPT" || encOrDec == "E") {
                    cout << "The encrypted message is: ";
                    cout << caesarCipher(originalMsg, caesarKey, 1);
                } else {
                    cout << "The decrypted message is: ";
                    cout << caesarCipher(originalMsg, caesarKey, 0);
                }
            } else if (cipherCode == "VIGENERE" || cipherCode == "V") {
                cout << "What is your key: " << endl;
                getline(cin, key);
                bool isNumber = true;
                int i = 0;
                while (i < key.size() && isNumber == true) {
                    if (!isdigit(key.at(i))) {
                        isNumber = true;
                    } else {
                        isNumber = false;
                    }
                    i++;
                }
                if (isNumber) {
                    if (encOrDec == "ENCRYPT" || encOrDec == "E") {
                        cout << "The encrypted message is: ";
                        cout << vigenereCipher(originalMsg, key, 1) << endl;
                    } else {
                        cout << "The decrypted message is: ";
                        cout << vigenereCipher(originalMsg, key, 0) << endl;
                    }
                } else {
                    cout << "Invalid key!" << endl;
                }

            } else if (cipherCode == "POLYBIUS" || cipherCode == "P") {
                bool isStr = true;
                int i = 0;
                while (i < originalMsg.size() && isStr == true) {
                    if ((originalMsg.at(i) == 32)
                        || (originalMsg.at(i) >= 48 && originalMsg.at(i) <= 57)
                        || (originalMsg.at(i) >= 65 && originalMsg.at(i) <= 90)
                        || (originalMsg.at(i) >= 97 && originalMsg.at(i) <= 122)) {
                        isStr = true;
                    } else {
                        isStr = false;
                    }
                    i++;
                }
                for (int k = 0; k < originalMsg.size(); k++) {
                    originalMsg.at(k) = toupper(originalMsg[k]);
                }
                if (isStr) {
                    cout << "What is your key: " << endl;
                    getline(cin, key);
                    key = toUpperCase(key);

                    if (encOrDec == "ENCRYPT" || encOrDec == "E") {
                        cout << "The encrypted message is: ";
                        cout << polybiusSquare(grid, key, originalMsg, 1) << endl;
                    } else {
                        cout << "The decrypted message is: ";
                        cout << polybiusSquare(grid, key, originalMsg, 0) << endl;
                    }
                } else {
                    cout << "Invalid message!" << endl;
                }
            } else {
                cout << "Invalid cipher!!";
            }
        }
    }
}