/*

<aside>
💡 **Q6.** Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

**Example 1:**
Input: nums = [1,2,3,1]

Output: true

</aside>

*/

// Solution

#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int> &nums)
{
    std::unordered_set<int> uniqueElements;

    for (int num : nums)
    {
        if (uniqueElements.find(num) != uniqueElements.end())
        {
            return true;
        }
        uniqueElements.insert(num);
    }

    return false;
}

int main()
{
    std::vector<int> nums = {1, 2, 3, 1};

    if (containsDuplicate(nums))
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }

    return 0;
}
