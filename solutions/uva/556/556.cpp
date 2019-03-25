/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=497
 * 556 - Amazing
*/

#include <iostream>
#include <vector>
#include <iomanip> // std::setw

class Maze
{
  private:
	int b, w;
	std::vector<std::vector<int>> board;
	std::vector<std::vector<int>> count;

	int x, y;

	int startX, startY;
	// East, West, North, South directions
	char dir;

  public:
	Maze(int b, int w)
	{
		this->b = b;
		this->w = w;
		this->board.resize(b + 2, std::vector<int>(w + 2, 1));
		this->count.resize(b + 2, std::vector<int>(w + 2, -1));

		this->x = this->startX = 1;
		this->y = this->startY = b;
		this->dir = 'E';
	};
	~Maze()
	{
		for (auto eachLine : board)
			eachLine.clear();
		board.clear();
	};

	void insertLines()
	{
		std::string line;
		for (int i = 0; i < b; i++)
		{
			std::cin >> line;
			for (int j = 0; j < w; j++)
			{
				board[i + 1][j + 1] = int(line[j] - '0');
				if (board[i + 1][j + 1] == 0)
					count[i + 1][j + 1] = 0;
			}
		}
	}

	/**
	 * @brief To check if maze is mounted correctly
	 * 
	 */
	void printMaze()
	{
		for (auto &line : board)
		{
			for (auto &block : line)
				std::cout << block;
			std::cout << '\n';
		}
	}

	void printMazeMap()
	{
		for (int i = 1; i <= b; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				if (x == j && y == i)
					std::cout << 'X';
				else
					std::cout << board[i][j];
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}

	void printState()
	{
		std::cout << '(' << this->x << ',' << this->y << ')' << '\n';
	}

	void turnleft()
	{
		switch (dir)
		{
		case 'N':
			dir = 'W';
			break;
		case 'S':
			dir = 'E';
			break;
		case 'E':
			dir = 'N';
			break;
		case 'W':
			dir = 'S';
			break;
		}
	}

	void turnRight()
	{
		switch (dir)
		{
		case 'N':
			dir = 'E';
			break;
		case 'S':
			dir = 'W';
			break;
		case 'E':
			dir = 'S';
			break;
		case 'W':
			dir = 'N';
			break;
		}
	}
	void goForward()
	{
		switch (dir)
		{
		case 'N':
			y--;
			break;
		case 'S':
			y++;
			break;
		case 'E':
			x++;
			break;
		case 'W':
			x--;
			break;
		}
	}

	bool moveRobot();
	void summary();
};

/**
 * @brief Return true if get the initial position
 * 
 * @return bool
 */
bool Maze::moveRobot()
{
	if (dir == 'N')
	{
		if (board[y][x + 1] == 0)
		{
			turnRight();
			goForward();
		}
		else if (board[y - 1][x] == 0)
		{
			goForward();
		}
		else if (board[y][x - 1] == 0)
		{
			turnleft();
			goForward();
		}
		else if (board[y + 1][x] == 0)
		{
			turnleft();
			turnleft();
			goForward();
		}
	}
	else if (dir == 'E')
	{
		if (board[y + 1][x] == 0)
		{
			turnRight();
			goForward();
		}
		else if (board[y][x + 1] == 0)
		{
			goForward();
		}
		else if (board[y - 1][x] == 0)
		{
			turnleft();
			goForward();
		}
		else if (board[y][x - 1] == 0)
		{
			turnleft();
			turnleft();
			goForward();
		}
	}
	else if (dir == 'W')
	{
		if (board[y - 1][x] == 0)
		{
			turnRight();
			goForward();
		}
		else if (board[y][x - 1] == 0)
		{
			goForward();
		}
		else if (board[y + 1][x] == 0)
		{
			turnleft();
			goForward();
		}
		else if (board[y][x + 1] == 0)
		{
			turnleft();
			turnleft();
			goForward();
		}
	}
	else if (dir == 'S')
	{
		if (board[y][x - 1] == 0)
		{
			turnRight();
			goForward();
		}
		else if (board[y + 1][x] == 0)
		{
			goForward();
		}
		else if (board[y][x + 1] == 0)
		{
			turnleft();
			goForward();
		}
		else if (board[y - 1][x] == 0)
		{
			turnleft();
			turnleft();
			goForward();
		}
	}

	count[y][x]++;
	return (x == startX && y == startY) ? true : false;
}

void Maze::summary()
{
	// not visited and how many were visited one, twice, thrice and four times
	int zero = 0, ichi = 0, ni = 0, san = 0, yon = 0;

	for (auto &line : count)
	{
		for (auto &eachBlock : line)
		{
			if (eachBlock == 0)
				zero++;
			else if (eachBlock == 1)
				ichi++;
			else if (eachBlock == 2)
				ni++;
			else if (eachBlock == 3)
				san++;
			else if (eachBlock == 4)
				yon++;
		}
	}
	std::cout << std::setw(3) << zero << std::setw(3) << ichi << std::setw(3) << ni << std::setw(3) << san << std::setw(3) << yon << '\n';
}

int main()
{
	int b, w;
	std::string line;

	while (std::cin >> b >> w)
	{
		if (b == 0 || w == 0)
			break;
		Maze maze(b, w);
		maze.insertLines();
		// maze.printMaze();
		// maze.printState();
		// maze.printMazeMap();
		while (!maze.moveRobot())
			continue;

		// maze.printMazeMap();

		maze.summary();
	}

	return 0;
}
