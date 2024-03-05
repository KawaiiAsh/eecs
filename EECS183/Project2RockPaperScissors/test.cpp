#include <iostream>
#include <string>

using namespace std;


//************************************************************************
// You should have implemented the following functions in rps.cpp
//************************************************************************
string getName(int playerNumber);
int getMenuChoice();
bool isMoveGood(char move);
char getMove(string playerName);
bool isRoundWinner(char move, char opponentMove);
void announceRoundWinner(string winnerName);
int doRound(string p1Name, string p2Name);
void announceWinner(string winnerName);
string doGame(string p1Name, string p2Name, int gameType);

//************************************************************************
// The following functions were already implemented for you in rps.cpp
//************************************************************************
void printInitialHeader();
void printMenu();
void printErrorMessage(int errorNumber);
void printCloser();

//************************************************************************
// Testing function declarations. Function definition is below main.
//************************************************************************
void test_isMoveGood();
void test_isRoundWinner();
void test_announceRoundWinner();
void test_announceWinner();


void startTests() {
    cout << "\nExecuting your test cases\n";

    test_isMoveGood();
    // TODO: call more test functions here
    test_isRoundWinner();
    test_announceRoundWinner();
    test_announceWinner();
    return;
}

//************************************************************************
// Put all your test function implementations below here.
// We have stubbed all required functions for you
// to recieve full points when submitting test.cpp
// NOTE: We will only grade your tests for the following functions
//       * isMoveGood
//       * isRoundWinner
//       * announceRoundWinner()
//       * announceWinner()
//************************************************************************

void test_isMoveGood() {
    cout << "Now testing function isMoveGood()\n";
    cout << "'r': Expected: 1, Actual: " << isMoveGood('r') << endl;
    cout << "'q': Expected: 0, Actual: " << isMoveGood('q') << endl;

    // TODO: implement more test cases here
    cout << "'R': Expected: 1, Actual: " << isMoveGood('R') << endl;
    cout << "'P': Expected: 1, Actual: " << isMoveGood('P') << endl;
    cout << "'p': Expected: 1, Actual: " << isMoveGood('p') << endl;
    cout << "'S': Expected: 1, Actual: " << isMoveGood('S') << endl;
    cout << "'s': Expected: 1, Actual: " << isMoveGood('s') << endl;

    cout << "'A': Expected: 0, Actual: " << isMoveGood('A') << endl;
    cout << "'1': Expected: 0, Actual: " << isMoveGood('1') << endl;
    cout << "' ': Expected: 0, Actual: " << isMoveGood(' ') << endl;
    return;
}

void test_isRoundWinner() {
    cout << "Now testing function isRoundWinner()\n";
    cout << "Test Case - Scissors ('s') vs Paper ('p'): Expected: 1, Actual: " << isRoundWinner('s', 'p') << endl;
    cout << "Test Case - Rock ('r') vs Scissors ('s'): Expected: 1, Actual: " << isRoundWinner('r', 's') << endl;
    cout << "Test Case - Paper ('p') vs Rock ('r'): Expected: 1, Actual: " << isRoundWinner('p', 'r') << endl;
    cout << "Test Case - Rock ('r') vs Rock ('r'): Expected: 0, Actual: " << isRoundWinner('r', 'r') << endl;
    return;
}

void test_announceRoundWinner() {
    cout << "Now testing function announceRoundWinner()\n";
    cout << "Test Case - Player 1 wins the round.\n";
    announceRoundWinner("Player 1");
    cout << "Test Case - The round is a draw.\n";
    announceRoundWinner("");
    return;
}

void test_announceWinner() {
    cout << "Now testing function announceWinner()\n";
    cout << "Test Case - Player 1 wins the game.\n";
    announceWinner("Player 1");
    cout << "Test Case - No winner in the game.\n";
    announceWinner("");
    return;
}