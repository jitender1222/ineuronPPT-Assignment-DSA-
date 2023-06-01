/*

Question 6
Given an array of integers nums which is sorted in ascending order, and an integer target,
write a function to search target in nums. If target exists, then return its index. Otherwise,
return -1.

You must write an algorithm with O(log n) runtime complexity.

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4

*/

// Solution

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            return mid; // Target found at index mid
        }
        else if (nums[mid] < target)
        {
            left = mid + 1; // Target is in the right half of the array
        }
        else
        {
            right = mid - 1; // Target is in the left half of the array
        }
    }

    return -1; // Target not found
}

int main()
{
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    int index = search(nums, target);
    cout << "Target index: " << index << endl;

    return 0;
}
