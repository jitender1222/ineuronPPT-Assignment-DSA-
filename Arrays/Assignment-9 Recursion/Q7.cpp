#include <iostream>
#include <algorithm>
using namespace std;

void permute(string str, int l, int r)
{
    if (l == r)
        cout << str << " ";
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(str[l], str[i]);
            permute(str, l + 1, r);
            swap(str[l], str[i]);
        }
    }
}

int main()
{
    string S = "ABC";
    int n = S.length();
    permute(S, 0, n - 1);
    return 0;
}
