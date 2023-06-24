#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> seen;

    for (const auto &num : nums)
    {
        if (seen.count(num) > 0)
        {
            return true;
        }
        seen.insert(num);
    }

    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    bool hasDuplicate = containsDuplicate(nums);

    cout << "Contains Duplicate: " << boolalpha << hasDuplicate << endl;

    return 0;
}
