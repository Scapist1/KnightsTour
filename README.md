# KnightsTour

Pseudocode - Knights Tour Problem Solver

Precompute:
1. Run precomputation to make a list of every possible move from each square on the board

Initialization:
2. Insert board
3. Initialize all its squares as unvisited
4. Set starting position = 0;0


Run Knights Tour finder: 

5. Try each of the 8 moves
6. Compoute new X & Y positions
7. Check if new square is valid and unvisited
8. Mark the square as visited with move number
9. Recurse to continue tour frow new square; return 1 success if full tour found
10. Undo the move (backtrack) if it fails
11. If solved, return = 1 and print board with number path solution
12. If failed, return = 0 and prompt failed attempt
