#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minProductSum(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.rbegin(), nums2.rend());

    int productSum = 0;

    for (int i = 0; i < nums1.size(); i++)
    {
        productSum += nums1[i] * nums2[i];
    }

    return productSum;
}

int main()
{
    vector<int> nums1 = {5, 3, 4, 2};
    vector<int> nums2 = {4, 2, 2, 5};

    int result = minProductSum(nums1, nums2);

    cout << result << endl;

    return 0;
}
