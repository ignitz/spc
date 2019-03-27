/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=433
 * 492 - Pig-Latin
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <regex>

bool isVogal(char c)
{
	std::set<char> chars;
	char const *charList = "AEIOUaeiou";
	chars.insert(charList, charList + strlen(charList));
	if (chars.find(c) != chars.end())
		return true;
	else
		return false;
}

std::string convertPiglatin(std::string line)
{
	std::string response;
	std::smatch matches;

	std::string str = line;
	while (std::regex_search(str, matches, std::regex("[A-Za-z]+")))
	{
		std::string prefix = matches.prefix().str();

		std::string strAdd;

		if (isVogal(matches.str(0)[0]))
			strAdd = matches.str(0) + "ay";
		else
			strAdd = matches.str(0).substr(1) + matches.str(0)[0] + "ay";
		response += prefix.replace(matches.position(), matches.length(), strAdd);
		str = matches.suffix().str();
	}

	response += str;
	return response;
}

// std::string convertPiglatin(std::string line)
// {
// 	std::string response;
// 	response = std::regex_replace(line, std::regex("[AEIOUaeiou][A-Za-z]*"), "$0ay");
// 	// response = std::regex_replace(response, std::regex("[BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz][A-Za-z]*"), "$0ay");
// 	// response = std::regex_replace(response, std::regex("\\b([BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz])([A-Za-z]*)\\b"), "$2$1ay");
// 	return response;
// }

void inputByChar()
{
	std::string content;
	char c;
	while ((c = std::getc(stdin)) != EOF)
	{
		content.push_back(c);
	}
	if (content.back() != '\n')
		content.push_back('\n');
	std::cout << convertPiglatin(content);
}

void inputByLine()
{
	std::string line;
	while (std::getline(std::cin, line))
	{
		std::cout << convertPiglatin(line) << '\n';
	}
}

int main()
{
	// inputByChar();
	inputByLine();
	return 0;
}
