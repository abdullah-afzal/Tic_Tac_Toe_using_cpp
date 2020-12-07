#include<iostream>
#include<conio.h>
using namespace std;


void game();// function which handels the board 

//basic game functions 
void boardDisplay(char board[][3]);
bool isGameComplete(int turn, char board[][3]);
char getInput(int* turn, char board[][3]);
bool isValidInput(char input, char board[][3]);
void replaceInput(char board[][3], char input, char player);
char whichPlayer(int turn);
bool checkMainDigonel(char arr[][3]);
bool checkDigonel2(char arr[][3]);
bool checkRows(char arr[][3]);
bool checkColms(char arr[][3]);
void callResults(int, char[][3]);

int main()
{
	game();
	return 0;
}

//functions defination

void game()
{
	char board[3][3] = { '1','2','3','4','5','6','7','8','9' };
	char player1 = 'X', player2 = 'O';
	int turn = 1;
	char input;
	while (!isGameComplete(turn, board))
	{
		cout << "\nPlayer 1 symbol: " << player1 << "\tPlayer 2 symbol: " << player2 << "\n";
		boardDisplay(board);
		input = getInput(&turn, board);
		replaceInput(board, input, whichPlayer(turn - 1));
		system("CLS");
		if (isGameComplete(turn, board))
		{
			callResults(turn - 1, board);
		}
	}
	
}

void boardDisplay(char board[][3])
{
	for (int i = 0; i < 3; i = i + 1)
	{
		cout << "\n";
		for (int j = 0; j < 3; j = j + 1)
		{
			cout << "\t" <<board[i][j];
			j != 2 ? cout << "  |" : cout << "";
		}
		i != 2 ? cout << "\n\t___|_______|_____\n\t   |       |": cout << "";
	}
}
bool isGameComplete(int turn, char board[][3])
{
	bool check = false;
	if (checkMainDigonel(board) == true)
	{
		check = true;
	}
	else if (checkDigonel2(board) == true)
	{
		check = true;
	}
	else if (checkRows(board) == true)
	{
		check = true;
	}
	else if (checkColms(board) == true)
	{
		check = true;
	}
	else if (turn >= 10)
		check = true;
	return check;
}
char getInput(int*turn,char board[][3])
{
	char input;
	*turn % 2 == 1 ? cout << "\n\tPlayer 1 Turn" : cout << "\n\tPlayer 2 Turn";
	input = _getch();
	while (!isValidInput(input,board))
	{
		cout << "\n\t Enter the valid value";
		input = _getch();
	}
	*turn = *turn + 1;
	return input;
}
bool isValidInput(char input,char arr[][3])
{
	int check = 0;
	if (input == 'X' || input == 'O')
		return false;
	for (int i = 0; i < 3; i = i + 1)
	{
		for (int j = 0; j < 3; j = j + 1)
		{
			if (input == arr[i][j])
			{
				check = check + 1;
			}
		}
	}
	if (check > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void replaceInput(char board[][3], char input,char player)
{
	for (int i = 0; i < 3; i = i + 1)
	{
		for (int j = 0; j < 3; j = j + 1)
		{
			if (input == board[i][j])
			{
				board[i][j] = player;
			}
		}
	}
}
char whichPlayer(int turn)
{
	if (turn % 2 == 1)
		return 'X';
	else
		return 'O';
}
bool checkMainDigonel(char arr[][3])
{
	bool check = false;
	int i = 0, j = 0;
	if (arr[i][j] == arr[i + 1][j + 1])
	{
		if (arr[i][j] == arr[i + 2][j + 2])
		{
			check = true;
		}
	}
	return check;
}
bool checkDigonel2(char arr[][3])
{
	bool check = false;
	int i = 0, j = 2;

	if (arr[i][j] == arr[i + 1][j - 1])
	{
		if (arr[i][j] == arr[i + 2][j - 2])
		{
			check = true;
		}
	}
	return check;
}
bool checkRows(char arr[][3])
{
	bool check = false;
	for (int i = 0; i < 3; i = i + 1)
	{
		int j = 0;
		if (arr[i][j] == arr[i][j + 1])
		{
			if (arr[i][j] == arr[i][j + 2])
			{
				check = true;
			}
		}
	}
	return check;
}
bool checkColms(char arr[][3])
{
	bool check = false;
	for (int i = 0; i < 3; i = i + 1)
	{
		int j = 0;
		if (arr[j][i] == arr[j + 1][i])
		{
			if (arr[j][i] == arr[j + 2][i])
			{
				check = true;
			}
		}
	}
	return check;
}
void callResults(int turn, char board[][3])
{
	string player;
	if (turn % 2 == 1)
		player = "Player 1";
	else
		player = "Player 2";
	string draw = "\n\tMatch Draw";
	string drawHash = "\n\t#well_played";
	cout << "\n\t*************************\n";
	if (checkMainDigonel(board) == true)
	{
		cout << "\n\t" << player << " Won the match";
	}
	else if (checkDigonel2(board) == true)
	{
		cout << "\n\t" << player << " Won the match";
	}
	else if (checkRows(board) == true)
	{
		cout << "\n\t" << player << " Won the match";
	}
	else if (checkColms(board) == true)
	{
		cout << "\n\t" << player << " Won the match";
	}
	else
		cout << "\n\t\t" << draw << "\n\t" << drawHash;
	cout << "\n\t*************************\n";
}
