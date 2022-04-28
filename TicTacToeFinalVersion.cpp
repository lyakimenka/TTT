// TicTacToeFinalVersion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Tic Tac Toe
Lizaveta Yakimenka
05.13.2021
*/

#include <iostream>
#include<ctime>
#include<vector>
#include<string>
#include<random>
#include <ctime>

void display(void);
int computerChoice(void);
void win(void);
int choose(std::string);
using namespace std;

int compChoice{};
int choice{ 0 };
int square[10]{ 0,1,2,3,4,5,6,7,8,9 };								// Creating an array for square numbers
char squareValue[10]{ '0','1','2','3','4','5','6','7','8','9' };	// An array for the values of each square

bool winner = false;
void wait(short seconds)											// This function makes countdown last for 3 seconds. 
{																	// Found this idea on cplusplus.com and designed it to work for my game.
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait);
}

int main()															// Main function calls other functions
{

	for (short minutes = 0; minutes >= 0; --minutes)				// Shows 0 minutes
	{
		for (short seconds = 3; seconds >= 0; --seconds)			// Shows seconds 
		{
			cout << "Time before game starts: \n\t\t\t\t" << minutes << ':' << seconds;
			wait(1);												// Waits for a second before it changes
			system("CLS");
		}
	}
	int c{ 0 };
	int i{ 0 };
	for (i = 0; i <= 4; i++)										// Loop to repeatedly call functions
	{
		display();													// Call display func
		c = choose("\tPlease enter a square number ");				// Call choose func
		win();														// Immediatly checks for a win after each new number is chosen
		if (winner == true)											// If there is a win, stops the program
		{
			break;
		}
		c = computerChoice();										// Does the same procedure for when the computer chooses and stops the program if computer won
		win();
		if (winner == true)
		{
			break;
		}

	}
	if (i == 5)
	{
		display();
		c = choose("\tPlease enter the ninth square");
		win();
	}
	display();
	// Call display func, but updated
	return 0;
}


void display(void)														// Void func - no need to return values
{

	cout << "\n"; \

		for (int j = 1; j <= 9; j++) {									// Loop displays numbers and updates chosen numbers with an X

			cout << "\t" << squareValue[j];

			if (j == 3 || j == 6)
			{
				cout << endl << endl << endl;
			}
		}
	cout << "\n\n";
	choice = 0;
	compChoice = 0;
}

int choose(std::string prompt)											// Int function choose is needed to return the value of choise variable to use it in display
{
	bool x = false;
	do
	{																	// Loops to check if the chosen number available
		cout << "\t" << prompt;
		cin >> choice;

		for (int i = 1; i <= 9; i++)
		{
			if (choice == i && square[i] == choice)
			{
				square[i] = -1;
				x = true;
				squareValue[i] = 'X';
			}
		}
	} while (x == false);
	return choice;														// Returns choice, so it is possible to use it in other functions
}

int computerChoice(void)
{
	srand(time(0));
	bool x = false;
	do {
		cout << "\nComputers choice ";
		compChoice = 1 + rand() % 9;									// Randomly chooses a number from 1 to 9

		for (int i = 1; i <= 9; i++)
		{
			if (compChoice == i && square[i] == compChoice)				// If the number chosen is not already taken, put a O on its place
			{
				square[i] = -1;
				x = true;
				squareValue[i] = 'O';
			}
		}
	} while (x == false);

	return compChoice;
}

void win()
{
	if (squareValue[1] == 'X' && squareValue[2] == 'X' && squareValue[3] == 'X')			// If any one of the conditions is met - win
	{
		cout << "\nYou have won with row 1";
		winner = true;
	}
	if (squareValue[1] == 'O' && squareValue[2] == 'O' && squareValue[3] == 'O')			// If any one of the conditions is met - win
	{
		cout << "\nComputer have won with row 1";
		winner = true;
	}
	if (squareValue[4] == 'X' && squareValue[5] == 'X' && squareValue[6] == 'X')
	{
		cout << "\nYou have won with row 2";
		winner = true;
	}
	if (squareValue[4] == 'O' && squareValue[5] == 'O' && squareValue[6] == 'O')
	{
		cout << "\nComputer have won with row 2";
		winner = true;
	}
	if (squareValue[7] == 'X' && squareValue[8] == 'X' && squareValue[9] == 'X')
	{
		cout << "\nYou have won with row 3";
		winner = true;
	}
	if (squareValue[7] == 'O' && squareValue[8] == 'O' && squareValue[9] == 'O')
	{
		cout << "\nComputer have won with row 3";
		winner = true;
	}
	if (squareValue[1] == 'X' && squareValue[4] == 'X' && squareValue[7] == 'X')
	{
		cout << "\nYou have won with column 1";
		winner = true;
	}
	if (squareValue[1] == 'O' && squareValue[4] == 'O' && squareValue[7] == 'O')
	{
		cout << "\nComputer have won with column 1";
		winner = true;
	}
	if (squareValue[2] == 'X' && squareValue[5] == 'X' && squareValue[8] == 'X')
	{
		cout << "\nYou have won with column 2";
		winner = true;
	}
	if (squareValue[2] == 'O' && squareValue[5] == 'O' && squareValue[8] == 'O')
	{
		cout << "\nComputer have won with column 2";
		winner = true;
	}
	if (squareValue[3] == 'X' && squareValue[6] == 'X' && squareValue[9] == 'X')
	{
		cout << "\nYou have won with column 3";
		winner = true;
	}
	if (squareValue[3] == 'O' && squareValue[6] == 'O' && squareValue[9] == 'O')
	{
		cout << "\nComputer have won with column 3";
		winner = true;
	}
	if (squareValue[1] == 'X' && squareValue[5] == 'X' && squareValue[9] == 'X')
	{
		cout << "\nYou have won with diagonal";
		winner = true;
	}
	if (squareValue[1] == 'O' && squareValue[5] == 'O' && squareValue[9] == 'O')
	{
		cout << "\nComputer have won with diagonal";
		winner = true;
	}
	if (squareValue[3] == 'X' && squareValue[5] == 'X' && squareValue[7] == 'X')
	{
		cout << "\nYou have won with diagonal";
		winner = true;
	}
	if (squareValue[3] == 'O' && squareValue[5] == 'O' && squareValue[7] == 'O')
	{
		cout << "\nComputer have won with diagonal";
		winner = true;
	}
	if (squareValue[1] != '1' && squareValue[2] != '2' && squareValue[3] != '3' &&					// If all the squares are marked and no win - it is a tie
		squareValue[4] != '4' && squareValue[5] != '5' && squareValue[6] != '6' &&
		squareValue[7] != '7' && squareValue[8] != '8' && squareValue[9] != '9' && winner == false)
	{
		cout << "Its a tie! Please, play again!" << endl;
		winner = true;
	}
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
