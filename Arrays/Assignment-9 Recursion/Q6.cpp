#include <iostream>
using namespace std;

int nthTermAP(int a, int d, int N)
{
    return a + (N - 1) * d;
}

int main()
{
    int a = 2;
    int d = 1;
    int N = 5;
    int nthTerm = nthTermAP(a, d, N);
    cout << nthTerm << endl;
    return 0;
}
