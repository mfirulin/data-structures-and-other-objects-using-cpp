#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

class Throttle
{
public:
    const int MAX_POSITION = 6;

    void shut_off();
    void shift(int amount);
    int position() const;
    double flow() const;
    bool is_on() const;
    bool is_half() const;


private:
    int pos = 0;
};

void Throttle::shut_off()
{
    pos = 0;
}

void Throttle::shift(int amount)
{
    pos += amount;

    if (pos < 0)
        pos = 0;
    else if (pos > MAX_POSITION)
        pos = MAX_POSITION;
}

int Throttle::position() const
{
    return pos;
}

double Throttle::flow() const
{
    return (double)pos / (double)MAX_POSITION;
}

bool Throttle::is_on() const
{
    return pos > 0;
}

bool Throttle::is_half() const
{
    return flow() > MAX_POSITION / 2 / (double)MAX_POSITION;
}

int main()
{
    const int PRECISION = 1;
    const int WIDTH = 5;
    Throttle throttle;

    cout.precision(PRECISION);

    cout << setw(WIDTH) << throttle.position() << setw(WIDTH) << throttle.flow() << setw(WIDTH) << throttle.is_half() << endl;

    for (int i = 0; i < throttle.MAX_POSITION; i++) {
        throttle.shift(1);
        cout << setw(WIDTH) << throttle.position() << setw(WIDTH) << throttle.flow() << setw(WIDTH) << throttle.is_half() << endl;
    }

    return EXIT_SUCCESS;
}