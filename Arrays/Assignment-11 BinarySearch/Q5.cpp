#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> intersect;
    for (int num : nums2)
    {
        if (set1.count(num))
        {
            intersect.insert(num);
        }
    }
    vector<int> result(intersect.begin(), intersect.end());
    return result;
}

int main()
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> intersectionResult = intersection(nums1, nums2);
    for (int num : intersectionResult)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
