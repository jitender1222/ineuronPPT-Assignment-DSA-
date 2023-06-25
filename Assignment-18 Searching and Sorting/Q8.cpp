#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool find132pattern(vector<int> &nums)
{
    int n = nums.size();
    stack<int> stk;
    int s3 = -9999;

    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] < s3)
        {
            return true;
        }

        while (!stk.empty() && nums[i] > stk.top())
        {
            s3 = stk.top();
            stk.pop();
        }

        stk.push(nums[i]);
    }

    return false;
}

int main()
{
    vector<int> nums = {3, 1, 4, 2};
    bool has132Pattern = find132pattern(nums);

    cout << "Contains 132 Pattern: " << boolalpha << has132Pattern << endl;

    return 0;
}
