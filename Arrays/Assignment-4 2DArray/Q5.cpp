

// Solution

#include <iostream>

using namespace std;

int countCompleteRows(int n)
{
    int row = 0;
    int coins = 0;

    while (coins <= n)
    {
        row++;
        coins += row;
    }

    return row - 1;
}

int main()
{
    int n = 5;

    int completeRows = countCompleteRows(n);

    cout << "Number of complete rows: " << completeRows << endl;

    return 0;
}
