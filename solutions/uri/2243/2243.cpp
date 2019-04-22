/*
 * Yuri Niitsuma
 * 2011039023
 * https://www.urionlinejudge.com.br/judge/en/problems/view/2243
 * 2243 - Isosceles
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unistd.h>

#define LEFT 2
#define RIGHT 1

int max, nmax;

void printBlocks(std::vector<std::vector<int>> &blocks, int x, int y)
{
    // for (auto const &line : blocks)
    // {
    //     for (bool const &block : line)
    //     {
    //         if (block)
    //             std::cout << 'x';
    //         else
    //             std::cout << '_';
    //     }
    //     std::cout << '\n';
    // }
    std::cout << "\n\n========================\n\n";
    for (int i = 0; i < blocks.size(); i++)
    {
        std::cout << i << '\t';
        for (int j = 0; j < max; j++)
        {
            if (blocks[i][j] & 3)
            {
                if (i == x && j == y)
                    std::cout << '/';
                else
                    std::cout << blocks[i][j];
            }
            else
            {
                // std::cout << '_';
            }
        }
        std::cout << '\n';
    }
}

bool goDeeper(std::vector<std::vector<int>> &blocks, int x, int y, int direction)
{
    if (y < 0)
        return true;
    if (x > nmax - 1 || x < 0)
        return false;
    // std::cout << "x = " << x << '\t' << "y = " << y << '\n';
    // printBlocks(blocks, x, y);

    bool response = false;

    if (direction == LEFT)
    {
        if (blocks[x][y] & LEFT)
            response = goDeeper(blocks, x - 1, y - 1, LEFT);
        else
            return false;
        if (response == false)
            blocks[x][y] &= RIGHT;
    }
    else
    {
        if (blocks[x][y] & RIGHT)
            response = goDeeper(blocks, x + 1, y - 1, RIGHT);
        else
            return false;
        if (response == false)
            blocks[x][y] &= LEFT;
    }
    return response;
}

bool checkTriangle(std::vector<std::vector<int>> &blocks, int x, int y)
{
    if (y < 0)
        return true;
    if (x < 0)
        return false;
    bool response = false;
    if (blocks[x][y] == 0)
        return false;

    response = goDeeper(blocks, x - 1, y - 1, LEFT);
    response = response & goDeeper(blocks, x + 1, y - 1, RIGHT);

    if (response == false)
        blocks[x][y] = 0;

    return response;
}

int main()
{
    int n, input;
    std::cin >> n;
    nmax = n;

    std::vector<int> numbers(n, 0);

    std::cin >> input;
    numbers[0] = input > 0 ? 1 : 0;

    for (int i = 1; i < n; i++)
    {
        std::cin >> input;
        if (input > numbers[i - 1])
            numbers[i] = numbers[i - 1] + 1;
        else
            numbers[i] = input;
        // else if (input < numbers[i - 1])
        // {
        //     numbers[i] = input++;
        //     for (int k = i - 1; k > 0; k--)
        //     {
        //         if (input <= numbers[k])
        //             numbers[k] = input++;
        //         else
        //             break;
        //     }
        // }

        // else
        //     numbers[i] = numbers[i - 1];
    }

    numbers[nmax - 1] = numbers[nmax - 1] > 0 ? 1 : 0;

    for (int k = n - 2; k >= 0; k--)
    {
        if (numbers[k] > numbers[k + 1])
            numbers[k] = numbers[k + 1] + 1;
    }

    max = *std::max_element(numbers.begin(), numbers.end());

    // std::vector<std::vector<int>> blocks(n, std::vector<int>(max, 0));

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < numbers[i]; j++)
    //     {
    //         if (j <= i && j < nmax - i)
    //             blocks[i][j] = 3;
    //     }
    // }

    bool result;

    // printBlocks(blocks, 0, 0);

    // std::cout << max << '\n';

    // for (int j = max - 1; j >= 0; j--)
    // {
    //     for (int i = j; i < nmax - j; i++)
    //     {
    //         // std::cout << i << '\t' << j << '\n';
    //         if (blocks[i][j])
    //         {
    //             // printBlocks(blocks, i, j);
    //             // sleep(1);
    //             result = checkTriangle(blocks, i, j);
    //             if (result)
    //             {
    //                 std::cout << j + 1 << '\n';
    //                 return 0;
    //             }
    //         }
    //     }
    // }
    // std::cout << 0 << '\n';

    return 0;
}
