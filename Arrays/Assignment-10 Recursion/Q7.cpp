#include <iostream>
using namespace std;

void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

void permutations(string str, int l, int r)
{
    if (l == r)
    {
        cout << str << " ";
        return;
    }
    for (int i = l; i <= r; i++)
    {
        swap(str[l], str[i]);
        permutations(str, l + 1, r);
        swap(str[l], str[i]); // backtrack
    }
}

int main()
{
    string str = "cd";
    int n = str.length();
    permutations(str, 0, n - 1);
    return 0;
}
