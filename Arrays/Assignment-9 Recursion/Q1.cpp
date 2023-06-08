#include <iostream>
using namespace std;

bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;
    return (n & (n - 1)) == 0;
}

int main()
{
    int n = 16;
    bool result = isPowerOfTwo(n);
    cout << boolalpha << result << endl;
    return 0;
}
