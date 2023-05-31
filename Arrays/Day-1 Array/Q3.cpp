/*

💡 **Q3.** Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

**Example 1:**
Input: nums = [1,3,5,6], target = 5

Output: 2


*/

// Solution

#include <iostream>

using namespace std;

int find_index(int nums[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low;
}

int main()
{
    int nums[] = {1, 3, 5, 6};
    int target = 5;
    int n = sizeof(nums) / sizeof(nums[0]);

    int index = find_index(nums, n, target);

    if (index != -1)
    {
        cout << "The index of the target value is " << index << endl;
    }
    else
    {
        cout << "The target value is not found in the array" << endl;
    }

    return 0;
}
