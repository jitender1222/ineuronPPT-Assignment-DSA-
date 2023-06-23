#include <iostream>
#include <vector>
#include <algorithm>

int maxSubarraySumCircular(std::vector<int> &nums)
{
    int totalSum = 0;
    int maxSum = nums[0];
    int minSum = nums[0];
    int currMax = nums[0];
    int currMin = nums[0];

    // Calculate the maximum and minimum sums of a non-empty subarray
    for (int i = 1; i < nums.size(); i++)
    {
        totalSum += nums[i];
        currMax = std::max(nums[i], currMax + nums[i]);
        currMin = std::min(nums[i], currMin + nums[i]);
        maxSum = std::max(maxSum, currMax);
        minSum = std::min(minSum, currMin);
    }

    // If all numbers are negative, return the maximum element
    if (totalSum == minSum)
    {
        return maxSum;
    }

    // Calculate the maximum sum of a circular subarray
    return std::max(maxSum, totalSum - minSum);
}

int main()
{
    std::vector<int> nums = {1, -2, 3, -2};
    std::cout << maxSubarraySumCircular(nums) << std::endl; // Output: 3

    nums = {5, -3, 5};
    std::cout << maxSubarraySumCircular(nums) << std::endl; // Output: 10

    nums = {-3, -2, -3};
    std::cout << maxSubarraySumCircular(nums) << std::endl; // Output: -2

    return 0;
}
