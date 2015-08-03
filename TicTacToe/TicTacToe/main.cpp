//#include "stdafx.h"		/*precompiled header*/
#include <iostream>		/*cout,cin*/
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>		/* srand, rand */
#include <ctime>		/* for time()*/
#include "GameBoard.h"
#include "Score.h"

/*
THINGS TO WORK ON:
1) player can choose start first or not, choose using X or O	DONE
2) resizable board, can choose 3x3, 4x4, 5x5...etc
3) AI, stupid computer now that won't block user's movement.
4) Refactoring
	a) Rename variables into more descriptive words
	b) Put some of the functions into header file?
	c) Put the forward function call into header file
	d) find ways to reduce the size of code
	e) reduce the use of global variables such as gameBoard.getGridChar and namespace
5) check user input against integer and string
*/

using namespace std;

//forward function declaration
int randomNum(int min,int max);
void playerMovement(GameBoard &board,int &trial);
void computerMovement(GameBoard &board,int &trial,const int &boardSize);

int main()
{
	//variable initialization
	srand(time(0));
	int playerPos;
	int computerPos;
	char startFirst;
	char playerSign;
	char computerSign;
	int numOfRow=3;
	int numOfCol=3;
	int boardSize=numOfRow*numOfCol;


	cout << "So this is the game of Tic Tac Toe, let see how it works" << "\n";
	cout << "What kind of sign you would like to use?" << "\n";
	cin >> playerSign;
	cout << "What kind of sign you would like ME to use?" << "\n";
	cin >> computerSign;

    cout<<"numOfRow and numOfCol? \n";
    cin>>numOfCol;
    numOfRow=numOfCol;
	//GameBoard(int nRow,int nCol,char chPlayerSign,char chComputerSign);
    GameBoard gameBoard(numOfRow,numOfCol,playerSign,computerSign);

	//-----------------let the player to choose if player go first or computer-----------------
	do {
		cout << " Do you want to start first or not? y=yes and n=no \n";
		cin >> startFirst;
	} while ((startFirst != 'n') & (startFirst != 'y') );

	//if computer go first, randomly set a pos for computer
	int trial = 0;
	if (startFirst == 'n')
	{
		computerMovement(gameBoard,trial,boardSize);
	}
	//-----------------------------------------------------------------------------------------

    Score gameScore;
	while (gameScore.getGameState(gameBoard) == Score::PLAYING)
	{
	    //----------------------player's movement-----------------------------
        playerMovement(gameBoard,trial);

		if (gameScore.getGameState(gameBoard) == Score::PLAYER_WIN ||trial>=boardSize)
        {
           break;
        }

        //----------------------computer's movement-----------------------------
        computerMovement(gameBoard,trial,boardSize);

		if (gameScore.getGameState(gameBoard) == Score::COMPUTER_WIN||trial>=boardSize)
        {
            break;
        }
	}

	if (trial>=boardSize)
		cout << " It is a DRAW :P" << "\n";

	return 0;
}

void playerMovement(GameBoard &board,int &trial)
{
    int playerPos;
    do{
        cout << " Where do you want to place?" << "\n";
        cin >> playerPos;
    } while (board.setPlayerPos(playerPos)==false);     //while player's position is invalid
    trial++;
}

void computerMovement(GameBoard &board,int &trial,const int &boardSize)
{
    int computerPos;
    cout << " It's my movement now " << "\n";
    do{
        computerPos = randomNum(1,boardSize); //to do random number from 1 to 9
    } while (board.setComputerPos(computerPos)==false);
    trial++;
}

//generate random int number between max and min.
int randomNum(int min,int max)
{
    return (rand() % (max-1)) + min;
}

