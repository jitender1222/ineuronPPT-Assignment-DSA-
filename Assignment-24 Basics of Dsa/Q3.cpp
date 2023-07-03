#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> count;
    int n = nums.size();

    for (int num : nums)
    {
        count[num]++;
        if (count[num] > n / 2)
            return num;
    }

    return -1; // Majority element not found
}

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int majority = majorityElement(nums);
    cout << majority << endl;
    return 0;
}
