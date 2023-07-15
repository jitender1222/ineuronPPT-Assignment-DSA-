#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> multiply(vector<vector<int>> &mat1, vector<vector<int>> &mat2)
{
    int m = mat1.size();
    int k = mat1[0].size();
    int n = mat2[0].size();

    vector<vector<int>> result(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int x = 0; x < k; x++)
            {
                result[i][j] += mat1[i][x] * mat2[x][j];
            }
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> mat1 = {{1, 0, 0},
                                {-1, 0, 3}};
    vector<vector<int>> mat2 = {{7, 0, 0},
                                {0, 0, 0},
                                {0, 0, 1}};

    vector<vector<int>> result = multiply(mat1, mat2);

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
