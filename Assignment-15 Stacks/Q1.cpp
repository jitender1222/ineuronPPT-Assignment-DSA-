#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[i] > nums[st.top()])
        {
            result[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }

    return result;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> result = nextGreaterElement(nums);

    cout << "Next Greater Elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
