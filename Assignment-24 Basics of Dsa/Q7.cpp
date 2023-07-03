#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> result;
    deque<int> window;

    for (int i = 0; i < n; i++)
    {
        while (!window.empty() && nums[i] >= nums[window.back()])
            window.pop_back();

        window.push_back(i);

        if (i >= k - 1)
        {
            result.push_back(nums[window.front()]);

            if (i - window.front() + 1 > k)
                window.pop_front();
        }
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = maxSlidingWindow(nums, k);

    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
