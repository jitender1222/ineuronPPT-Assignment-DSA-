#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int nonZeroIndex = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
            nums[nonZeroIndex++] = nums[i];
    }

    for (int i = nonZeroIndex; i < n; i++)
        nums[i] = 0;
}

int main()
{
    // Create the input array
    vector<int> nums;
    // Add code to populate the array...

    // Move zeroes to the end
    moveZeroes(nums);

    // Print the modified array
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
