// Solution

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    vector<int> squares(nums.size());

    for (int i = 0; i < nums.size(); i++)
    {
        squares[i] = nums[i] * nums[i];
    }

    sort(squares.begin(), squares.end());

    return squares;
}

int main()
{
    vector<int> nums = {-4, -1, 0, 3, 10};

    vector<int> sortedSquaresResult = sortedSquares(nums);

    cout << "Sorted squares: ";
    for (int num : sortedSquaresResult)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
