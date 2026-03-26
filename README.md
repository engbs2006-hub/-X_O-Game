# Tic Tac Toe

## Project Overview
Tic Tac Toe is a classic two-player game where players take turns marking a square in a 3x3 grid. The first player to get three of their marks in a row - vertically, horizontally, or diagonally - wins the game.

## Features
- Two-player gameplay: Play against another player.
- Clear and simple user interface.
- Support for different winning conditions.

## Compilation Instructions
1. Ensure you have a C++ compiler installed on your machine.
2. Download the source code from the repository.
3. Open a terminal and navigate to the project directory.
4. Compile the code using the command: `g++ -o tic_tac_toe main.cpp`
5. Run the game with the command: `./tic_tac_toe`

## Game Rules
1. The game is played on a 3x3 grid.
2. Players take turns placing their markers (X and O) in the empty squares.
3. The first player to place three markers in a row (vertically, horizontally, or diagonally) wins.
4. If all squares are filled and there is no winner, the game ends in a draw.

## Function Documentation
- `void displayBoard()`: Displays the current state of the board.
- `bool checkWin()`: Checks if there is a winner.
- `bool checkDraw()`: Checks if the game is a draw.
- `void makeMove(int player)`: Allows a player to make a move on the board.

## Changelog
- **2026-03-26**: Updated README with full documentation.