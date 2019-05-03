/******************************
 * Filename: GPACalc.c
 * Author: Blakely North
 * Date Last Edited: 1-22-2019
 * Brief Description: A sample and standard new file
   gcc -Wall -Wextra -O -ansi -pedantic -o GPACalc GPACalc.c
 ******************************/
//printf, scanf
#include <stdio.h>
//rand, srand
#include <stdlib.h>
//time
#include <time.h>
//strcat, strcpy etc.
#include <string.h>
//Board width
#define WIDTH 7
//Board height
#define HEIGHT 6

//prints the board (duh)
int printBoard();
//Returns an int between 1 and 7 based on what the player's move was. Also checks if it is a valid move
int playerTurn();
//Reurns 1 for player X (one), 2 for player O (two), 0 for draw, and -1 when nobody has won yet
int whoWon();
//Game loop
int gameloop();
//Check the move and add it to the board
int move();

/* board checkers */
int Horizontal();
int Vertical();
int DiagonalRight(); /* (\) */
int DiagonalLeft();  /* (/) */

//player input
int input;
//player input row - set by move() and used to process in whoWon()
int row;
//game board
char board[WIDTH][HEIGHT] = {{' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '}};
//To exit or not to exit
//int exit = 0;
//Who's turn is it? 1 = X, 2 = O
int currentPlayerTurn = 2;
char chcurrentPlayerTurn = 'O';
//Game loop
int gameloop()
{
  if (currentPlayerTurn == 1)
    currentPlayerTurn = 2, chcurrentPlayerTurn = 'O';
  else if (currentPlayerTurn == 2)
    currentPlayerTurn = 1, chcurrentPlayerTurn = 'X';

  printBoard();
  playerTurn();
  return whoWon();
}
//                                                  1 2 3 4 5 6 7
//
//
//
//
//
//
//prints the board (duh)
int printBoard()
{
  //Counters
  int i, j;

  for (i = 48; i - 48 < WIDTH; putchar(++i), putchar(' '))
    ;
  putchar('\n');
  for (i = 0; i < HEIGHT; ++i, putchar('\n'))
    for (j = 0; j < (WIDTH); ++j)
      putchar(board[j][i]), putchar('|');
  return 0;
}

//Returns an int between 1 and 7 based on what the player's move was. Also checks if it is a valid move
int playerTurn()
{
  input = -3;
  while (move() == 0)
    puts("Invalid move");
  return 0;
}

int move()
{
  //Counters
  int i;

  int pos = 0;
  puts("Where do you want to play?");
  input = getchar();
  while (!(input > '0' && input <= '7'))
    input = getchar();

  pos = input - '1';
  for (i = HEIGHT - 1; i >= 0; --i)
  {
    //Check if there is a blank beneath this space
    if (board[pos][i] == ' ')
    {
      board[pos][i] = chcurrentPlayerTurn;
      return 1;
    }
  }
  return 0;
}

//Reurns 1 for player X (one), 2 for player O (two), 0 for draw, and -1 when nobody has won yet
int whoWon()
{
  if (Horizontal() || Vertical() || DiagonalRight() || DiagonalLeft())
    return currentPlayerTurn;
  else
    return -1;
}

/* Checks what it says for 2 in a rows */
int Horizontal()
{
  //Counters
  int x, y;

  int count = 0;
  /* Check for 4 plays in a row */
  for (y = 0; y < HEIGHT; ++y)
    for (count = 0, x = 0; x + 1 < WIDTH; ++x)
    {
      if (board[x][y] == board[x + 1][y] && (board[x][y] == 'O' || board[x][y] == 'X'))
        ++count;
      if (count == 3)
        return 1;
    }
  return 0;
}

/* Checks what it says for 2 in a rows */
int Vertical()
{
  //Counters
  int x, y;

  int count = 0;
  /* Check for 4 plays in a row */
  for (x = 0; x < WIDTH; ++x)
    for (count = 0, y = 1; y < HEIGHT; ++y)
    {
      if (board[x][y] == board[x][y - 1] && (board[x][y] == 'O' || board[x][y] == 'X'))
        ++count;
      if (count == 3)
        return 1;
    }
  return 0;
}
/* Checks what it says for 2 in a rows */
int DiagonalRight()
{
  //Counters
  int i, x, y;

  int count = 0;
  /* Check for 4 plays in a row */
  for (x = 0; x < WIDTH; ++x)
    for (y = 0; y < HEIGHT; ++y)
      for (count = 0, i = 1; i < 4 && x + i < WIDTH && y + i < HEIGHT; ++i)
      {
        if (board[x][y] == board[x + i][y + i] && (board[x][y] == 'O' || board[x][y] == 'X'))
          ++count;
        if (count == 3)
          return 1;
      }
  return 0;
}

/* Checks what it says for 2 in a rows */
int DiagonalLeft()
{
  //Counters
  int i, x, y;

  int count = 0;
  /* Check for 4 plays in a row */
  for (x = WIDTH - 1; x >= 0; --x)
    for (y = 0; y < HEIGHT; ++y)
      for (count = 0, i = 1; i < 4 && x - i < WIDTH && y + i < HEIGHT; ++i)
      {
        if (board[x][y] == board[x - i][y + i] && (board[x][y] == 'O' || board[x][y] == 'X'))
          ++count;
        if (count == 3)
          return 1;
      }
  return 0;
}

int main(void)
{
  puts("Welcome to Connect 4!\nPress enter to start");
  while (getchar() != '\n')
    ;
  putchar('\n');
  //keep going until there is a winner
  while (gameloop() == -1)
    ;
  printBoard();
  printf("Player %c wins!\nPress enter to exit.", chcurrentPlayerTurn);
  while (getchar() != '\n')
    ;
  putchar('\n');
  return currentPlayerTurn;
}