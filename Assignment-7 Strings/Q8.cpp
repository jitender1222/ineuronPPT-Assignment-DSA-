#include <iostream>
#include <vector>
using namespace std;

bool checkStraightLine(vector<vector<int>> &coordinates)
{
    int n = coordinates.size();
    if (n <= 2)
        return true;

    int x0 = coordinates[0][0];
    int y0 = coordinates[0][1];
    int x1 = coordinates[1][0];
    int y1 = coordinates[1][1];

    for (int i = 2; i < n; i++)
    {
        int x = coordinates[i][0];
        int y = coordinates[i][1];

        if ((y1 - y0) * (x - x0) != (y - y0) * (x1 - x0))
            return false;
    }

    return true;
}

int main()
{
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    vector<vector<int>> coordinates(n, vector<int>(2));
    cout << "Enter the coordinates of the points: ";
    for (int i = 0; i < n; i++)
    {
        cin >> coordinates[i][0] >> coordinates[i][1];
    }

    bool isStraightLine = checkStraightLine(coordinates);

    cout << (isStraightLine ? "true" : "false") << endl;

    return 0;
}
