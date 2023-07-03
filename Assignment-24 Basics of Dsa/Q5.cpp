#include <iostream>
#include <vector>
using namespace std;

int nthUglyNumber(int n)
{
    vector<int> uglyNumbers(n);
    uglyNumbers[0] = 1;

    int i2 = 0, i3 = 0, i5 = 0;
    int nextMultipleOf2 = 2, nextMultipleOf3 = 3, nextMultipleOf5 = 5;

    for (int i = 1; i < n; i++)
    {
        int nextUglyNumber = min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));
        uglyNumbers[i] = nextUglyNumber;

        if (nextUglyNumber == nextMultipleOf2)
        {
            i2++;
            nextMultipleOf2 = uglyNumbers[i2] * 2;
        }
        if (nextUglyNumber == nextMultipleOf3)
        {
            i3++;
            nextMultipleOf3 = uglyNumbers[i3] * 3;
        }
        if (nextUglyNumber == nextMultipleOf5)
        {
            i5++;
            nextMultipleOf5 = uglyNumbers[i5] * 5;
        }
    }

    return uglyNumbers[n - 1];
}

int main()
{
    int n = 10;
    int ugly = nthUglyNumber(n);
    cout << ugly << endl;
    return 0;
}
