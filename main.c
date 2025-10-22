#include <stdio.h>

/* Chessboard size */
#define SIZE 8

/* All 8 Knight moves */
const signed int MOVES_X[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const signed int MOVES_Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int countMoves[SIZE][SIZE] = {0}; // initialize to zero
int possibleBoard[SIZE][SIZE][8] = {0};

int findSteps(int countMoves[SIZE][SIZE], int possibleBoard[SIZE][SIZE][8]) {

  // Initialize move counts to 0
  for (size_t x = 0; x < SIZE; ++x) {
    for (size_t y = 0; y < SIZE; ++y) {
      countMoves[x][y] = 0;
    }
  }

  /* Precompute all possible moves for each square */
  for (size_t x = 0; x < SIZE; ++x) {
    for (size_t y = 0; y < SIZE; ++y) {
      for (size_t xy = 0; xy < 8; ++xy) {
        if (x + MOVES_X[xy] >= 0 && x + MOVES_X[xy] < SIZE &&
            y + MOVES_Y[xy] >= 0 && y + MOVES_Y[xy] < SIZE) {
          int counter = countMoves[x][y];
          possibleBoard[x][y][counter] = xy;
          countMoves[x][y]++;
        }
      }
    }
  }
  return 0;
}

int solveKnightsTour(int x, int y, int moveCount, int board[SIZE][SIZE]) {
  if (moveCount == SIZE * SIZE)
    /* Solution found! Succeeded */
    return 1;

  for (int xy = 0; xy < countMoves[x][y]; xy++) {

    /* Compoute new X & Y positions using solutionBoard */
    int move = possibleBoard[x][y][xy];
    int nextX = x + MOVES_X[move];
    int nextY = y + MOVES_Y[move];

    /* Check if new square is valid and unvisited */
    if (nextX >= 0 && nextY >= 0 && nextX < SIZE && nextY < SIZE &&
        board[nextX][nextY] == -1) {

      /* Mark the square as visited with move number */
      board[nextX][nextY] = moveCount + 1;

      /* Recurse to continue tour frow new square; return 1 if full tour found
       */
      if (solveKnightsTour(nextX, nextY, moveCount + 1, board))
        return 1;
      else
        /* Undo the move (backtrack) if it failed */
        board[nextX][nextY] = -1;
    }
  }
  /* returns 0 if all loops finnished without a solution found */
  return 0;
}

int main(void) {

  /* Insert board and initialize to 0 */
  int board[SIZE][SIZE];

  /* Initialize all its squares as unvisited */
  for (int x = 0; x < SIZE; x++)
    for (int y = 0; y < SIZE; y++)
      board[x][y] = -1;

  /* Starting position */
  board[0][0] = 1;

  /* Compute all moves */
  findSteps(countMoves, possibleBoard);

  if (solveKnightsTour(0, 0, 1, board) == 1) {
    for (int x = 0; x < SIZE; x++) {
      for (int y = 0; y < SIZE; y++)
        printf("%2d ", board[x][y]);
      puts(" ");
    }

    return 1;

  } else {
    printf("failed");
  }

  return 0;
}
