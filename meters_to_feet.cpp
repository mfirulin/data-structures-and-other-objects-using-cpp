#include <cstdlib>
#include <cassert>
#include <iostream>
#include <iomanip>

using namespace std;

// parameter m - meters, should be positive.
// return - feet
double sum(double m)
{
    assert(m >= 0);

    return m * 3.2808;
}

void setup_cout_fraction(int fraction_digits)
{
    assert(fraction_digits > 0);

    cout.precision(fraction_digits);
    cout.setf(ios::fixed, ios::floatfield);
    if (fraction_digits > 0)
        cout.setf(ios::showpoint);
    else
        cout.unsetf(ios::showpoint);
        
}

int main()
{
    const int START = 5;
    const int END = 100;
    const int STEP = 5;
    const int FRACTION = 2;
    const int WIDTH = 9;
    const string HEADER1 = "meters";
    const string HEADER2 = "feet";

    setup_cout_fraction(FRACTION);

    cout << setw(WIDTH) << HEADER1 << ' ';
    cout << setw(WIDTH) << HEADER2 << endl;

    for (int m = START; m <= END; m += STEP) {
        double f = sum(m);
        cout << setw(WIDTH) << m << ' ';
        cout << setw(WIDTH) << f << endl;
    }

    return EXIT_SUCCESS;
}