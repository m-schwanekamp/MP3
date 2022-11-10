//Lab MP3 Madalynn Schwanekamp
//2 player Tic Tac Toe game that keeps track
//of location markers as well as game stats. It 
//can be restored to the original form and played 
//again as well.
#include <iostream>
#include <string>

using namespace std;

int getPlayerInput(string playerName);
//Gets input from each player to place a mark on the board
//Checks for player turn
//@param: input valid 1-9 integers only
//@param: only valid if that space on the board is clear

bool isLegalMove(char board[], int location);
//@param: returns true if location input has not been played yet

void placeMarkOnBoard(char board[], char playerMark, int location);
//updates board to place the current player's mark in 
//in the location indicated

void clearBoard(char board[]);
//Restores board to original form

bool hasThreeInRow(char board[], char playerMark);
//@param: returns true if a player has won the game
//in a horizontal, vertical, or diagonal row

void displayBoard(char board[]);
//Prints ou current board with updated player marks

bool hasTie(char board[]);
//test if the game ends in a tie

void displayGameStats(int ties, int player1Score, int player2Score, string player_1Name, string player_2Name);
//prints stats for game for each player
//includes number of games tied, won and lost
//displays each players name and stats individually

int main() {
    //reference for board array
    char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    
    string player_1Name; //Player name 
    string player_2Name;
    char playerMark = 'x'; //player mark not including '0'
    string player1_answer; //response to playing the game, yes/no
    string player2_answer;
    string playerName;
    int p1Score = 0; //player score
    int p2Score = 0;
    int tie = 0; //number of ties
    int row; //space on board

    //Enter each playr into the game, asking for
    //names and if they want to play
    cout << "Enter player 1 name: ";
    cin >> player_1Name;
    cout << "Does Player 1 want to play? ";
    cin >> player1_answer;
    cout << "Enter player 2 name: ";
    cin >> player_2Name;
    cout << "Does Player 2 want to play? ";
    cin >> player2_answer;

    //Game loop
    if (player1_answer == "yes" && player2_answer == "yes") {
        do {
            displayBoard(board);
            if (playerMark == 'x') { //switches between starting players
                cout << player_1Name << " goes first.\n";
            }
            else cout << player_2Name << " goes first.\n";
            while (hasThreeInRow(board, playerMark) != true && hasTie(board) != true) {
                if (playerMark == 'x') {
                    row = getPlayerInput(player_1Name);
                }
                else row = getPlayerInput(player_2Name);
                if (isLegalMove(board, row) == true) { //tests for if the square can be played
                    if (playerMark == 'x' && board[row] != 'x' && board[row] != '0') {
                        board[row] = 'x';
                        playerMark = '0';
                    }
                    else if (playerMark == '0' && board[row] != 'x' && board[row] != '0') {
                        board[row] = '0';
                        playerMark = 'x';
                    }
                    else {
                        cout << "there is no empty space!" << endl;
                        placeMarkOnBoard(board, playerMark, row);
                    }
                    displayBoard(board);
                }
                
            }
            if (hasThreeInRow(board, playerMark) == true) {
                //displays which player has won the game
                if (playerMark == 'x') {
                    p1Score++;
                    cout << player_1Name << " wins!" << endl;
                }
                else {
                    p2Score++;
                    cout << player_2Name << " wins!" << endl;
                }
                displayGameStats(tie, p1Score, p2Score, player_1Name, player_2Name);
                
                clearBoard(board);
            }
            else if (hasTie(board) == true) { //displays if the game ends in a tie
                tie++;
                cout << " Tied Game." << endl;
                displayGameStats(tie, p1Score, p2Score, player_1Name, player_2Name);
                clearBoard(board);
            }
            //asks players if they would like to play again
            cout << "Player 1, play again?";
            cin >> player1_answer;
            cout << "Player 2, play again?";
            cin >> player2_answer;
            
        } while (player1_answer == "yes" && player2_answer == "yes");
    }
    else return 0;
}

//boolean test for tie
bool hasTie(char board[]) {
    int tie = true;
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'x' && board[i] != '0') {
            return false;
        }
    }
    return true;
}
//displays game stats
void displayGameStats(int ties, int player1Score, int player2Score, string player_1Name, string player_2Name) {
    cout << player_1Name << " has " << player1Score << "wins." << endl;
    cout << player_2Name << " has " << player2Score << "wins." << endl;
    cout << ties << " Ties." << endl;
}

//displays current updated board
void displayBoard(char board[]) {
    cout << "    |    |    \n";
    cout << "  " << board[0] << " |  " << board[1] << " |  " << board[2] << "    \n";
    cout << "____|____|____\n";
    cout << "    |    |    \n";
    cout << "  " << board[3] << " |  " << board[4] << " |  " << board[5] << "    \n";
    cout << "____|____|____\n";
    cout << "    |    |    \n";
    cout << "  " << board[6] << " |  " << board[7] << " |  " << board[8] << "    \n";
    cout << "    |    |    \n";
}

//places each player's mark on board
void placeMarkOnBoard(char board[], char playerMark, int location) {
    string player_1Name;
    string player_2Name;

    if (playerMark == 'x') { //changes square to player 1 mark
        cout << player_1Name << "Please enter";
        cin >> location;
        if (location == 1) {
            board[0] = 'x';
        }
        if (location == 2) {
            board[1] = 'x';
        }
        if (location == 3) {
            board[2] = 'x';
        }
        if (location == 4) {
            board[3] = 'x';
        }
        if (location == 5) {
            board[4] = 'x';
        }
        if (location == 6) {
            board[5] = 'x';
        }
        if (location == 7) {
            board[6] = 'x';
        }
        if (location == 8) {
            board[7] = 'x';
        }
        if (location == 9) {
            board[8] = 'x';
        }
    }
    if (playerMark == '0') { //changes square to player 2 mark
        cout << player_2Name << "Please enter";
        cin >> location;
        if (location == 1) {
            board[0] = '0';
        }
        if (location == 2) {
            board[1] = '0';
        }
        if (location == 3) {
            board[2] = '0';
        }
        if (location == 4) {
            board[3] = '0';
        }
        if (location == 5) {
            board[4] = '0';
        }
        if (location == 6) {
            board[5] = '0';
        }
        if (location == 7) {
            board[6] = '0';
        }
        if (location == 8) {
            board[7] = '0';
        }
        if (location == 9) {
            board[8] = '0';
        }
    }
}

//boolean test for three in a row
//compares squares to test if a row of them are the same
bool hasThreeInRow(char board[], char playerMark) {
    int tie = true; //tests for tie
    for (int i = 0; i < 3; i++) {
        if (board[0] == board[1] && board[1] == board[2] || board[3] == board[4] && board[4] == board[5]
             || board[6] == board[7] && board[7] == board[8]) {
            return true;
        }
        if (board[0] == board[3] && board[3] == board[6] || board[1] == board[4] && board[4] == board[7] 
            || board[2] == board[5] && board[5] == board[8]) {
            return true;
        }
        if (board[0] == board[4] && board[4] == board[8] || board[2] == board[4] && board[4] == board[6]) {
            return true;
        }
        //test for tie if board is completely filled
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i] != 'x' && board[i] != '0') {
                    return false;
                }
            }
        }
    }
    tie = true;
    return false;
}

//boolean test for legal move
bool isLegalMove(char board[], int location) {
    if (board[location] != 'x' && board[location] != '0') {
        return true;
    }
    else {
        return false;
    }
}

//receives player input 1-9
int getPlayerInput(string playerName) {
    int num; //player input
    do {
        cout << playerName << " enter a number 1-9: ";

        cin >> num;
        if (num >= 1 && num <= 9) {
            return num - 1;
        }
    } while (true);
}

//restores board to original when game is won
void clearBoard(char board[]) {
    for (int i = 0; i < 9; i++) {
        board[i] = i + 49;
   }
}
