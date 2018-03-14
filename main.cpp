#include <iostream>
#include <ctime>
using namespace std;

// Declaring variables
const int levelRows = 10;
const int levelColumns = 10;
int maximumShips = 10;

int gameLevel[levelRows][levelColumns];

// Creates level 
void CreateLevel()
{
	for (int i=0; i< levelRows ; i++)
	{
		for (int j = 0 ; j< levelColumns ; j++)
		{
			gameLevel[i][j] = 0;
		}
	}
}

// Shows level on console
void ShowLevel()
{
	for (int i=0; i< levelRows ; i++)
	{
		for (int j = 0 ; j< levelColumns ; j++)
		{
			cout << gameLevel[i][j]<< " ";
		}
		cout << endl;
	}
}

// Sets the locations of the ships
void SetShipLocations()
{
	int spawnShips =0;
	while(spawnShips < maximumShips)
	{
		int randomRowLocation = rand() % levelRows;
		int randomColumnLocation = rand() % levelColumns;
		if (gameLevel[randomRowLocation][randomColumnLocation] != 1)
		{
			spawnShips ++;
			gameLevel[randomRowLocation][randomColumnLocation] = 1;
		}
	}
}

// How many ships remain after the attack
int numberOfShips()
{
	int numberOfRemainingShips = 0;
	for (int i=0; i< levelRows ; i++)
	{
		for (int j = 0 ; j< levelColumns ; j++)
		{
			if (gameLevel[i][j] == 1)	
			{
				numberOfRemainingShips++;
			}
		}
	}

	return numberOfRemainingShips;
}

// If there is a ship at that row and column it gets destroyed
bool shipAttack(int row , int column)
{
	if (gameLevel[row][column] == 1)
	{
		gameLevel[row][column] = 2;
		return true;
	}

	return false;
}

// Calls all functions
int main()
{
	srand(time(NULL));
	int rowAttack , columnAttack;
	char endGameOption;
	CreateLevel();
	SetShipLocations();
	while(1)
	{
			cout << "Enter row: /n" << endl;
			cin >> rowAttack;
			cout << "Enter column: /n" << endl;
			cin >> columnAttack;

			if (shipAttack(rowAttack,columnAttack))
			{
				cout << "You ot me!! :) " << endl;
			}
			else
			{
				cout << "Sorry no ship at this location, better luck next time!" << endl;
			}
			cout << "Number of remaining ships is/are: " << numberOfShips() << endl;
			cout << "Do you want to surrender (y/n)?" ; cin >> endGameOption;
			if (endGameOption == 'y')
			{
				break;
			}
	}

	cout << "Game over!" << endl;
	ShowLevel();
	system("pause");
	return 0;
}