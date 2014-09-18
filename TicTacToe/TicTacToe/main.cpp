#include <iostream> 
#include <cmath> 
#include <cstdlib>
#include "tictactoe.h"

using namespace std;
const int BOARD_SIZE = 3;

int main(int argc, char* argv[]) {
	//initial print out of board
	int board[BOARD_SIZE][BOARD_SIZE] = {0};
	PrintBoard(board);
	int row = 0, col = 0;

	for(int i = 1; i < 9; i++) {

		//2. Ask for move 
		if(i%2 == 1)
			cout<<"X's turn: ";
		else
			cout<<"O's turn: ";
		GetMove(&row, &col);

		//3. Verify the move, update if valid, ask again if not.
		if(MoveIsValid(board, row, col)) {
			if(i%2 == 1)
				board[row][col] = 1;
			else
				board[row][col] = -1;
			PrintBoard(board);
		}
		else {
			cout<<"Can't go there! Pick somewhere else please."<<endl;
			i--;
		}
	}
}

//Print out the first line, then nested loop to print out each board spot, leading 
// with the counter for each row.
void PrintBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
	cout<<"- 0 1 2"<<endl;

	for(int i = 0; i < BOARD_SIZE; i++) { 
		cout<<i;

		for(int k = 0; k < BOARD_SIZE;k++) {
			if(board[i][k] == -1)
				cout<<" O";
			else if(board[i][k] == 0)
				cout<<" .";
			else if(board[i][k] == 1)
				cout<<" X"; 
		}

		cout<<endl;
	}

	cout<<endl;
}

//Create a junke variable for comma, like suggested, get input from user. win.
void GetMove(int *row, int *col) {
	char junk = '.';
	cin>>*row>>junk>>*col;
	cout<<endl;
}

//checks all invalid input errors, returns true if move is fine, false if not.
bool MoveIsValid(int board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
	if(board[row][col] != 0 || row > 3 || row < 0 || col > 3 || col < 0)
		return false;
	else
		return true;
}