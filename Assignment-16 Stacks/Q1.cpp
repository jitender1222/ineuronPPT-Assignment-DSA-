#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> findNearestGreaterFrequency(const vector<int> &arr)
{
    vector<int> result(arr.size(), -1);
    stack<int> st;
    vector<int> frequency(10001, 0); // Assuming the elements in the array are in the range [1, 10000]

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        frequency[arr[i]]++;
        while (!st.empty() && frequency[arr[i]] >= frequency[arr[st.top()]])
        {
            st.pop();
        }
        if (!st.empty())
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
    vector<int> result = findNearestGreaterFrequency(arr);

    cout << "Output: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
