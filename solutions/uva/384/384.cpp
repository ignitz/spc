/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=320
 * 384
*/

// 1. Its first character is either a ’D’ or an ’E’.
// 2. The first character is followed by a string of one or more ’F’s.
// 3. The string of one or more ’F’s is followed by either a Slump or a ’G’. The Slump or ’G’ that
// follows the F’s ends the Slump. For example DFFEFFFG is a Slump since it has a ’D’ for its
// first character, followed by a string of two F’s, and ended by the Slump ’EFFFG’.
// 4. Nothing else is a Slump.
// A Slimp is a character string that has the following properties:
// 1. Its first character is an ’A’.
// 2. If it is a two character Slimp then its second and last character is an ’H’.
// 3. If it is not a two character Slimp then it is in one of these two forms:
// a) ’A’ followed by ’B’ followed by a Slimp followed by a ’C’.
// b) ’A’ followed by a Slump (see above) followed by a ’C’.
// 4. Nothing else is a Slimp.

#include <iostream>

struct Tuple
{
    bool check;
    int size;
};

Tuple checkSlump(std::string str)
{
    std::string aux;
    int count = 0;
    if (str.front() == 'D' || str.front() == 'E')
    {
        aux = str.substr(1);
        count++;
        if (aux.front() == 'F')
        {
            aux = aux.substr(1);
            count++;
            while (aux.front() == 'F')
            {
                aux = aux.substr(1);
                count++;
            }
            if (aux.front() == 'G')
            {
                count++;
                Tuple response;
                response.check = true;
                response.size = count;

                return response;
            }
            else
            {
                auto response = checkSlump(aux);
                if (response.check)
                {
                    response.size += count;
                    return response;
                }
            }
        }
    }
    Tuple response;
    response.check = false;
    response.size = count;
    return response;
}

Tuple checkSlimp(std::string str)
{
    std::string aux;
    int count = 0;

    aux = str;
    if (aux.length() == 0)
    {
        Tuple response;
        response.check = false;
        response.size = count;
        return response;
    }

    if (aux.compare("AH") == 0)
    {
        Tuple response;
        response.check = true;
        response.size = 2;
        return response;
    }
    if (aux.front() == 'A')
    {
        aux = aux.substr(1);
        count++;
        if (aux.back() == 'C')
        {
            aux = aux.substr(0, aux.length() - 1);
            count++;

            if (aux.front() == 'B')
            {
                aux = aux.substr(1);
                count++;

                auto response = checkSlimp(aux);
                if (response.check)
                {
                    response.size += count;
                    return response;
                }
            }
            else
            {

                auto response = checkSlump(aux);
                if (response.check)
                {
                    response.size += count;
                    return response;
                }
            }
        }
    }

    Tuple response;
    response.check = false;
    response.size = count;
    return response;
}

bool checkSlurpys(std::string str)
{
    // std::cout << str << '\n';
    // check if AH or or the last G
    if (str.substr(0, 2).compare("AH") == 0)
    {
        auto aux = str.substr(2);
        auto response = checkSlump(aux);

        if (response.check && aux.substr(response.size).size() == 0)
            return true;
        else
            return false;
    }
    else
    {
        auto response = checkSlimp(str.substr(0, str.find_last_of('C') + 1));
        if (response.check)
        {
            auto aux = str.substr(str.find_last_of('C') + 1);
            auto response = checkSlump(aux);
            if (response.check && aux.substr(response.size).size() == 0)
                return true;
        }
    }

    return false;
}

int maratona()
{
    int n;
    std::cout << "SLURPYS OUTPUT\n";
    int count = 0;
    std::cin >> n;
    unsigned int state;

    std::string input;

    while (count < n)
    {
        std::cin >> input;
        if (checkSlurpys(input))
        {
            std::cout << "YES" << '\n';
        }
        else
        {
            std::cout << "NO" << '\n';
        }
        count++;
    }
    std::cout << "END OF OUTPUT\n";
    return 0;
}

int testeSlumpSlimp()
{
    std::string slumps[5] = {"DFG",
                             "EFG",
                             "DFFFFFG",
                             "DFDFDFDFG",
                             "DFEFFFFFG"};
    std::string notSlumps[5] = {"DFEFF",
                                "EFAHG",
                                "DEFG",
                                "DG",
                                "EFFFFDG"};
    std::string slimps[7] = {"AH",
                             "ABAHC",
                             "ABABAHCC",
                             "ADFGC",
                             "ADFFFFGC",
                             "ABAEFGCC",
                             "ADFDFGC"};
    std::string notSlimps[6] = {"ABC",
                                "ABAH",
                                "DFGC",
                                "ABABAHC",
                                "SLIMP",
                                "ADGC"};
    std::cout << "Slumps" << '\n';
    for (auto x : slumps)
    {
        std::cout << checkSlump(x).check << " " << checkSlump(x).size << '\n';
    }
    std::cout << "Not Slumps" << '\n';
    for (auto x : notSlumps)
    {
        std::cout << checkSlump(x).check << " " << checkSlump(x).size << '\n';
    }
    std::cout << "Slimps" << '\n';
    for (auto x : slimps)
    {
        std::cout << checkSlimp(x).check << " " << checkSlimp(x).size << '\n';
    }
    std::cout << "Not Slimps" << '\n';
    for (auto x : notSlimps)
    {
        std::cout << checkSlimp(x).check << " " << checkSlimp(x).size << '\n';
    }
    return 0;
}

int testeSlurpys()
{
    std::string slurpys[3] = {"AHDFG",
                              "ADFGCDFFFFFG",
                              "ABAEFGCCDFEFFFFFG"};
    std::string notSlurpys[3] = {"AHDFGA",
                                 "DFGAH",
                                 "ABABCC"};
    std::cout << "Slurpys" << '\n';
    for (auto x : slurpys)
    {
        std::cout << checkSlurpys(x) << '\n';
    }
    std::cout << "Not Slurpys" << '\n';
    for (auto x : notSlurpys)
    {
        std::cout << checkSlurpys(x) << '\n';
    }

    return 0;
}

int main()
{
    maratona();
    return 0;
}