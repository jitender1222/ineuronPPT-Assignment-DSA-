#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;
    for (int num : nums)
    {
        actualSum += num;
    }
    return expectedSum - actualSum;
}

int main()
{
    vector<int> nums = {3, 0, 1};
    int missingNum = missingNumber(nums);
    cout << missingNum << endl;
    return 0;
}
