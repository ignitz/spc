/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=46
 * 110 - Meta-Loopless Sorts
*/

#include <iostream>
#include <vector>

class ProgramPascal
{
  private:
	int numVars;
	std::vector<char> vars;

  public:
	ProgramPascal(int numVars);
	~ProgramPascal();
	void insertSpaces(int level, bool elseIf);
	void createBlock(int i);
	void createProgram();
	void swap(int x, int y);
	void printWriteln(int i);
};

ProgramPascal::ProgramPascal(int numVars)
{
	this->numVars = numVars;
}

ProgramPascal::~ProgramPascal()
{
}

void ProgramPascal::insertSpaces(int level, bool elseIf = false)
{
	// level = 0 no spaces
	// level = 1 two spaces
	// ...
	// level = n 2n spaces0
	if (elseIf)
	{
		for (int i = 0; i < level - 1; i++)
			std::cout << "  ";
		std::cout << " ";
	}
	else
	{
		for (int i = 0; i < level; i++)
			std::cout << "  ";
	}
}

// void ProgramPascal::createBlock(int i, int j)
// {
// 	this->level++;
// 	if (j == -1)
// 	{
// 		this->level--;
// 		createBlock(i + 1, i);
// 		return;
// 	}

// 	if (i == numVars)
// 	{
// 		insertSpaces();
// 		std::cout << "writeln(";
// 		for (auto &c : vars)
// 		{
// 			if (c != vars[0])
// 				std::cout << ",";
// 			std::cout << c;
// 		}
// 		std::cout << ")\n";
// 		this->level--;
// 		return;
// 	}
// 	insertSpaces();
// 	// if (lastIf)
// 	// 	std::cout << "else ";
// 	std::cout << "if " << vars[j] << " < " << vars[j + 1] << " then\n";

// 	createBlock(i, j - 1);

// 	// aux = vars[j + 1];
// 	// vars[j + 1] = vars[j];
// 	// vars[j] = aux;
// 	aux = vars[j + 1];
// 	vars[j + 1] = vars[j];
// 	vars[j] = aux;

// 	insertSpaces();
// 	std::cout << "else\n";
// 	createBlock(i + 1, i);
// 	this->level--;
// }

void ProgramPascal::printWriteln(int i)
{
	// print in reverse mode
	insertSpaces(i);
	std::cout << "writeln(";
	for (int index = numVars - 1; index >= 0; index--)
	{
		if (vars[index] != vars.back())
			std::cout << ",";
		std::cout << vars[index];
	}
	std::cout << ")\n";
}

void ProgramPascal::createBlock(int i)
{
	if (i == numVars)
	{
		printWriteln(i);
		return;
	}

	insertSpaces(i, true);
	for (int j = i; j >= 1; j--)
		vars[j] = vars[j - 1];
	for (int j = 0; j < i; j++)
	{
		std::cout << " if "
				  << vars[j + 1] << " < " << char('a' + char(i))
				  << " then" << '\n';
		vars[j] = 'a' + char(i);
		createBlock(i + 1);
		vars[j] = vars[j + 1];
		insertSpaces(i);
		std::cout << "else";
	}
	std::cout << '\n';
	vars[i] = 'a' + char(i);
	createBlock(i + 1);
}

void ProgramPascal::swap(int x, int y)
{
	vars[x] = vars[x] + vars[y];
	vars[y] = vars[x] - vars[y];
	vars[x] = vars[x] - vars[y];
}

void ProgramPascal::createProgram()
{
	std::cout << "program sort(input,output);\nvar\n";

	for (char a = 'a'; a < 'a' + numVars; a++)
	{
		vars.push_back(a);
	}

	for (auto &c : vars)
	{
		if (c != 'a')
			std::cout << ",";
		std::cout << c;
	}

	std::cout << " : integer;\nbegin\n  readln(";
	for (auto &c : vars)
	{
		if (c != 'a')
			std::cout << ",";
		std::cout << c;
	}
	std::cout << ");\n";

	// insert ifs
	createBlock(1);
	// end
	std::cout << "end.\n";
}

int main()
{
	int n, numVars;
	std::string line;

	std::cin >> n;
	// std::cout << "n = " << n << '\n';
	int count = 1;

	while (n--)
	{
		std::cin >> numVars;
		ProgramPascal program(numVars);

		if (count++ != 1)
			std::cout << '\n';

		program.createProgram();
		// std::cout << "numvars = " << numVars << '\n';
	}

	return 0;
}
