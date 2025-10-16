# KnightsTour

Pseudocode - Knights Tour Problem Solver

Precompute:
1. Run precomputation to make a list of every possible move from each square on the board

Initialization:
2.1 Insert board
2.2 Initialize all its squares as unvisited
2.3 Set starting position = 0;0


Run Knights Tour finder: 

3.1 Try each of the 8 moves
3.2 Compoute new X & Y positions
3.3 Check if new square is valid and unvisited
3.4 Mark the square as visited with move number
3.5 Recurse to continue tour frow new square; return 1 success if full tour found
3.6 Undo the move (backtrack) if it fails
3.7 If solved, return = 1 and print board with number path solution
3.8 If failed, return = 0 and prompt failed attempt
