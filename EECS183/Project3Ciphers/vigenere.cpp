#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include <iostream>

//************************************************************************
// Implement the functions below this line.
//************************************************************************

string vigenereCipher(string original, string keyword, bool encrypt) {
    string result = "";
    int keyLength = keyword.length();
    keyword = toUpperCase(keyword);
    int t = 0;

    for (int i = 0; i < original.size(); i++) {
        if (isalpha(original.at(i))) {
            while (!isalpha(keyword[t % keyLength])) {
                t++;
            }

            int shift = keyword[t % keyLength] - 'A';
            if (isupper(original.at(i))) {
                if (encrypt) {
                    original.at(i) = (original.at(i) - 'A' + shift) % 26 + 'A';
                } else {
                    original.at(i) = (original.at(i) - 'A' - shift + 26) % 26 + 'A';
                }
            } else if (islower(original.at(i))) {
                if (encrypt) {
                    original.at(i) = (original.at(i) - 'a' + shift) % 26 + 'a';
                } else {
                    original.at(i) = (original.at(i) - 'a' - shift + 26) % 26 + 'a';
                }
            }
            t++;
        }
        result += original.at(i);
    }
    return result;
}