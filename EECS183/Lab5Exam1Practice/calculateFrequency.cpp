#include <iostream>
#include <string>

using namespace std;

/**
* Requires: (1) num > 0
*           (2) num has no leading zeros
*           (3) 0 <= d <= 9
* Modifies: nothing
* Effects : returns the number of times digit d appears in num
* 
* Note:     Your implementation should work for values of num 
*           that contain any number of digits.
*           Here is a breakdown of the iterations needed for 
*           calculateFrequency(133, 3), which should return 2 
*           because the digit 3 appears in 133 twice.
*            
*           1. 133 / 1 = 133 --> 133 % 10 = 3 ⇒ rightmost digit of 133 is 3
*           2. 133 / 10 = 13 --> 13 % 10 = 3 ⇒ next digit of 133 is 3
*           3. 133 / 100 = 1 --> 1 % 10 = 1 ⇒ next digit of 133 is 1
*           4. 133 / 1000 = 0 --> no additional digits in 133 
**/
int calculateFrequency(int num, int d) {

	// TODO: implement
    int frequency = 0; // Initialize frequency counter
    while (num > 0) {
        if (num % 10 == d) {
            frequency++; // Increment frequency if the rightmost digit matches d
        }
        num /= 10; // Remove the rightmost digit from num
    }
    return frequency;
}