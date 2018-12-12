#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	char GameBoard[10][10], User;
	int row, col, RandomPointX, RandomPointY, StartPointX, StartPointY, Score, EnemyX, EnemyY, Enemy, Life, Enemy2X, Enemy2Y, Enemy3X, Enemy3Y, Enemy4X, Enemy4Y, Enemy5X, Enemy5Y;
	bool Quit, Enemy2, Enemy3, Enemy4, Enemy5;

	Quit = false;
	Enemy2 = false;
	Enemy3 = false;
	Enemy4 = false;
	Enemy5 = false;

	Score = 0;
	Life = 3;
	Enemy2X = -10;
	Enemy3X = -10;
	Enemy4X = -10;
	Enemy5X = -10;
	Enemy2Y = -10;
	Enemy3Y = -10;
	Enemy4Y = -10;
	Enemy5Y = -10;

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
				if (Score >= 1)
				{
					GameBoard[Enemy2X][Enemy2Y] = 'K';
				}
				if (Score >= 2)
				{
					GameBoard[Enemy3X][Enemy3Y] = 'K';
				}
				if (Score >= 3)
				{
					GameBoard[Enemy4X][Enemy4Y] = 'K';
				}
				if (Score >= 4)
				{
					GameBoard[Enemy5X][Enemy5Y] = 'K';
				}

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
		default:
			cout << "Invalid Input! Try Again!\n";
			cin >> User;
		}

		Enemy = (rand() % 4) + 1;

		switch (Enemy)
		{
		case 1:
			GameBoard[EnemyX][EnemyY] = '-';
			EnemyX -= 1;
			if (Score >= 1)
			{
				GameBoard[Enemy2X][Enemy2Y] = '-';
				Enemy2X += 1;
			}
			if (Score >= 2)
			{
				GameBoard[Enemy3X][Enemy3Y] = '-';
				Enemy3X -= 2;
			}
			if (Score >= 3)
			{
				GameBoard[Enemy4X][Enemy4Y] = '-';
				Enemy4X += 2;
			}
			if (Score >= 4)
			{
				GameBoard[Enemy5X][Enemy5Y] = '-';
				Enemy5X -= 3;
			}
			break;
		case 2:
			GameBoard[EnemyX][EnemyY] = '-';
			EnemyY -= 1;
			if (Score >= 1)
			{
				GameBoard[Enemy2X][Enemy2Y] = '-';
				Enemy2Y += 1;
			}
			if (Score >= 2)
			{
				GameBoard[Enemy3X][Enemy3Y] = '-';
				Enemy3Y -= 2;
			}
			if (Score >= 3)
			{
				GameBoard[Enemy4X][Enemy4Y] = '-';
				Enemy4Y += 2;
			}
			if (Score >= 4)
			{
				GameBoard[Enemy5X][Enemy5Y] = '-';
				Enemy5Y -= 3;
			}
			break;
		case 3:
			GameBoard[EnemyX][EnemyY] = '-';
			EnemyX += 1;
			if (Score >= 1)
			{
				GameBoard[Enemy2X][Enemy2Y] = '-';
				Enemy2X -= 1;
			}
			if (Score >= 2)
			{
				GameBoard[Enemy3X][Enemy3Y] = '-';
				Enemy3X += 2;
			}
			if (Score >= 3)
			{
				GameBoard[Enemy4X][Enemy4Y] = '-';
				Enemy4X -= 2;
			}
			if (Score >= 4)
			{
				GameBoard[Enemy5X][Enemy5Y] = '-';
				Enemy5X += 3;
			}
			break;
		case 4:
			GameBoard[EnemyX][EnemyY] = '-';
			EnemyY += 1;
			if (Score >= 1)
			{
				GameBoard[Enemy2X][Enemy2Y] = '-';
				Enemy2Y -= 1;
			}
			if (Score >= 2)
			{
				GameBoard[Enemy3X][Enemy3Y] = '-';
				Enemy3Y += 2;
			}
			if (Score >= 3)
			{
				GameBoard[Enemy4X][Enemy4Y] = '-';
				Enemy4Y -= 2;
			}
			if (Score >= 4)
			{
				GameBoard[Enemy5X][Enemy5Y] = '-';
				Enemy5Y += 3;
			}
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

		if (Enemy2X == -1)
		{
			Enemy2X += 10;
		}
		else if (Enemy2X == 10)
		{
			Enemy2X -= 10;
		}

		if (Enemy2Y == -1)
		{
			Enemy2Y += 10;
		}
		else if (Enemy2Y == 10)
		{
			Enemy2Y -= 10;
		}

		if (Enemy3X <= -1)
		{
			Enemy3X += 10;
		}
		else if (Enemy3X >= 10)
		{
			Enemy3X -= 10;
		}

		if (Enemy3Y <= -1)
		{
			Enemy3Y += 10;
		}
		else if (Enemy3Y >= 10)
		{
			Enemy3Y -= 10;
		}

		if (Enemy4X <= -1)
		{
			Enemy4X += 10;
		}
		else if (Enemy4X >= 10)
		{
			Enemy4X -= 10;
		}

		if (Enemy4Y <= -1)
		{
			Enemy4Y += 10;
		}
		else if (Enemy4Y >= 10)
		{
			Enemy4Y -= 10;
		}

		if (Enemy5X <= -1)
		{
			Enemy5X += 10;
		}
		else if (Enemy5X >= 10)
		{
			Enemy5X -= 10;
		}

		if (Enemy5Y <= -1)
		{
			Enemy5Y += 10;
		}
		else if (Enemy5Y >= 10)
		{
			Enemy5Y -= 10;
		}

		if ((EnemyX == RandomPointX && EnemyY == RandomPointY) || (EnemyX == StartPointX && EnemyY == StartPointY) ||
			(Enemy2X == RandomPointX && Enemy2Y == RandomPointY) || (Enemy2X == StartPointX && Enemy2Y == StartPointY) ||
			(Enemy3X == RandomPointX && Enemy3Y == RandomPointY) || (Enemy3X == StartPointX && Enemy3Y == StartPointY) ||
			(Enemy4X == RandomPointX && Enemy4Y == RandomPointY) || (Enemy4X == StartPointX && Enemy4Y == StartPointY) ||
			(Enemy5X == RandomPointX && Enemy5Y == RandomPointY) || (Enemy5X == StartPointX && Enemy5Y == StartPointY))
		{
			Life -= 1;
		}

		if (Score == 1)
		{
			Enemy2 = true;
		}
		if (Score == 2)
		{
			Enemy3 = true;
		}
		if (Score == 3)
		{
			Enemy4 = true;
		}
		if (Score == 4)
		{
			Enemy5 = true;
		}

		if (Enemy2)
		{
			Enemy2X = (rand() % 9) + 1;
			Enemy2Y = (rand() % 9) + 1;
			Enemy2 = false;
		}
		if (Enemy3)
		{
			Enemy3X = (rand() % 9) + 1;
			Enemy3Y = (rand() % 9) + 1;
			Enemy3 = false;
		}
		if (Enemy4)
		{
			Enemy4X = (rand() % 9) + 1;
			Enemy4Y = (rand() % 9) + 1;
			Enemy4 = false;
		}
		if (Enemy5)
		{
			Enemy5X = (rand() % 9) + 1;
			Enemy5Y = (rand() % 9) + 1;
			Enemy5 = false;
		}

	}

	cout << "\n\n\n\n\n\n\nFinal Score: " << Score << "\n\n\n\n\nGood Job!\n\n\n\n\nPress any key to exit!\n\n\n\n\n\n\n\n\n\n\n\n";
	
	system("pause");
	return 0;
}