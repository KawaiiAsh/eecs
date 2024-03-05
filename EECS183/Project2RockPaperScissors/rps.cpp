#include <iostream>
#include <string>

// Maximum number of rounds in a game
const int MAX_ROUNDS = 3;

using namespace std;

// Function declarations
void printInitialHeader();
void printMenu();
void printErrorMessage(int errorNumber);
void printCloser();
void rps();
string getName(int playerNumber);
int getMenuChoice();
bool isMoveGood(char move);
char getMove(string playerName);
bool isRoundWinner(char move, char opponentMove);
void announceRoundWinner(string winnerName);
int doRound(string p1Name, string p2Name);
void announceWinner(string winnerName);
string doGame(string p1Name, string p2Name, int gameType);

// Main game function that initializes the game and manages the game loop
void rps() {
    printInitialHeader();// Print the game's initial header
    // Initialize player names
    string playerOneName;
    string playerTwoName;
    playerOneName = getName(1);
    cout << endl;
    playerTwoName = getName(2);
    cout << endl;

    // Game menu and choice handling loop
    while (true) {
        int choice = getMenuChoice();
        if (choice == 3) { // Choice to quit the game
            cout << endl;
            printCloser(); // Print closing message
            break; // Exit the loop and end the game
        }
        // Play the game based on the choice (either standard or under construction mode)
        string gameWinner = doGame(playerOneName, playerTwoName, choice);
        announceWinner(gameWinner);
    }
}

// Function to get the player's name, with a default name if none is entered
string getName(int playerNumber) {
    string name;
    cout << "Player " << playerNumber << ", enter your name: ";
    getline(cin, name);
    if (name.empty()) {
        printErrorMessage(1);
        if (playerNumber == 1) {
            return "Rocky";
        } else {
            return "Creed";
        }
    }
    return name;// Return the entered or default name
}

// Function to display the game menu and get the user's choice
int getMenuChoice() {
    int menuChoice;
    bool isValidChoice = false;

    do {
        printMenu();
        cin >> menuChoice;
        if (menuChoice >= 1 && menuChoice <= 3) {
            isValidChoice = true;
        } else {
            cout << endl;
            cout << "Invalid menu choice" << endl;
        }

    } while (!isValidChoice);
    return menuChoice;
}

// Function to check if a player's move is valid ('R', 'P', 'S')
bool isMoveGood(char move) {
    bool isGood = (move == 'R' || move == 'r' || move == 'P' || move == 'p' || move == 'S' || move == 's');
    return isGood;
}

// Function to get a player's move and ensure it is valid
char getMove(string playerName) {
    char move;
    cout << endl;
    cout << playerName << ", enter your move: ";
    cin >> move;
    if (!isMoveGood(move)) {
        printErrorMessage(2);
        return 'r';// Return a default move if the input is invalid
    }
    return move;// Return the valid move
}

// Function to determine the winner of a round based on the moves
bool isRoundWinner(char move, char opponentMove) {
    move = tolower(move);
    opponentMove = tolower(opponentMove);
    // Determine the winner based on the rules of Rock-Paper-Scissors
    return (move == 'r' && opponentMove == 's') ||
           (move == 's' && opponentMove == 'p') ||
           (move == 'p' && opponentMove == 'r');
}
// Announces the winner of the current round or declares a draw if there is no winner.
void announceRoundWinner(string winnerName) {
    if (winnerName == "") {
        // If the winner name is empty, it indicates a draw.
        cout << endl;
        cout << "This round is a draw!" << endl;
    } else {
        // Announce the winner of the round.
        cout << endl;
        cout << winnerName << " wins the round!" << endl;
    }
}

// Executes a single round of the game, determining and announcing the round's winner.
int doRound(string playerOneName, string playerTwoName) {
    // Get moves from both players
    char playerOneMove = getMove(playerOneName);
    char playerTwoMove = getMove(playerTwoName);

    // Determine the winner of the round
    if (isRoundWinner(playerOneMove, playerTwoMove)) {
        // Player one wins the round.
        return 1;
    } else if (isRoundWinner(playerTwoMove, playerOneMove)) {
        // Player two wins the round.
        return 2;
    } else {
        // If neither player wins, it's a draw.
        return 0;
    }
}

// Announces the overall winner of the game or declares no winner if it's a draw.
void announceWinner(string winnerName) {
    cout << endl;
    if (winnerName == "") {
        // If the winner name is empty, it indicates no overall winner.
        cout << "No winner!" << endl;
    } else {
        // Congratulate the overall winner of the game.
        cout << "Congratulations " + winnerName << "!" << endl;
        cout << "You won EECS 183 Rock-Paper-Scissors!" << endl;
    }
}

// Manages the flow of the game, including determining the game type and announcing the overall winner.
string doGame(string playerOneName, string playerTwoName, int gameType) {
    int roundRound = 0;
    int playerOneScore = 0;
    int playerTwoScore = 0;
    if (gameType == 1){
        for (int i=0; i < MAX_ROUNDS; ++i){
            roundRound = doRound(playerOneName, playerTwoName);
            if (roundRound == 1){
                announceRoundWinner(playerOneName);
                playerOneScore+=1;
            }else if (roundRound == 2){
                announceRoundWinner(playerTwoName);
                playerTwoScore+=1;
            }else{
                announceRoundWinner("");
            }
        }
        if (playerOneScore > playerTwoScore){
            return playerOneName;
        }else if (playerOneScore < playerTwoScore){
            return playerTwoName;
        }else if (playerOneScore == playerTwoScore){
            return "";
        }
    }
    else if (gameType == 2){
        cout << "Under Construction" << endl;
        return "";
    }
    return"";
}

// Prints the initial game header.
void printInitialHeader() {
    cout << "----------------------------------------" << endl;
    cout << "               EECS 183                 " << endl;
    cout << "          Rock-Paper-Scissors           " << endl;
    cout << "----------------------------------------" << endl << endl;
}

// Displays the game menu with options.
void printMenu() {
    cout << endl << endl;
    cout << "Menu Options" << endl
         << "------------" << endl;
    cout << "1) Play rock, paper, scissors" << endl;
    cout << "2) Play rock, paper, scissors, lizard, spock" << endl;
    cout << "3) Quit" << endl << endl;
    cout << "Choice --> ";
}

// Displays an error message based on the error number.
void printErrorMessage(int errorNumber) {
    if (errorNumber == 1) {
        cout << endl << "ERROR: Illegal name given, using default" << endl;
    } else if (errorNumber == 2) {
        cout << endl << "ERROR: Illegal move given, using default";
    } else {
        // This line is for unexpected errors, should ideally never print.
        cout << "This should never print!";
    }
}

// Prints a closing message thanking the players for playing.
void printCloser() {
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "           Thanks for playing           " << endl;
    cout << "          Rock-Paper-Scissors!          " << endl;
    cout << "----------------------------------------" << endl << endl;
}