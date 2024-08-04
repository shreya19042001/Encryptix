#include <bits/stdc++.h>

using namespace std;

char board[3][3];
char currentPlayer;
bool gameOngoing;

void initializeBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X';
    gameOngoing = true;
}

void displayBoard() {
cout << "TIC-TAC-TOE GAME\n";
    cout << "Current board state:\n";
    cout << "  0 1 2\n";
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "  -----\n";
    }
}

bool isValidMove(int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

void makeMove(int row, int col) {
    if (isValidMove(row, col)) {
        board[row][col] = currentPlayer;
    } else {
        throw invalid_argument("Invalid move! Position already taken or out of bounds.");
    }
}

bool checkWin() {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true;
        }
    }
    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true;
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true;
    }
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playGame() {
    int row, col;
    while (gameOngoing) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        
        try {
            makeMove(row, col);
            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                gameOngoing = false;
            } else if (checkDraw()) {
                displayBoard();
                cout << "The game is a draw!\n";
                gameOngoing = false;
            } else {
                switchPlayer();
            }
        } catch (const invalid_argument& e) {
            cout << e.what() << "\n";
        }
    }
}

bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

int main() {
    do {
        initializeBoard();
        playGame();
    } while (playAgain());
    
    cout << "Thank you for playing!\n";
    return 0;
}
