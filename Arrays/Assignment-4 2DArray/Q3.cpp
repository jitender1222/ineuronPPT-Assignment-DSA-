

// Solution

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> transposeMatrix(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> transpose(n, vector<int>(m));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    return transpose;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    vector<vector<int>> transpose = transposeMatrix(matrix);

    cout << "Transpose of matrix:" << endl;
    for (const vector<int> &row : transpose)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
