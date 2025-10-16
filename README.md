# KnightsTour

Pseudocode - Knights Tour Problem Solver

/* Precompute all possible moves for each square */
/* Run precomputation to make a list of every possible move from each square on the board */

/* Insert board */
/* Initialize all its squares as unvisited */
/* Set starting position = 0;0 */

/* Run tour finder first time with initialized values */

/* Try each of the 8 moves */
/* Compoute new X & Y positions */
/* Check if new square is valid and unvisited */
/* Mark the square as visited with move number */
/* Recurse to continue tour frow new square; return 1 success if full tour found */
/* Undo the move (backtrack) if it fails */
/* If solved, return = 1 and print board with number path solution */
/* else failed, return = 0 and prompt failed attempt */
