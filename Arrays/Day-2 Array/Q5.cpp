/*

Question 5
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

Example 1:
Input: nums = [1,2,3]
Output: 6

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumProduct(vector<int> &nums)
{
    int n = nums.size();

    // Sort the array in ascending order
    sort(nums.begin(), nums.end());

    // Maximum product can be either the product of the three largest elements or the product of the two smallest elements and the largest element
    return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
}

int main()
{
    vector<int> nums = {1, 2, 3};

    int maxProduct = maximumProduct(nums);
    cout << "Maximum product: " << maxProduct << endl;

    return 0;
}
