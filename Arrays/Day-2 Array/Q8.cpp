/*

Question 8
You are given an integer array nums and an integer k.

In one operation, you can choose any index i where 0 <= i < nums.length and change nums[i] to nums[i] + x where x is an integer from the range [-k, k]. You can apply this operation at most once for each index i.

The score of nums is the difference between the maximum and minimum elements in nums.

Return the minimum score of nums after applying the mentioned operation at most once for each index in it.

Example 1:
Input: nums = [1], k = 0
Output: 0

Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.

*/

// Solution

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumScore(vector<int> &nums, int k)
{
    int n = nums.size();

    // Sort the array in ascending order
    sort(nums.begin(), nums.end());

    // Initialize the minimum and maximum elements
    int minNum = nums[0];
    int maxNum = nums[n - 1];

    // Update the minimum and maximum elements based on the operation
    for (int i = 1; i < n - 1; i++)
    {
        int lowerBound = max(minNum + k, nums[i] - k);
        int upperBound = min(maxNum - k, nums[i] + k);

        if (lowerBound <= upperBound)
        {
            minNum = min(minNum, lowerBound);
            maxNum = max(maxNum, upperBound);
        }
    }

    // Calculate and return the minimum score
    return maxNum - minNum;
}

int main()
{
    vector<int> nums = {1};
    int k = 0;

    int minScore = minimumScore(nums, k);
    cout << "Minimum score: " << minScore << endl;

    return 0;
}
