/*

Question 2
Given an array nums of n integers, return an array of all the unique quadruplets
[nums[a], nums[b], nums[c], nums[d]] such that:
           ● 0 <= a, b, c, d < n
           ● a, b, c, and d are distinct.
           ● nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

*/

// Solution

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> result;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        for (int j = i + 1; j < n - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }

            int left = j + 1;
            int right = n - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target)
                {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    left++;
                    right--;
                }
                else if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = fourSum(nums, target);
    cout << "Unique quadruplets:" << endl;
    for (const auto &quad : result)
    {
        for (int num : quad)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
