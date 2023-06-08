#include <iostream>
using namespace std;

int lastRemaining(int n)
{
    int remaining = 1;
    bool isLeftToRight = true;
    int step = 1;

    while (n > 1)
    {
        if (isLeftToRight || n % 2 == 1)
        {
            remaining += step;
        }
        n /= 2;
        step *= 2;
        isLeftToRight = !isLeftToRight;
    }

    return remaining;
}

int main()
{
    int n = 9;
    int lastNum = lastRemaining(n);
    cout << lastNum << endl;
    return 0;
}
