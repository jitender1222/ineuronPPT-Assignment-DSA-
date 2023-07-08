#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int trapRainWater(vector<int> &height)
{
    int n = height.size();
    int water = 0;
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && height[i] > height[st.top()])
        {
            int top = st.top();
            st.pop();

            if (st.empty())
                break;

            int distance = i - st.top() - 1;
            int boundedHeight = min(height[i], height[st.top()]) - height[top];
            water += distance * boundedHeight;
        }

        st.push(i);
    }

    return water;
}

int main()
{
    int n;
    cout << "Enter the number of bars: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter the heights of the bars: ";
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }

    int trappedWater = trapRainWater(height);

    cout << "Trapped Water: " << trappedWater << endl;

    return 0;
}
