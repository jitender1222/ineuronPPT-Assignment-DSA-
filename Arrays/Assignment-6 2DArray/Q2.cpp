#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int left = 0;
    int right = m * n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int num = matrix[mid / n][mid % n];

        if (num == target)
        {
            return true;
        }
        else if (num < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 60}};
    int target = 3;

    bool result = searchMatrix(matrix, target);

    cout << boolalpha << result << endl;

    return 0;
}
