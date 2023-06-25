#include <iostream>
#include <vector>

using namespace std;

void rearrange(vector<int> &nums)
{
    int n = nums.size();
    int i = -1, j = n;

    while (true)
    {
        // Find the first positive element from left
        do
        {
            i++;
        } while (i < n && nums[i] >= 0);

        // Find the first negative element from right
        do
        {
            j--;
        } while (j >= 0 && nums[j] < 0);

        if (i >= j)
            break;

        // Swap the positive and negative elements
        swap(nums[i], nums[j]);
    }

    // Rearrange positive and negative numbers alternatively
    if (i == 0 || i == n)
        return;

    int k = 0;

    while (k < n && i < n)
    {
        swap(nums[k], nums[i]);
        k += 2;
        i++;
    }
}

int main()
{
    // Create the input array
    vector<int> nums;
    // Add code to populate the array...

    // Rearrange the array
    rearrange(nums);

    // Print the rearranged array
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
