#include <iostream>
using namespace std;

int power(int N, int P)
{
    if (P == 0)
        return 1;
    return N * power(N, P - 1);
}

int main()
{
    int N = 5;
    int P = 2;
    int result = power(N, P);
    cout << result << endl;
    return 0;
}
