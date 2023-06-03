

// Solution

#include <iostream>
#include <vector>

using namespace std;

int maxCount(vector<vector<int>> &ops, int m, int n)
{
    int minRow = m;
    int minCol = n;

    for (const vector<int> &op : ops)
    {
        minRow = min(minRow, op[0]);
        minCol = min(minCol, op[1]);
    }

    return minRow * minCol;
}

int main()
{
    int m = 3;
    int n = 3;
    vector<vector<int>> ops = {{2, 2}, {3, 3}};

    int maxIntegers = maxCount(ops, m, n);

    cout << "Number of maximum integers: " << maxIntegers << endl;

    return 0;
}
