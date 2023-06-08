#include <iostream>
using namespace std;

int sumOfNaturalNumbers(int n)
{
    return (n * (n + 1)) / 2;
}

int main()
{
    int n = 5;
    int sum = sumOfNaturalNumbers(n);
    cout << sum << endl;
    return 0;
}
