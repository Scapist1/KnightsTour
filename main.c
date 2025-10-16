#include <stdbool.h>
#include <stdio.h>

#define SIZE 8
void generate_and_print_a_board(unsigned int w, unsigned h) {

  for (unsigned int row = 0; row < h; ++row) {
    for (unsigned int col = 0; col < w; ++col)
      printf("%d%d ", row, col);
    puts("");
  }
}

#define MOVE_COUNT 8 /**< Number of moves that a knight can make */
const int MOVES_X[MOVE_COUNT] = {2, 1, -1, -2, -2, -1, 1, 2};
const int MOVES_Y[MOVE_COUNT] = {1, 2, 2, 1, -1, -2, -2, -1};

bool make_a_move(size_t move_id, size_t x, size_t y, bool board[SIZE][SIZE]) {
  // accessibility check
  x += MOVES_X[move_id];
  y += MOVES_Y[move_id];
  if (x < SIZE && y < SIZE && board[x][y] == false) {
    board[x][y] = true;
    return true;
  }
  return false;
}

unsigned int tour_greedy(size_t start_x, size_t start_y) {
  bool board[SIZE][SIZE] = {};
  size_t x = start_x, y = start_y;
  board[x][y] = true; // mark the starting square as visited
  unsigned int moves_made = 1;

  while (1) {
    int min_onward = MOVE_COUNT + 1;
    int next_move = -1;
    size_t next_x = 0, next_y = 0;

    for (int i = 0; i < MOVE_COUNT; ++i) {
      size_t nx = x + MOVES_X[i];
      size_t ny = y + MOVES_Y[i];
      if (nx >= SIZE || ny >= SIZE || board[nx][ny])
        continue;

      // Count onward moves from this candidate
      int onward = 0;
      for (int j = 0; j < MOVE_COUNT; ++j) {
        size_t nnx = nx + MOVES_X[j];
        size_t nny = ny + MOVES_Y[j];
        if (nnx < SIZE && nny < SIZE && !board[nnx][nny])
          ++onward;
      }

      if (onward < min_onward) {
        min_onward = onward;
        next_move = i;
        next_x = nx;
        next_y = ny;
      }
    }

    if (next_move == -1)
      break; // no more moves

    // Move to the chosen square
    x = next_x;
    y = next_y;
    board[x][y] = true;
    ++moves_made;
  }

  return moves_made;
}

int main() { generate_and_print_a_board(SIZE, SIZE); }
