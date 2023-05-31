/*

<aside>
💡 **Q8.** You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

**Example 1:**
Input: nums = [1,2,2,4]
Output: [2,3]

</aside>

*/

// Solution

#include <iostream>
#include <vector>

using namespace std;

vector<int> findDuplicateAndMissingNumber(vector<int> nums)
{
    int n = nums.size();

    vector<bool> present(n + 1, false);

    for (int i = 0; i < n; i++)
    {
        present[nums[i]] = true;
    }

    int missingNumber = 1;
    while (present[missingNumber])
    {
        missingNumber++;
    }

    int duplicateNumber = -1;
    for (int i = 0; i < n; i++)
    {
        if (present[nums[i]] == true && nums[i] != missingNumber)
        {
            duplicateNumber = nums[i];
            break;
        }
    }

    return {duplicateNumber, missingNumber};
}

int main()
{
    vector<int> nums = {1, 2, 2, 4};

    vector<int> result = findDuplicateAndMissingNumber(nums);

    cout << "The duplicate number is " << result[0] << endl;
    cout << "The missing number is " << result[1] << endl;

    return 0;
}
