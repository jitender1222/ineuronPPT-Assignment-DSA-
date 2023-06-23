#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> maxAbsoluteDifference(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> result(n, -1);

    stack<int> st;

    // Find nearest smaller element on the left
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            result[i] = arr[st.top()];
        }

        st.push(i);
    }

    while (!st.empty())
    {
        st.pop();
    }

    // Find nearest smaller element on the right
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        if (!st.empty() && (result[i] == -1 || arr[st.top()] - arr[i] > arr[i] - result[i]))
        {
            result[i] = arr[st.top()];
        }

        st.push(i);
    }

    return result;
}

int main()
{
    vector<int> arr = {1, 1, 2, 3, 4, 2, 1};
    vector<int> result = maxAbsoluteDifference(arr);

    cout << "Output: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}