/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=54
 * 118
*/

#include <iostream>
#include <vector>
#include <bitset>

bool DEBUG = false;
std::vector<std::vector<bool>> markFallPosition;

u_int8_t getNumberByChar(char c)
{
    switch (c)
    {
    case 'E':
        return 1;
    case 'N':
        return 4;
    case 'W':
        return 16;
    case 'S':
        return 64;
    }
    return 0;
}

char getCharByNumber(u_int8_t n)
{
    switch (n)
    {
    case 1:
        return 'E';
    case 4:
        return 'N';
    case 16:
        return 'W';
    case 64:
        return 'S';
    }
    return 'A';
}

class Robo
{
  private:
    uint8_t direcao;
    int x;
    int y;
    int max_x;
    int max_y;
    bool fallen;

  public:
    Robo(int x, int y, int n, int m, char init_dir);
    ~Robo();
    void rotateLeft();
    void rotateRight();
    void goForward();
    void receiveCommand(char);
    bool checkIfFall(int new_x, int new_y);
    void printPosition();
};

Robo::Robo(int x, int y, int n, int m, char init_dir)
{
    this->fallen = false;
    this->x = x;
    this->y = y;
    this->max_x = n;
    this->max_y = m;
    this->direcao = getNumberByChar(init_dir);
}

Robo::~Robo() {}

void Robo::rotateLeft()
{
    this->direcao = (this->direcao << 2) | (this->direcao >> 6);
}

void Robo::rotateRight()
{
    this->direcao = (this->direcao >> 2) | (this->direcao << 6);
}

void Robo::goForward()
{
    switch (this->direcao)
    {
    case 1:
        if (this->checkIfFall(this->x + 1, this->y))
            return;
        this->x++;
        break;
    case 4:
        if (this->checkIfFall(this->x, this->y + 1))
            return;
        this->y++;
        break;
    case 16:
        if (this->checkIfFall(this->x - 1, this->y))
            return;
        this->x--;
        break;
    case 64:
        if (this->checkIfFall(this->x, this->y - 1))
            return;
        this->y--;
        break;
    default:
        std::cout << "ERRO1 " << static_cast<int>(this->direcao) << '\n';
    }
}

void Robo::receiveCommand(char c)
{
    if (this->fallen)
        return;
    switch (c)
    {
    case 'F':
        this->goForward();
        break;
    case 'L':
        this->rotateLeft();
        break;
    case 'R':
        this->rotateRight();
        break;
    default:
        std::cout << "ERRO2" << '\n';
    }
}

bool Robo::checkIfFall(int new_x, int new_y)
{
    if (new_x > this->max_x || new_x < 0 || new_y > this->max_y || new_y < 0)
    {
        if (markFallPosition[this->x + 1][this->y + 1])
            return true;
        markFallPosition[this->x + 1][this->y + 1] = true;
        this->fallen = true;
    }
    return this->fallen;
}

void Robo::printPosition()
{
    // std::bitset<8> bitsDir(this->direcao);
    std::cout << static_cast<int>(this->x) << ' ' << static_cast<int>(this->y)
              << ' ' << getCharByNumber(this->direcao);

    if (this->fallen)
        std::cout << " LOST\n";
    else
        std::cout << '\n';
}

void doDirections(int x, int y, int n, int m, char init_dir, std::string directions)
{
    using namespace std;

    // std::cout << n << "\t" << m << "\t" << x << "\t" << y << "\t" << init_dir << '\n';

    Robo robo(x, y, n, m, init_dir);
    if (DEBUG)
    {
        std::cout << "Posicao inicial: ";
        robo.printPosition();
    }

    for (auto &eachChar : directions)
    {
        if (DEBUG)
            std::cout << "Recebendo comando " << eachChar << '\n';
        robo.receiveCommand(eachChar);
        if (DEBUG)
        {
            std::cout << "Nova posição ";
            robo.printPosition();
        }
    }

    robo.printPosition();
}

int main()
{
    using namespace std;
    string input;
    int n, m;

    int x, y;
    char init_dir;
    // n is x max
    // m is y axis max
    cin >> n >> m;
    markFallPosition.resize(100, vector<bool>(100, false));

    int count = 1;

    while (cin >> x)
    {
        // if (count == 50)
        //     std::cout << "/* message */" << '\n';
        string directions;
        cin >> y;
        cin >> init_dir;
        cin >> directions;
        doDirections(x, y, n, m, init_dir, directions);
        count++;
    }
    return 0;
}
