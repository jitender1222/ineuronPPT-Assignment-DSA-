#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> set1(nums1.begin(), nums1.end());
    vector<int> result;

    for (int num : nums2)
    {
        if (set1.count(num))
        {
            result.push_back(num);
            set1.erase(num);
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
    vector<int> intersectionArray = intersection(nums1, nums2);

    // Print the intersection array
    for (int num : intersectionArray)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
