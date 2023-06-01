/*

Question 3
We define a harmonious array as an array where the difference between its maximum value
and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence
among all its possible subsequences.

A subsequence of an array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: nums = [1,3,2,2,5,2,3,7]
Output: 5

Explanation: The longest harmonious subsequence is [3,2,2,2,3].

*/

// Solution

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int findLHS(vector<int> &nums)
{
    unordered_map<int, int> freq;
    int maxLength = 0;

    for (int num : nums)
    {
        freq[num]++;
    }

    for (auto it = freq.begin(); it != freq.end(); ++it)
    {
        int currentNum = it->first;
        int currentFreq = it->second;

        if (freq.find(currentNum + 1) != freq.end())
        {
            int nextFreq = freq[currentNum + 1];
            maxLength = max(maxLength, currentFreq + nextFreq);
        }
    }

    return maxLength;
}

int main()
{
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    int longestSubsequenceLength = findLHS(nums);
    cout << "Length of the longest harmonious subsequence: " << longestSubsequenceLength << endl;
    return 0;
}
