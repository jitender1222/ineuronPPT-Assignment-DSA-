

// Solution

#include <iostream>
#include <vector>

using namespace std;

vector<int> shuffleArray(vector<int> &nums, int n)
{
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        result.push_back(nums[i]);
        result.push_back(nums[i + n]);
    }

    return result;
}

int main()
{
    vector<int> nums = {2, 5, 1, 3, 4, 7};
    int n = 3;

    vector<int> shuffledArray = shuffleArray(nums, n);

    cout << "Shuffled array: ";
    for (int num : shuffledArray)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
