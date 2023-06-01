/*

Question 6
Given a non-empty array of integers nums, every element appears twice except
for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only
constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1

*/

// Solution

#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int> &nums)
{
    int single = 0;

    for (int num : nums)
    {
        single ^= num;
    }

    return single;
}

int main()
{
    vector<int> nums = {2, 2, 1};
    int single = singleNumber(nums);
    cout << "Single number: " << single << endl;
    return 0;
}
