#include <iostream>
#include <vector>

using namespace std;

vector<int> countSmaller(vector<int> &nums)
{
    int n = nums.size();
    vector<int> counts(n, 0);
    vector<int> sortedNums;

    for (int i = n - 1; i >= 0; i--)
    {
        auto it = lower_bound(sortedNums.begin(), sortedNums.end(), nums[i]);
        counts[i] = it - sortedNums.begin();
        sortedNums.insert(it, nums[i]);
    }

    return counts;
}

int main()
{
    // Create the input array
    vector<int> nums;
    // Add code to populate the array...

    // Get the counts of smaller numbers
    vector<int> counts = countSmaller(nums);

    // Print the counts
    for (int count : counts)
    {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
