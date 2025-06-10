## DISCLAIMER: 
This program is intended for educational purposes only.
It is a simple demonstration of basic C programming concepts,

## Snake,Water Game
This C program is a simple implementation of the "Snake, Water, Gun" game — a variation of the classic Rock, Paper, Scissors game, where:
Snake (s) drinks Water (w) → Snake wins
Water (w) disables Gun (g) → Water wins
Gun (g) kills Snake (s) → Gun wins
If both choices are the same, the game is a draw.

Usage:  
To run a C program, you first need to install the GCC compiler, which compiles the .c file into machine code — that is, an executable file.
Download and install MinGW from https://sourceforge.net/projects/mingw/
Add C:\MinGW\bin to your system's Environment Variables → Path.
check gcc --version in powershell
gcc SnakeWaterGame.c -o game.exe
## For e.g:  
PS C:\Users\dell\OneDrive\Desktop\overall\testfolder> ./game.exe  
Enter s for snake, w for water  and g for gun==>>w  
You choose w and computer choose g==>>You win  
PS C:\Users\dell\OneDrive\Desktop\overall\testfolder> ./game.exe  
Enter s for snake, w for water  and g for gun==>>w  
You choose w and computer choose w==>>Game Draw  

## Multiplication table
This C code is a simple program that generates and prints multiplication tables for several numbers

Usage:  
gcc multiplication.c -o multiplication.exe
./multiplication.exe

## Snake and Ladder Game
A two-player console-based Snake and Ladder game.

Usage:  
gcc SnakeLadderGame.c -o SnakeLadderGame.exe
./SnakeLadderGame
