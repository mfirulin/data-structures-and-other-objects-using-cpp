#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

class Throttle
{
public:
    Throttle();
    Throttle(int top_position);
    Throttle(int top_position, int position);

    void shut_off();
    void shift(int amount);
    int top_position() const;
    int position() const;
    double flow() const;
    bool is_on() const;
    bool is_half() const;


private:
    int pos = 0;
    int top_pos = 0;
};

Throttle::Throttle()
{
    top_pos = 1;
}

Throttle::Throttle(int top_position)
{
    top_pos = top_position;
}

Throttle::Throttle(int top_position, int position)
{
    top_pos = top_position;
    pos = position;
}

void Throttle::shut_off()
{
    pos = 0;
}

void Throttle::shift(int amount)
{
    pos += amount;

    if (pos < 0)
        pos = 0;
    else if (pos > top_pos)
        pos = top_pos;
}

int Throttle::position() const
{
    return pos;
}

int Throttle::top_position() const
{
    return top_pos;
}

double Throttle::flow() const
{
    return (double)pos / top_pos;
}

bool Throttle::is_on() const
{
    return pos > 0;
}

bool Throttle::is_half() const
{
    return flow() > (double)top_pos / 2 / top_pos;
}

int main()
{
    const int PRECISION = 1;
    const int WIDTH = 5;
    Throttle throttle(7);

    cout.precision(PRECISION);

    cout << setw(WIDTH) << throttle.position() << setw(WIDTH) << throttle.flow() << setw(WIDTH) << throttle.is_half() << endl;

    for (int i = 0; i < throttle.top_position(); i++) {
        throttle.shift(1);
        cout << setw(WIDTH) << throttle.position() << setw(WIDTH) << throttle.flow() << setw(WIDTH) << throttle.is_half() << endl;
    }

    return EXIT_SUCCESS;
}