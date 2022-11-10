//Lab MP3 Madalynn Schwanekamp
#include <iostream>
#include <string>

using namespace std;

void displayBoard(char board[]);
bool isLegalMove(char board[], int location);
bool hasThreeInRow(char board[], char playerMark);
int getPlayerInput(string playerName);
void placeMarkOnBoard(char board[], char playerMark, int location);
void clearBoard(char board[]);
void displayGameStats(int ties, int player1Score, int player2Score);

char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

string player_1Name;
string player_2Name;

int row;
int col;
char playerMark = 'x';
bool tie = false;


int main() {
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int row;
    int col;
    char playerMark = 'x';
    bool tie = false;
    string player1_answer;
    string player2_answer;
    string playerName;
    int location;
    int p1Score;
    int p2Score;

    cout << "Enter player 1 name: ";
    cin >> player_1Name;
    cout << "Does Player 1 want to play? ";
    cin >> player1_answer;
    cout << "Enter player 2 name: ";
    cin >> player_2Name;
    cout << "Does Player 2 want to play? ";
    cin >> player2_answer;

    if (player1_answer == "yes" && player2_answer == "yes") {
        do {
            displayBoard(board);
            cout << player_1Name << " goes first.n";
            getPlayerInput(player_1Name);
            if (isLegalMove(board, playerMark) == true) {
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
                    placeMarkOnBoard(board, playerMark, location);
                }
                displayBoard(board);
            }
        }while (hasThreeInRow(board, playerMark) != true);
        if (hasThreeInRow(board, playerMark) == true) {
            displayGameStats(tie, p1Score, p2Score);
            cout << playerName << " wins!" << endl;
            clearBoard(board);
        }
        
    }
    else return 0;


}

void displayGameStats(int ties, int player1Score, int player2Score) {
    int p1Score;
    int p2Score;
    string player_1Name;
    string player_2Name;
    bool tie = false;
    if (playerMark == 'x' && tie == false) {
        p2Score++;
    }
    if (playerMark == '0' && tie == false) {
        p1Score++;
    }
    cout << player_1Name << " has " << p1Score << "wins." << endl;
    cout << player_2Name << " has " << p2Score << "wins." << endl;
}

void displayBoard(char board[]) {

//output of the game board

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

void placeMarkOnBoard(char board[], char playerMark, int location) {

    string player_1Name;
    string player_2Name;

    if (playerMark == 'x') {
        cout << player_1Name << "Please enter";
        cin >> location;
    }

    if (playerMark == '0') {
        cout << player_2Name << "Please enter";
        cin >> location;
    }


    if (location == 1) {
        row = 0;
        col = 0;
    }

    if (location == 2) {
        row = 0;
        col = 1;
    }

    if (location == 3) {
        row = 0;
        col = 2;
    }
    if (location == 4) {
        row = 1;
        col = 0;
    }
    if (location == 5) {
        row = 1;
        col = 1;
    }
    if (location == 6) {
        row = 1;
        col= 2;
    }
    if (location == 7) {
        row = 2;
        col = 0;
    }
    if (location == 8) {
        row = 2;
        col = 1;
    }
    if (location == 9) {
        row = 2;
        col = 2;
    }
}

bool hasThreeInRow(char board[], char playerMark) {
    int tie = true;
    for (int i = 0; i < 3; i++) {
        if (board[0] == board[1] && board[0] == board[2] || board[0] == board[1] && board[0] == board[2]) {
            return true;
        }
        if (board[0] == board[1] && board[1] == board[2] || board[0] == board[1] && board[1] == board[2]) {
            return true;
        }

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

bool isLegalMove(char board[], int location) {
    if (playerMark == 'x' && board[row] != 'x' && board[row] != '0') {
        return true;
    }
    else if (playerMark == '0' && board[row] != 'x' && board[row] != '0') {
        return true;
    }
    else {
        return false;
    }
}

int getPlayerInput(string playerName) {
    int num;
    do {
        cout << playerName << " enter a number 1-9: ";

        cin >> num;
        if (num >= 1 && num <= 9) {
            return num;
        }
    }while(true);
    
    
}

void clearBoard(char board[]) {

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
