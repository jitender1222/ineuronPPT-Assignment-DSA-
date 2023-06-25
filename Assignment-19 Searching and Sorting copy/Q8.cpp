#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> countMap;
    vector<int> result;

    for (int num : nums1)
    {
        countMap[num]++;
    }

    for (int num : nums2)
    {
        if (countMap[num] > 0)
        {
            result.push_back(num);
            countMap[num]--;
        }
    }

    return result;
}

int main()
{
    // Create the input arrays
    vector<int> nums1;
    vector<int> nums2;
    // Add code to populate the arrays...

    // Find the intersection
    vector<int> intersectionArray = intersect(nums1, nums2);

    // Print the intersection array
    for (int num : intersectionArray)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
