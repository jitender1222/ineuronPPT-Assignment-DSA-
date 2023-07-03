#include <iostream>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    int left = 0, right = arr.size() - k;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (x - arr[mid] > arr[mid + k] - x)
            left = mid + 1;
        else
            right = mid;
    }

    return vector<int>(arr.begin() + left, arr.begin() + left + k);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4, x = 3;
    vector<int> result = findClosestElements(arr, k, x);

    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> groups;

    for (string s : strs)
    {
        string key = s;
        sort(key.begin(), key.end());
        groups[key].push_back(s);
    }

    vector<vector<string>> result;

    for (auto it = groups.begin(); it != groups.end(); it++)
    {
        result.push_back(it->second);
    }

    return result;
}

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> groups = groupAnagrams(strs);

    for (auto group : groups)
    {
        for (string s : group)
        {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}
