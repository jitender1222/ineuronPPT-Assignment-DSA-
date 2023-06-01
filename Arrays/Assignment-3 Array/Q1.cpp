/*

Question 1
Given an integer array nums of length n and an integer target, find three integers
in nums such that the sum is closest to the target.
Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2

Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/

// Solution

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    int n = nums.size();
    int closestSum = 0;
    int minDiff = INT_MAX;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++)
    {
        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            int diff = abs(sum - target);

            if (diff == 0)
            {
                return sum;
            }

            if (diff < minDiff)
            {
                minDiff = diff;
                closestSum = sum;
            }

            if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return closestSum;
}

int main()
{
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int result = threeSumClosest(nums, target);
    cout << "Sum closest to target: " << result << endl;
    return 0;
}
