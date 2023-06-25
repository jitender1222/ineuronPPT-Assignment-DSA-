#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    cout << "Before Sorting: ";
    for (const auto &num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    sortColors(nums);

    cout << "After Sorting: ";
    for (const auto &num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
