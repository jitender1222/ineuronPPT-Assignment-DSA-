#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {}

    void push(int val)
    {
        st.push(val);

        if (minSt.empty() || val <= minSt.top())
        {
            minSt.push(val);
        }
    }

    void pop()
    {
        if (st.empty())
            return;

        int val = st.top();
        st.pop();

        if (val == minSt.top())
        {
            minSt.pop();
        }
    }

    int top()
    {
        if (st.empty())
            return -1;

        return st.top();
    }

    int getMin()
    {
        if (minSt.empty())
            return -1;

        return minSt.top();
    }
};

int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "Minimum element: " << minStack.getMin() << endl;
    minStack.pop();
    cout << "Top element: " << minStack.top() << endl;
    cout << "Minimum element: " << minStack.getMin() << endl;

    return 0;
}
