/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1083
 * 10142 - Australian Voting
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>

std::queue<int> split(const std::string &s, char delimiter)
{
	std::queue<int> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter))
	{
		tokens.push(std::stoi(token));
	}
	return tokens;
}

// Function to find the maximum element
int findMax(std::set<int> my_set)
{

	// Get the maximum element
	int max_element;
	if (!my_set.empty())
		max_element = *my_set.rbegin();

	// return the maximum element
	return max_element;
}

// Function to find the minimum element
int findMin(std::set<int> my_set)
{

	// Get the minimum element
	int min_element;
	if (!my_set.empty())
		min_element = *my_set.begin();

	// return the minimum element
	return min_element;
}

int doVote()
{
	int countCase, numberOfCases, n, index;
	int total;
	std::string line;
	std::vector<std::pair<int, std::string>> candVotes;
	std::vector<std::queue<int>> votes;
	std::set<int> setOfValues;

	std::getline(std::cin, line);

	countCase = 1;
	numberOfCases = std::stoi(line);

	while (countCase++ <= numberOfCases)
	{
		std::getline(std::cin, line);
		if (line.length() == 0)
			std::getline(std::cin, line);
		if (line.length() == 0)
			break;
		if (countCase != 2)
			std::cout << '\n';

		n = std::stoi(line);
		candVotes.resize(n, std::make_pair(0, ""));

		index = 0;

		while (n--)
		{
			std::getline(std::cin, line);
			candVotes[index].second = line;
			index++;
		}

		while (std::getline(std::cin, line))
		{
			if (line.length() == 0)
				break;
			votes.push_back(split(line, ' '));
		}

		while (true)
		{
			for (int i = 0; i < votes.size(); i++)
			{
				// elimina os votos dos candidatos excluidos
				while (!votes[i].empty() && candVotes[votes[i].front() - 1].first < 0)
					votes[i].pop();
				if (!votes[i].empty())
					if (candVotes[votes[i].front() - 1].first >= 0)
						candVotes[votes[i].front() - 1].first++;
			}

			// count total of valid votes
			total = 0;

			for (auto &cand : candVotes)
			{
				if (cand.first >= 0)
				{
					total += cand.first;
					setOfValues.insert(cand.first);
				}
			}

			//empate
			if (setOfValues.size() == 1)
			{
				break;
			}

			// ganhou
			if (2 * findMax(setOfValues) > total)
			{
				for (auto &cand : candVotes)
				{
					if (findMin(setOfValues) == cand.first)
						cand.first = -1;
				}
				break;
			}

			// elimina os piores candidatos pra próxima rodada
			for (auto &cand : candVotes)
			{
				if (findMin(setOfValues) >= cand.first)
					cand.first = -1;
				else
					cand.first = 0;
			}

			// limpar pra tentar de novo
			setOfValues.clear();
		}

		// printa ganhadores
		{
			auto maxVotes = findMax(setOfValues);
			// printar quem ainda tá empatado ou quem é o campeao
			for (auto &cand : candVotes)
			{
				if (cand.first == maxVotes)
					std::cout << cand.second << '\n';
			}
			// std::cout << '\n';
		}

		// clear containers
		candVotes.clear();
		for (auto &vote : votes)
		{
			while (!vote.empty())
				vote.pop();
		}
		votes.clear();
		setOfValues.clear();
	}
	return 0;
}

int main()
{
	doVote();
	// std::set<int> myset;
	// myset.insert(1);
	// myset.insert(2);
	// myset.insert(4);
	// std::cout << findMax(myset) << '\n';
	// std::queue<int> queue;

	// std::cout << queue.front() << '\n';
	return 0;
}
