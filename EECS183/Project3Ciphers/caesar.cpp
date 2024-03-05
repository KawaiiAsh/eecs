#include "caesar.h"
#include <iostream>

//************************************************************************
// Implement the functions below this line.
//************************************************************************

char shiftAlphaCharacter(char c, int n) {
    // TODO: implement
    if (!isalpha(c)) return c;

    char base = islower(c) ? 'a' : 'A';
    n = n % 26;
    int position = c - base + n;

    if (position < 0) {
        position += 26;
    }

    return static_cast<char>((position % 26) + base);
}

string caesarCipher(string original, int key, bool encrypt) {
    // TODO: implement
    if (!encrypt) {
        key = -key;
    }
    for (char &c : original) {
        if (isalpha(c)) {
            int shift = (islower(c) ? 'a' : 'A');
            int n = (c - shift + key) % 26;
            if (n < 0) n += 26;
            c = static_cast<char>(n + shift);
        }
    }
    return original;
}