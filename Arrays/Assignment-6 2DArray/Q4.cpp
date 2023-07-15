#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findMaxLength(vector<int> &nums)
{
    int maxLength = 0;
    int count = 0;
    unordered_map<int, int> map;
    map[0] = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            count--;
        }
        else
        {
            count++;
        }

        if (map.find(count) != map.end())
        {
            maxLength = max(maxLength, i - map[count]);
        }
        else
        {
            map[count] = i;
        }
    }

    return maxLength;
}

int main()
{
    vector<int> nums = {0, 1, 0, 0, 1, 1};

    int result = findMaxLength(nums);

    cout << result << endl;

    return 0;
}
