#include <cstdlib>
#include <cassert>
#include <iostream>

using namespace std;

// parameter n - should be positive
// return - sum 1 + 2 + ... + n
int sum(int n)
{
    assert(n >= 0);

    int sum = 0;

    while (n) {
        sum += n;
        n--;
    }

    return sum;
}

int main()
{
    cout << sum(9) << endl;
    return EXIT_SUCCESS;
}