#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	char GameBoard[10][10], User;
	int row, col, RandomPointX, RandomPointY, StartPointX, StartPointY, Score, EnemyX, EnemyY, Enemy, Life;
	bool Quit;

	Quit = false;

	Score = 0;
	Life = 3;

	srand(time(0));

	RandomPointX = (rand() % 9) + 1;
	RandomPointY = (rand() % 9) + 1;

	EnemyX = (rand() % 9) + 1;
	EnemyY = (rand() % 9) + 1;
	
	for (row = 0; row < 10; row++)
	{
		for (col = 0; col < 10; col++)
		{
			GameBoard[row][col] = '-';
		}
	}

	if (RandomPointX < 5)
	{
		StartPointX = RandomPointX + 4;
	}
	else
	{
		StartPointX = RandomPointX - 3;
	}

	if (RandomPointY < 5)
		
	{
		StartPointY = RandomPointY + 6;
	}
	else
	{
		StartPointY = RandomPointY - 4;
	}

	cout << "Created by : Dakota Wilson!\n\nScore points by getting yourself (X) to the doctor (Y) but dont get touched\nby the killer (K) or let him get to the doctor first or you will lose a life!\n\n";

	while (!Quit && Life > 0) 
	{
		cout << "w = X up, a = X left, s = X down, d = right, p = quit\n\n";
		cout << "Score: " << Score << '\n';
		cout << "Lives: " << Life << '\n';
		
		for (row = 0; row < 10; row++)
		{
			
			for (col = 0; col < 10; col++)
			{
				
				cout << GameBoard[row][col] << "  ";
				GameBoard[RandomPointX][RandomPointY] = 'Y';
				GameBoard[StartPointX][StartPointY] = 'X';
				GameBoard[EnemyX][EnemyY] = 'K';
			}
			cout << '\n';
		}
		
		cin >> User;
		
		switch (User)
		{
		case 'w':
			GameBoard[StartPointX][StartPointY] = '-';
			StartPointX -= 1;
			break;
		case 'a':
			GameBoard[StartPointX][StartPointY] = '-';
			StartPointY -= 1;
			break;
		case 's':
			GameBoard[StartPointX][StartPointY] = '-';
			StartPointX += 1;
			break;
		case 'd':
			GameBoard[StartPointX][StartPointY] = '-';
			StartPointY += 1;
			break;
		case 'p':
			Quit = true;
			break;
		default :
			cout << "Invalid Input! Try Again!\n";
			cin >> User;
		}

		Enemy = (rand() % 4) + 1;

		switch (Enemy)
		{
		case 1:
			GameBoard[EnemyX][EnemyY] = '-';
			EnemyX -= 1;
			break;
		case 2:
			GameBoard[EnemyX][EnemyY] = '-';
			EnemyY -= 1;
			break;
		case 3:
			GameBoard[EnemyX][EnemyY] = '-';
			EnemyX += 1;
			break;
		case 4:
			GameBoard[EnemyX][EnemyY] = '-';
			EnemyY += 1;
			break;
		}


		
		if (StartPointX == RandomPointX && StartPointY == RandomPointY)
		{
			Score += 1;

			RandomPointX = (rand() % 9) + 1;
			RandomPointY = (rand() % 9) + 1;
		}

		if (StartPointX == -1)
		{
			StartPointX += 10;
		}
		else if (StartPointX == 10)
		{
			StartPointX -= 10;
		}
		
		if (StartPointY == -1)
		{
			StartPointY += 10;
		}
		else if (StartPointY == 10)
		{
			StartPointY -= 10;
		}

		if (EnemyX == -1)
		{
			EnemyX += 10;
		}
		else if (EnemyX == 10)
		{
			EnemyX -= 10;
		}

		if (EnemyY == -1)
		{
			EnemyY += 10;
		}
		else if (EnemyY == 10)
		{
			EnemyY -= 10;
		}

		if ((EnemyX == RandomPointX && EnemyY == RandomPointY) || (EnemyX == StartPointX && EnemyY == StartPointY))
		{
			Life -= 1;
		}
	}

	return 0;
}