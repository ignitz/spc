/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=156
 * 220 - Othello
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cassert>

class Othello
{
  private:
	std::vector<std::vector<char>> board;
	char currentPlayer;
	std::vector<std::pair<int, int>> possiblePos;

  public:
	Othello();
	~Othello();
	void setBlock(int x, int y, char c);
	void setCurrentPlayer(char current);
	void switchCurrentPlayer();
	void printBoard();
	void printSummary();
	void listAllPossibleMoves();
	void getAllPossibleMoves();
	void clearPossibleMoves();
	bool isPossibleMove(int x, int y);
	bool isAlone(int x, int y);
	void tryToChangeThisShit(int x, int y);
	void moveThisFuck(int x, int y);
};

Othello::Othello()
{
	board.resize(8, std::vector<char>(8, '-'));
}

Othello::~Othello()
{
}

void Othello::setBlock(int x, int y, char c)
{
	board[y][x] = c;
}

void Othello::setCurrentPlayer(char current)
{
	this->currentPlayer = current;
}

void Othello::switchCurrentPlayer()
{
	this->currentPlayer = this->currentPlayer == 'B' ? 'W' : 'B';
}

void Othello::printBoard()
{
	for (auto &line : board)
	{
		for (char &c : line)
			std::cout << c;
		std::cout << '\n';
	}
}

void Othello::printSummary()
{
	int countBlack = 0, countWhite = 0;

	// std::string stringBoard;

	for (auto &line : board)
	{
		for (char &c : line)
		{
			if (c == 'W')
				countWhite++;
			else if (c == 'B')
				countBlack++;

			// stringBoard.push_back(c);
		}
		// stringBoard.push_back('\n');
	}

	std::cout << "Black -  " << countBlack << ' ' << "White -  " << countWhite << '\n';
}

void Othello::getAllPossibleMoves()
{
	clearPossibleMoves();
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[j][i] == '-' && isPossibleMove(i, j))
				possiblePos.push_back(std::make_pair(j, i));
		}
	}

	std::sort(possiblePos.begin(), possiblePos.end());
}

void Othello::clearPossibleMoves()
{
	possiblePos.clear();
}

void Othello::listAllPossibleMoves()
{
	// assert(currentPlayer == 'B' || currentPlayer == 'W');

	// getAllPossibleMoves();

	for (int i = 0; i < possiblePos.size(); i++)
	{
		if (i != 0)
			std::cout << ' ';
		std::cout << '(' << possiblePos[i].first + 1 << ',' << possiblePos[i].second + 1 << ')';
	}

	if (possiblePos.size() == 0)
	{
		std::cout << "No legal move.";
		switchCurrentPlayer();
	}
	std::cout << '\n';
}

bool Othello::isAlone(int x, int y)
{
	int beginX, endX;
	int beginY, endY;

	beginX = std::max(0, x - 1);
	endX = std::min(7, x + 1);
	beginY = std::max(0, y - 1);
	endY = std::min(7, y + 1);

	for (int i = beginX; i <= endX; i++)
	{
		for (int j = beginY; j <= endY; j++)
		{
			if (i == x && y == j)
				continue;
			if (board[j][i] != '-')
				return false;
		}
	}

	return true;
}

bool Othello::isPossibleMove(int x, int y)
{
	if (isAlone(x, y))
		return false;

	bool check;

	char same = this->currentPlayer;
	char other = this->currentPlayer == 'B' ? 'W' : 'B';

	// E
	check = false;
	for (int i = x + 1; i < 8; i++)
	{
		if (board[y][i] == other)
			check = true;
		if (check && board[y][i] == same)
			return true;
		if (board[y][i] == '-')
			break;
	}
	// W
	check = false;
	for (int i = x - 1; i >= 0; i--)
	{
		if (board[y][i] == other)
			check = true;
		if (check && board[y][i] == same)
			return true;
		if (board[y][i] == '-')
			break;
	}

	// N
	check = false;
	for (int i = y - 1; i >= 0; i--)
	{
		if (board[i][x] == other)
			check = true;
		if (check && board[i][x] == same)
			return true;
		if (board[i][x] == '-')
			break;
	}
	// S
	check = false;
	for (int i = y + 1; i < 8; i++)
	{
		if (board[i][x] == other)
			check = true;
		if (check && board[i][x] == same)
			return true;
		if (board[i][x] == '-')
			break;
	}

	// NE
	check = false;
	for (int i = x + 1, j = y - 1; i < 8 && j >= 0; i++, j--)
	{
		if (board[j][i] == other)
			check = true;
		if (check && board[j][i] == same)
			return true;
		if (board[j][i] == '-')
			break;
	}

	// SE
	check = false;
	for (int i = x + 1, j = y + 1; i < 8 && j < 8; i++, j++)
	{
		if (board[j][i] == other)
			check = true;
		if (check && board[j][i] == same)
			return true;
		if (board[j][i] == '-')
			break;
	}
	// SW
	check = false;
	for (int i = x - 1, j = y + 1; i >= 0 && j < 8; i--, j++)
	{
		if (board[j][i] == other)
			check = true;
		if (check && board[j][i] == same)
			return true;
		if (board[j][i] == '-')
			break;
	}
	// NW
	check = false;
	for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (board[j][i] == other)
			check = true;
		if (check && board[j][i] == same)
			return true;
		if (board[j][i] == '-')
			break;
	}
	return false;
}

void Othello::tryToChangeThisShit(int x, int y)
{
	bool check;

	char same = this->currentPlayer;
	char other = this->currentPlayer == 'B' ? 'W' : 'B';

	// E
	check = false;
	for (int i = x + 1; i < 8; i++)
	{
		if (board[y][i] == other)
			check = true;
		if (check && board[y][i] == same)
		{
			for (int ii = i - 1; ii > x; ii--)
				board[y][ii] = currentPlayer;
			break;
		}
		if (board[y][i] == '-')
			break;
	}
	// W
	check = false;
	for (int i = x - 1; i >= 0; i--)
	{
		if (board[y][i] == other)
			check = true;
		if (check && board[y][i] == same)
		{
			for (int ii = i + 1; ii < x; ii++)
				board[y][ii] = currentPlayer;
			break;
		}
		if (board[y][i] == '-')
			break;
	}

	// N
	check = false;
	for (int i = y - 1; i >= 0; i--)
	{
		if (board[i][x] == other)
			check = true;
		if (check && board[i][x] == same)
		{
			for (int ii = i + 1; ii < y; ii++)
				board[y][ii] = currentPlayer;
			break;
		}
		if (board[i][x] == '-')
			break;
	}
	// S
	check = false;
	for (int i = y + 1; i < 8; i++)
	{
		if (board[i][x] == other)
			check = true;
		if (check && board[i][x] == same)
		{
			for (int ii = i - 1; ii > y; ii--)
				board[ii][x] = currentPlayer;
			break;
		}
		if (board[i][x] == '-')
			break;
	}

	// NE
	check = false;
	for (int i = x + 1, j = y - 1; i < 8 && j >= 0; i++, j--)
	{
		if (board[j][i] == other)
			check = true;
		if (check && board[j][i] == same)
		{
			for (int ii = i - 1, jj = j + 1; ii > x && jj < y; ii--, jj++)
				board[jj][ii] = currentPlayer;
			break;
		}
		if (board[j][i] == '-')
			break;
	}

	// SE
	check = false;
	for (int i = x + 1, j = y + 1; i < 8 && j < 8; i++, j++)
	{
		if (board[j][i] == other)
			check = true;
		if (check && board[j][i] == same)
		{
			for (int ii = i - 1, jj = j - 1; ii > x && jj > y; ii--, jj--)
				board[jj][ii] = currentPlayer;
			break;
		}
		if (board[j][i] == '-')
			break;
	}
	// SW
	check = false;
	for (int i = x - 1, j = y + 1; i >= 0 && j < 8; i--, j++)
	{
		if (board[j][i] == other)
			check = true;
		if (check && board[j][i] == same)
		{
			for (int ii = i + 1, jj = j - 1; ii < x && jj > y; ii++, jj--)
				board[jj][ii] = currentPlayer;
			break;
		}
		if (board[j][i] == '-')
			break;
	}
	// NW
	check = false;
	for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (board[j][i] == other)
			check = true;
		if (check && board[j][i] == same)
		{
			for (int ii = i + 1, jj = j + 1; ii < x && jj < y; ii++, jj++)
				board[jj][ii] = currentPlayer;
			break;
		}
		if (board[j][i] == '-')
			break;
	}
}

void Othello::moveThisFuck(int x, int y)
{
	int xx = x - 1;
	int yy = y - 1;
	board[xx][yy] = this->currentPlayer;
	tryToChangeThisShit(yy, xx);

	switchCurrentPlayer();
}

int main()
{
	int n;
	char option;
	int x, y, num1, num2;
	int lineCount;
	int numCase = 0;

	std::string line;

	std::getline(std::cin, line);

	n = std::stoi(line);

	while (n--)
	{
		if (numCase++)
			std::cout << '\n';
		Othello othello;
		// read 8 lines
		lineCount = 8;

		while (lineCount--)
		{
			std::getline(std::cin, line);

			for (int i = 0; i < 8; i++)
			{
				othello.setBlock(i, 8 - lineCount - 1, line[i]);
			}
		}

		// othello.printBoard();
		std::getline(std::cin, line);
		// who is the current player
		othello.setCurrentPlayer(line[0]);

		while (std::getline(std::cin, line))
		{
			if (line[0] == 'Q')
			{
				// print board
				othello.printBoard();
				break;
			}

			if (line[0] == 'L')
			{
				// list all possible moves
				othello.getAllPossibleMoves();
				othello.listAllPossibleMoves();
			}
			else if (line[0] == 'M')
			{
				// do a move
				num1 = int(line[1] - '0');
				num2 = int(line[2] - '0');
				othello.moveThisFuck(num1, num2);
				othello.printSummary();
			}
		}
	}

	return 0;
}
