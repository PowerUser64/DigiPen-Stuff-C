/***********************************
TicTacToe.c
10/1/18
Programmed By: The Masked Programmer and (insert name here)
Brief: A Tic Tac Toe game with some missing components to be fixed.
gcc -Wall -Wextra -ansi -pedantic -O -o TicTacToe TicTacToe.c
***********************************/
/*printf scanf*/
#include <stdio.h>

/*function prototypes*/
/*function will need to look at the grid and determine if there is a winner or if it is a tie*/
int CheckGrid(int Grid[][3]);
/*print out the board for the players*/
void printBoard(int Grid[][3]);

/*contains main game loop and player input runs other functions*/
int main(void)
{
	/*2D array for our grid, 3x3*/
	int Grid[3][3] = {{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
	/* 0 is for O 1 is for X*/
	int playerTurn = 1;
	int input;
	int gameState = CheckGrid(Grid);
	printf("Welcome to Tic Tac Toe!\nTake turns with another player chosing places.\n");

	while(gameState == -1)
	{
		/*display board with numbers*/
		printBoard(Grid);
		if(playerTurn == 1)
		{
			printf("Player X's Turn, select your position:\n");
		}
		else
		{
			printf("Player O's Turn, select your position:\n");
		}
		/*Get input from the current player*/
		while(1)
		{
			scanf(" %i", &input);
			if(input >= 0 && input < 9 && Grid[input/3][input%3] == -1)
			{
				/*legal input found*/
				Grid[input/3][input%3] = playerTurn;
				break;
			}
			printf("Invalid Input\n");
			while(getchar() != '\n');
		}
		/*change playerturn*/
		if(playerTurn)
		{
			playerTurn = 0;
		}
		else
		{
			playerTurn = 1;
		}
		gameState = CheckGrid(Grid);
	}
	printBoard(Grid);
	/*determine winner*/
	switch(gameState)
	{
		case 0:
		printf("Player O Wins!\n");
		break;
		case 1:
		printf("Player X Wins!\n");
		break;
		case 2:
		printf("Tie!\n");
		break;
	}
	return 0;
}

/*function will need to look at the grid and determine if there is a winner or if it is a tie*/
int CheckGrid(int Grid[3][3])
{
	int i, j;

	/*horizontal loop through all on one row*/
	for(i = 0; i < 3; i++)
	{
		if(Grid[i][0] != -1 && Grid[i][0] == Grid[i][1] && Grid[i][1] == Grid[i][2])
		{
			return Grid[i][0];
		}
	}

	/*verticle loop through all on one column*/
	for(j = 0; j < 3; j++)
	{
		if(Grid[0][j] != -1 && Grid[0][j] == Grid[1][j] && Grid[1][j] == Grid[2][j])
		{
			return Grid[0][j];
		}
	}
	/*diagonals check all at once*/

	if(Grid[0][0] != -1 && Grid[0][0] == Grid[1][1] && Grid[1][1] == Grid[2][2])
	{
		return Grid[1][1];
	}

	/*other diagonal*/
	if(Grid[0][2] != -1 && Grid[0][2] == Grid[1][1] && Grid[1][1] == Grid[2][0])
	{
		return Grid[1][1];
	}


	/*make sure not tie*/
	for(i = 0; i <3; i++)
	{
		for(j = 0 ; j < 3 ; j++)
		{
			/* -1 means the game isn't done */
			if(Grid[i][j] == -1)
			{
				return -1;
			}
		}
	}

	/*it is a tie if it gets here*/
	return 2;
}
/*print out the board for the players*/
void printBoard(int Grid[][3])
{
	int i,j;
	for(i = 0; i <3; i++)
	{
		printf("|");
		for(j = 0 ; j < 3 ; j++)
		{
			switch(Grid[i][j])
			{
				case -1:
				printf(" %i |", i * 3 + j );
				break;
				case 0:
				printf(" O |");
				break;
				case 1:
				printf(" X |");
				break;
			}
		}
		printf("\n\n");
	}
	return;
}
void AImove(char tempboard[3][3], int *rows,  int *columns)
{
    int points=-1, temppoints, i, i2;

    for(i=0;i<3;i++)
    {
        for(i2=0;i2<3;i2++)
        {
            if(tempboard[i][i2]=='\0')
            {
                tempboard[i][i2]='O';
                temppoints = MinMax(tempboard, 1);
                if(temppoints > points)
                {
                    points=temppoints;
                    *rows = i;
                    *columns = i2;
                }
                tempboard[i][i2]='\0';
            }
        }
    }
}

int MinMax(char tempboard[3][3], int player)
{
    int winner, points, temppoints, i, i2;
    winner=didwin(tempboard);
    if(winner=='X') return(0);
    else if (winner=='O') return(999);
    else
    {
        for(i=0;i<3;i++)
        {
            for(i2=0;i2<3;i2++)
            {
                if(tempboard[i][i2]='\0')
                {
                    if (player==1)
                    {
                        tempboard[i][i2]='X';
                    }
                    else
                    {
                        tempboard[i][i2]='O';
                    }
                    if (player==1)
                    {
                        temppoints=MinMax(tempboard, 2);
                    }
                    else
                    {
                        temppoints=MinMax(tempboard, 1);
                    }
                    if(temppoints>points)
                    {
                        points=temppoints;
                    }
                    tempboard[i][i2]='\0';
                }
            }
        }
    }
    return(points);
}