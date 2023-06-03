

// Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<vector<int>> findDistinctElements(vector<int> &nums1, vector<int> &nums2)
{
    vector<vector<int>> result(2, vector<int>());
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());

    for (int num : nums1)
    {
        if (set2.find(num) == set2.end())
        {
            result[0].push_back(num);
        }
    }

    for (int num : nums2)
    {
        if (set1.find(num) == set1.end())
        {
            result[1].push_back(num);
        }
    }

    return result;
}

int main()
{
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};

    vector<vector<int>> distinctElements = findDistinctElements(nums1, nums2);

    cout << "Distinct elements in nums1: ";
    for (int num : distinctElements[0])
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Distinct elements in nums2: ";
    for (int num : distinctElements[1])
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
