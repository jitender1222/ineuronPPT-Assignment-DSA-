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

// alternate solution

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> maxAbsoluteDifference(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> leftSmall(n, -1);
    vector<int> rightSmall(n, -1);
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
            leftSmall[i] = arr[st.top()];
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

        if (!st.empty())
        {
            rightSmall[i] = arr[st.top()];
        }

        st.push(i);
    }

    // Calculate the maximum absolute difference for each element
    vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        int leftDiff = leftSmall[i] == -1 ? -1 : abs(arr[i] - leftSmall[i]);
        int rightDiff = rightSmall[i] == -1 ? -1 : abs(arr[i] - rightSmall[i]);
        result[i] = max(leftDiff, rightDiff);
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
