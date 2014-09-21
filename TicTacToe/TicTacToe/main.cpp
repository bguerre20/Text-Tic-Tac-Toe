#include <iostream> 
#include <cmath> 
#include <cstdlib>
#include "tictactoe.h"

using namespace std;
const int BOARD_SIZE = 3;
const int ALL_POSSIBLE_MOVES = 9;

int main(int argc, char* argv[]) {
   //initial print out of board
   char board[BOARD_SIZE][BOARD_SIZE] = {
      {0,0,0},
      {0,0,0},
      {0,0,0}
   };
   PrintBoard(board);
   int row = 0, col = 0;

   //Game loop for 9 turns as instructed by the project parameters.
   for(int i = 1; i < ALL_POSSIBLE_MOVES + 1; i++) {
      if (checkForWinner(board) == 1) {
         cout<<"X WINS!!!"<<endl;
         break;
      }
      else if (checkForWinner(board) == -1) {
         cout<<"O WINS!!!"<<endl;
         break;
      }
      else {
         //2. Ask for move, use mod to determine who's move it is.
         if (i % 2 == 1)
            cout<<"X's turn: ";
         else
            cout<<"O's turn: ";
         GetMove(&row, &col);

         //3. Verify the move, update if valid, ask again if not.
         if (!MoveIsValid(board, row, col)) {
            if (i % 2 == 1)
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
}

//

void PrintBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
   cout<<"- 0 1 2"<<endl;

   for(int i = 0; i < BOARD_SIZE; i++) { 
      cout<<i;

      for(int k = 0; k < BOARD_SIZE;k++) {
         if (board[i][k] == -1)
            cout<<" O";
         else if (board[i][k] == 0)
            cout<<" .";
         else if (board[i][k] == 1)
            cout<<" X"; 
      }

      cout<<endl;
   }

   cout<<endl;
}

//Create a junke variable for comma, like suggested, get input from user. 
// win.
void GetMove(int *row, int *col) {
   char junk = '.';
   cin>>*row>>junk>>*col;
   cout<<endl;
}

//checks all invalid input errors, returns true if move is fine, false if
// not.
bool MoveIsValid(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
   return((board[row][col] == 1) || (board[row][col] == -1) || row > 3 || row < 0 || col > 3 || col < 0);
}

int checkForWinner(char board[BOARD_SIZE][BOARD_SIZE]) {
   int winR = 0, winC = 0, winD1 = 0, winD2 = 0;

   //check rows... and Col?
   for(int r = 0; r < BOARD_SIZE; r++) {
      winR = 0, winC = 0;
      for(int c = 0; c < BOARD_SIZE; c++) { 
         winR += board[r][c];
         winC += board[c][r];
      }
      if (winR == 3 || winC == 3)
         return 1;
      else if (winR == -3 || winC == -3)
         return -1;

   }
   //check diag1
   for(int d1 = 0; d1 < BOARD_SIZE; d1++) {
      winD1 += board[d1][d1];
   }
   //check for diag2
   int d3 = 0;
   for(int d2 = 2; d2 > -1; d2--) {
      winD2 += board[d2][d3];
      d3++;
   }


   if (winD1 == 3 || winD2 == 3) 
      return 1;
   else if (winD1 == -3 || winD2 == -3) 
      return -1;
   else
      return 0;
}