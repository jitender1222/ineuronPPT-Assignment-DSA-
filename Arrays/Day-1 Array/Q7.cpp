/*

<aside>
💡 **Q7.** Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the nonzero elements.

Note that you must do this in-place without making a copy of the array.

**Example 1:**
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

</aside>

*/

// Solution

#include <iostream>

using namespace std;

void moveZeroes(int *nums, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            nums[count++] = nums[i];
        }
    }

    for (int i = count; i < n; i++)
    {
        nums[i] = 0;
    }
}

int main()
{
    int nums[] = {0, 1, 0, 3, 12};
    int n = sizeof(nums) / sizeof(nums[0]);

    moveZeroes(nums, n);

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}
