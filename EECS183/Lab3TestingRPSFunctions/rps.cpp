#include <iostream>
#include <string>

using namespace std;


//************************************************************************
// You will implement the following functions in rps.cpp for Project 2
//************************************************************************

/**
 * Requires: nothing
 * Modifies: nothing
 * Effects:  Returns true if and only if move represents a valid move character:
 *           one of 'R', 'r', 'P', 'p', 'S', 's'. Returns false otherwise.
 */
bool isMoveGood(char move);

/**
 * Requires: winnerName is the name of the player who won the round.
 * Modifies: cout
 * Effects:  If winnerName is empty, prints a message indicating the round
 *           is a draw. Otherwise, prints a congratulatory message to the
 *           winner.
 * Prompt:   This round is a draw!
 *           ------------- OR -------------
 *           [winner_name] wins the round!
 */
void announceRoundWinner(string winnerName);


//************************************************************************
// Testing function declarations. Function definition is below main.
//************************************************************************
void test_isMoveGood();
void test_announceRoundWinner();

int main() {
    cout << "\nExecuting your test cases\n";

    test_isMoveGood();
    test_announceRoundWinner();
    // TODO: call more test functions here

    return 0;
}

//************************************************************************
// Put all your test function implementations below here.
// We have stubbed all required functions for you
// to recieve full points when submitting test.cpp
// NOTE: We will only grade your tests for the following functions
//       * isMoveGood
//       * announceRoundWinner()
//************************************************************************

void test_isMoveGood() {
    cout << "Now testing function isMoveGood()\n";
    cout << "'r': Expected: 1, Actual: " << isMoveGood('r') << endl;

    char validMoves[] = {'R', 'r', 'P', 'p', 'S', 's'};
    for (char move : validMoves) {
        if (!isMoveGood(move)) {
            cout << "FAILED: isMoveGood('" << move << "') should have returned 'true'\n";
        }
    }

    char invalidMoves[] = {'a', 'Z', '0', 'x', 'B', 'y'}; // Examples of invalid moves
    for (char move : invalidMoves) {
        if (isMoveGood(move)) {
            cout << "FAILED: isMoveGood('" << move << "') should have returned 'false'\n";
        }
    }
    // TODO: implement more test cases here

    return;
}

void test_announceRoundWinner() {
    cout << "Now testing function announceRoundWinner()\n";

	// TODO: implement test cases here
    cout << "Testing with empty string for draw scenario.\n";
    announceRoundWinner("");

    cout << "Testing with a winner name.\n";
    announceRoundWinner("Alice");
    return;
}

// DO NOT ALTER THE CODE BELOW THIS LINE IN ANY WAY
// WRITE YOUR CODE IN THE FUNCTIONS ABOVE

#if defined(DEBUG) || defined(_DEBUG)
bool isMoveGood(char move) {
    
    // this (incorrect) implementation returns false to avoid compile error
    // you DO NOT need to implement this function as part of the lab
    // you will implement this function for Project 2 RPS
    return false;
}

void announceRoundWinner(string winnerName) {
    
    // you DO NOT need to implement this function as part of the lab
    // you will implement this function for Project 2 RPS
    return;
}
#endif