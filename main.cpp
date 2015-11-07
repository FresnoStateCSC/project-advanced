#include <iostream>
#include <stdlib.h>
using namespace std;

void PvP();
void PvE();
void E();
void initBoard(char board[3][3]);
int checkWinner(char board[3][3], int player);
bool checkFull(char board[3][3]);
void printBoard(char board[3][3]);

int main()
{
	int input;
	cout << "Tic Tac Toe" << endl;
	cout << "Pick a mode" << endl;
	cout << "1. Player vs Player" << endl;
	cout << "2. Player vs CPU" << endl;
	cout << "3. Teach CPU" << endl;
	cin >> input;
	if(input == 1)
	{
		PvP();
	}
	else if(input == 2)
	{
		//PVE();	
	}
	else if(input == 3)
	{
		//E();
	}
	return 0;
}

void initBoard(char board[3][3])
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			board[i][j] = '|';
		}
	}
}

int checkWinner(char board[3][3], int player)
{
	//Check Player One
	if(player == 1)
	{
		if(board[0][0] == 'x' &&
	   	board[0][1] == 'x' &&
	   	board[0][2] == 'x')
		{
			return 0;
		}
		if(board[1][0] == 'x' &&
           	board[1][1] == 'x' &&
           	board[1][2] == 'x')
        	{
                	return 0;
        	}
		if(board[2][0] == 'x' &&
           	board[2][1] == 'x' &&
           	board[2][2] == 'x')
        	{
                	return 0;
        	}
		if(board[0][0] == 'x' &&
           	board[1][0] == 'x' &&
           	board[2][0] == 'x')
        	{
                	return 0;
        	}
		if(board[0][1] == 'x' &&
           	board[1][1] == 'x' &&
           	board[2][1] == 'x')
        	{
                	return 0;
        	}
		if(board[0][2] == 'x' &&
           	board[1][2] == 'x' &&
           	board[2][2] == 'x')
        	{
                	return 0;
        	}
		if(board[0][0] == 'x' &&
           	board[1][1] == 'x' &&
           	board[2][2] == 'x')
        	{
                	return 0;
        	}
		if(board[0][2] == 'x' &&
           	board[1][1] == 'x' &&
           	board[2][0] == 'x')
        	{
                	return 0;
        	}
	}
	
	 //Check Player Two
	else if(player == 2)
	{
        	if(board[0][0] == 'o' &&
           	board[0][1] == 'o' &&
           	board[0][2] == 'o')
        	{
                	return 0;
        	}
        	if(board[1][0] == 'o' &&
           	board[1][1] == 'o' &&
           	board[1][2] == 'o')
        	{
                	return 0;
        	}
        	if(board[2][0] == 'o' &&
           	board[2][1] == 'o' &&
           	board[2][2] == 'o')
        	{
                	return 0;
        	}
        	if(board[0][0] == 'o' &&
           	board[1][0] == 'o' &&
           	board[2][0] == 'o')
        	{
                	return 0;
        	}
        	if(board[0][1] == 'o' &&
           	board[1][1] == 'o' &&
           	board[2][1] == 'o')
        	{
                	return 0;
        	}
        	if(board[0][2] == 'o' &&
           	board[1][2] == 'o' &&
           	board[2][2] == 'o')
        	{
                	return 0;
        	}
		if(board[0][0] == 'o' &&
           	board[1][1] == 'o' &&
           	board[2][2] == 'o')
        	{
                	return 0;
        	}
		if(board[0][2] == 'o' &&
           	board[1][1] == 'o' &&
           	board[2][0] == 'o')
        	{
                	return 0;
        	}
	}
		return -1;

}
bool checkFull(char board[3][3])
{
	for(int i=0; i < 3; i++)
	{
		for(int j=0; j< 3; j++)
		{
			if(board[i][j] != 'x' && board[i][j] != 'o')
				return false;
		}
	}
	return true;
}
void printBoard(char board[3][3])
{
	for(int i = 0; i < 3; i++)
	{	
		for(int j = 0; j < 3; j++)
		{
			cout << board[i][j] << "  ";
		}
		cout << endl;
	}
}

void PvP()
{
	int inputX, inputY;
	bool invalid = true;
	char board[3][3];
	initBoard(board);
	bool done = false;
	while(done == false)
	{
		for(int i=1; i < 3; i++)
		{
			invalid = false;
			while(invalid == false)
			{
				printBoard(board);
				cout << endl << "Player " << i << "'s turn" << endl;
				cout << "Row: ";
				cin >> inputX;
				cout << "Column: ";
				cin >> inputY;
				if(board[inputX][inputY] == 'x' || board[inputX][inputY] == 'o')
				{
					system("clear");
					cout << "Invalid move" << endl;
				}
				else
				{
					if(i==1)
						board[inputX][inputY] = 'x';
					else
						board[inputX][inputY] = 'o';
					invalid = true;
				}
			}
			system("clear");
			if(checkWinner(board, i) == 0)
			{
				system("clear");
				printBoard(board);
				cout << endl << "Player " << i << " Wins!" << endl;
				done = true;
				break;
			}
			if(checkFull(board))
			{
				system("clear");
				printBoard(board);
				cout << endl << "Draw" << endl;
				done = true;
				break;
			}

		}
		
	}
}


