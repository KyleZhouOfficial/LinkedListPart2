/*
Kyle Zhou
This is my 2 player TicTacToe game
10/10/21
 */
#include <iostream>
#include <cstring>

using namespace std;


void resetBoard(int board[3][3]){
  //reset board by setting all indcies to 0
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      board[i][j] = 0;
    }
  }
}


void printBoard(int board[3][3]){
  //print columns with tabs
  cout << " \t1\t2\t3" << endl;
  // print a b c
  for(int i = 0; i < 3; i++){
    cout << (char)('a' + i);
    // for every row print out the board state
    for(int j = 0; j < 3;j++){
      if(board[i][j] == 0){
	cout << "\t";
      } else if(board[i][j] == 1){
	cout << "\tX";
      } else {
	cout << "\tO";
      }
    }
    cout << endl;
  }
}


bool checkTie(int board[3][3]){
  //if the board is full then return true else false
  for(int i = 0; i < 3; i++){
    for(int j = 0 ; j < 3; j++){
      if(board[i][j] == 0){
	return false;
      }
    }
  }
  return true;
}


bool checkWin(int player, int board[3][3]){
  //if( player has a row
  for(int i = 0; i < 3; i++){
    bool isRowSame = true;
    for(int j = 0; j < 3; j++){
      if(board[i][j] != player) isRowSame = false;
    }
    if(isRowSame) return true;
  }

  //if player wins a column
  for(int i = 0; i < 3; i++){
    bool isColumnSame = true;
    for(int j = 0; j < 3; j++){
      if(board[j][i] != player) isColumnSame = false;
    }
    if(isColumnSame) return true;
  }

  //if player wins a diagnol
  bool isDiag = true;
  for(int i = 0; i < 3; i++){
    if(board[i][i] != player) isDiag = false;
  }
  if(isDiag) return true;

  isDiag = true;
  for(int i = 0; i < 3; i++){
    if(board[i][2-i] != player) isDiag = false;
  }
  if(isDiag) return true;


  return false;
}


bool getInput(int board[3][3], bool isXMove){
  char row1;
  int row;
  int column;
  //read in char and int
  cin >> row1 >> column;
  //row number
  row = row1 - 'a';
  //column number in zero-based
  column--;

  //if input within board and the space is empty then put the corresponding players move
  if(row >= 0 && row < 3 && column >= 0 && column < 3 && board[row][column] == 0){
    board[row][column] = isXMove ? 1 : 2;
    return true;
  } else{
    return false;
  }
}

int main(){
  //variables
  int winsX = 0;
  int winsY = 0;
  int board[3][3];
  bool isXMove = true;
  bool keepGoing = false;
  //reset board
  resetBoard(board);
  //keep playing game
  while(true){
    //if not tie or win keep going
    while(!checkWin(1, board) && !checkWin(2, board) && !checkTie(board)){
      printBoard(board);
      cout << "Enter a coordinate" << endl;
      //keep reading input if not legal
      while(!keepGoing){
	keepGoing = getInput(board, isXMove);
      }
      //change player turn
      isXMove = !isXMove;
      keepGoing = false;
    }
    //print messages to player
    if(checkTie(board)){
      cout << "Tie!" << endl << "X wins: " << winsX << " Y wins: " << winsY << endl;
    }
    if(checkWin(1, board)){
      winsX++;
      cout << "X wins!" << endl << "X wins: " << winsX << " Y wins: " << winsY << endl;;
    }
    if(checkWin(2, board)){
      winsY++;
      cout << "Y wins!" << endl << "X wins: " << winsX << " Y wins: " << winsY << endl;;
    }
    //reset after game ends
    resetBoard(board);

  }

  return 0;

}
