//Lab MP3 Madalynn Schwanekamp
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;
int getPlayerInput(string playerName);
//returns value between 1 and 9. uses name of player and checks for correct input
bool isLegalMove(char board[], int location);
// returns true if mark on board has not been played on yet
void placeMarkOnBoard(char board[], char playerMard, int location);
// places indicated mark at board location
void clearBoard(char board[]);
// restores board to blank original
bool hasThreeInRow (char board[], char playerMark);
//returns true if the board shows three of the same marks in a row
void displayBoard(char board[]);
//prints our current board
void displayGameStats(int ties, int player1Score, int player2Score);
// prints out stats for all games. number tied, number each player has won