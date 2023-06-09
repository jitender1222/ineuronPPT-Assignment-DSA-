#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    int leftIndex = findLeftIndex(nums, target);
    if (leftIndex == -1)
    {
        return {-1, -1};
    }
    int rightIndex = findRightIndex(nums, target);
    return {leftIndex, rightIndex};
}

int findLeftIndex(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    int index = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target)
        {
            right = mid - 1;
            if (nums[mid] == target)
            {
                index = mid;
            }
        }
        else
        {
            left = mid + 1;
        }
    }
    return index;
}

int findRightIndex(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    int index = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target)
        {
            left = mid + 1;
            if (nums[mid] == target)
            {
                index = mid;
            }
        }
        else
        {
            right = mid - 1;
        }
    }
    return index;
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> range = searchRange(nums, target);
    cout << range[0] << " " << range[1] << endl;
    return 0;
}
