# Sudoku-Solver
Sudoku solver program using the backtracking algorithm in C++

Sudoku Solver 

Abdulhadi Sultan Qureshi (20100065), Abdullah Shamail (20100024)


Problem description:

We had to create a program that could solve Sudoku puzzles. The user had to input a puzzle grid, which the program had to solve. The values entered in these grids had to be checked for legality (i.e. whether or not their placement broke any Sudoku rules), for this we had to apply a number of checks; to check if there was another equivalent value in the row, column or 3x3 box. If there was another value equal to the one entered in these checks, then value we entered was not correct and had to be changed. The goal was to find a solution in which none of the values failed any of these checks. Another goal was to solve the grids as soon as possible (which we achieved as our program solves these puzzles almost instantly).
As part of the extra work, we had to further develop the program so that it created its own random puzzles with 3 different difficulties (Easy which had 32 filled boxes, Medium which had 27 and Hard which had 22). These grids had to have a solution and the program had to be capable enough to solve them after creating them.


Problem handling:

The program employed a backtracking algorithm to solve these puzzles. To do this it looked up the first empty box in the grid and entered a value (1) and then checked the value for legality, if it was not legal, the value was incremented and checked for legality again. If the value in that position was legal, the program moved to the next empty box and checked the value for legality again. If the value went over 9, the program went back to the last box it had filled and increased the present value since it lead to a dead end. The program went back and forth until the last empty box was filled with a legal value, solving the puzzle. More details on the algorithm: https://en.wikipedia.org/wiki/Sudoku_solving_algorithms#Backtracking
To create random grid, the rand command was used to find a random row, column and value. The value was checked for legality. These values were placed until the number of boxes filled corresponded to the difficulty level. The grid was then checked to see if it was solvable, and if it wasn’t, then a new grid was made and checked again (till a solvable grid was made).


Future improvements:

Many improvements that could’ve been proposed for this program have already been implemented e.g. a few checks so that the row and column numbers entered by the user were not out of bounds and allowing non-case sensitive entry.
 However, there are still a few improvements that could be proposed. Since the current method for the user to enter the grid is tedious and slow since the user has to enter a lot of data to fill the grid, which could lead to some sort of human error during data entry (the error although can be undone quite easily by entering a 0 in the position where the erroneous value was entered, a better, more efficient way for the user entering the grid could be implemented e.g. labeling the grid so that it is easier for the user to understand the exact position of where the data is being entered and allowing the user to enter all the data of all values in one go to make the process of data entry faster. 
Another improvement could be to come up with a better and more efficient algorithm for creating random grids, eliminating the few seconds that it takes to create them.
