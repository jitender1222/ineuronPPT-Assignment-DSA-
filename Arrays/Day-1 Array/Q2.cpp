/*
💡 **Q2.** Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

- Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
- Return k.

**Example :**
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_*,_*]

**Explanation:** Your function should return k = 2, with the first two elements of nums being 2. It does not matter what you leave beyond the returned k (hence they are underscores)

*/

// Solution

#include <iostream>

using namespace std;

int remove_all_occurrences(int nums[], int val, int n)
{
    int i, j, count = 0;

    for (i = 0; i < n; i++)
    {
        if (nums[i] != val)
        {
            nums[count++] = nums[i];
        }
    }

    return count;
}

int main()
{
    int nums[] = {3, 2, 2, 3};
    int val = 3;
    int n = sizeof(nums) / sizeof(nums[0]);

    int new_length = remove_all_occurrences(nums, val, n);

    for (int i = 0; i < new_length; i++)
    {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}
