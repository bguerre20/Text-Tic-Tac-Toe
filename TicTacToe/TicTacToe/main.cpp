#include <iostream> 
#include <cmath> 
#include <cstdlib>
#include "tictactoe.h"

using namespace std;
const int BOARD_SIZE = 3;

int main(int argc, char* argv[]) {
	//1. Print out the board state
	int board[BOARD_SIZE][BOARD_SIZE] = {0};
	PrintBoard(board);
	//2. Ask for move 
	int row = 0, col = 0;
	GetMove(&row, &col);
	//3. Verify the move

	//4. Update the game
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

void GetMove(int *row, int *col) {
	
}

bool MoveIsValid(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
	return true;
}