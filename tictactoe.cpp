#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';

void drawBoard() {
    
    cout << "Player 1 (X) - Player 2 (O)\n\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
    cout << "     |     |     \n\n";
}

bool placeMarker(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    
    // Check if row and column values are within the bounds of the board
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        // Out of bounds position
        return false;
    }

    if (board[row][col] != 'X' && board[row][col] != 'O' && board[row][col] != ' ') {
        board[row][col] = currentPlayer;
        return true;
    } else {
        return false;
    }
}

void switchPlayer() {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}

bool checkWin() {
	
	
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }

    // check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }

    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    
    return false;
}

bool checkTie(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                // There's still an empty cell on the board, so the game is not tied
                return false;
            }
        }
    }
    
    // All cells are filled and there's no winner, so the game is tied
    return true;
}


int main() {
    int position;
    
	cout << "Tic Tac Toe\n";
	
    drawBoard();
    

    while (true) 
	{
        // get player input
        cout << "Player " << currentPlayer << ", choose a position (1-9): ";
        cin >> position;

        // place marker and switch player
        if (placeMarker(position)) 
		{
            drawBoard();
            
            if (checkTie(board)) {
            	cout << "Game is tied!" << endl;
            	break;
        	}
        
            if (checkWin())
			{
				cout << "Player " << currentPlayer << " wins!" << endl;
	            break;
	        }
            	switchPlayer();
		}
		else
		{	
	        	cout << "Invalid move. Try again.";
		}
	}
		  


return 0;
}
