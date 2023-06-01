/*

Question 7
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is
monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.

Example 1:
Input: nums = [1,2,2,3]
Output: true


*/

// Solution

#include <iostream>
#include <vector>

using namespace std;

bool isMonotonic(vector<int> &nums)
{
    int n = nums.size();

    // Check if the array is monotone increasing
    bool increasing = true;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] < nums[i - 1])
        {
            increasing = false;
            break;
        }
    }

    // Check if the array is monotone decreasing
    bool decreasing = true;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > nums[i - 1])
        {
            decreasing = false;
            break;
        }
    }

    // Return true if either increasing or decreasing is true
    return increasing || decreasing;
}

int main()
{
    vector<int> nums = {1, 2, 2, 3};

    bool isMonotone = isMonotonic(nums);
    cout << "The given array is" << (isMonotone ? "true" : "false") << endl;

    return 0;
}
