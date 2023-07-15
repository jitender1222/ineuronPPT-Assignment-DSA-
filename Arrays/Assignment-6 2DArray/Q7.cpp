#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    int num = 1;
    int left = 0;
    int right = n - 1;
    int top = 0;
    int bottom = n - 1;

    while (num <= n * n)
    {
        for (int i = left; i <= right; i++)
        {
            matrix[top][i] = num;
            num++;
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            matrix[i][right] = num;
            num++;
        }
        right--;

        for (int i = right; i >= left; i--)
        {
            matrix[bottom][i] = num;
            num++;
        }
        bottom--;

        for (int i = bottom; i >= top; i--)
        {
            matrix[i][left] = num;
            num++;
        }
        left++;
    }

    return matrix;
}

int main()
{
    int n = 3;

    vector<vector<int>> result = generateMatrix(n);

    for (const auto &row : result)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
