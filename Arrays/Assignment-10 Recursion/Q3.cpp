#include <iostream>
using namespace std;

void printSubsets(string set, string subset, int i)
{
    if (i == set.length())
    {
        cout << subset << " ";
        return;
    }
    printSubsets(set, subset, i + 1);
    printSubsets(set, subset + set[i], i + 1);
}

int main()
{
    string set = "abc";
    string subset = "";
    int i = 0;
    printSubsets(set, subset, i);
    return 0;
}
