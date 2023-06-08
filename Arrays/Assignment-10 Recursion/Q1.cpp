#include <iostream>
using namespace std;

bool isPowerOfThree(int n)
{
    if (n <= 0)
        return false;
    while (n % 3 == 0)
    {
        n /= 3;
    }
    return n == 1;
}

int main()
{
    int n = 27;
    bool result = isPowerOfThree(n);
    cout << boolalpha << result << endl;
    return 0;
}
