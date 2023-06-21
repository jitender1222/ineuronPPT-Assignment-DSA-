#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool canArrangeInIncreasingOrder(queue<int> &q)
{
    stack<int> st;
    queue<int> secondQueue;

    int expectedElement = 1;

    while (!q.empty())
    {
        if (q.front() == expectedElement)
        {
            q.pop();
            expectedElement++;
        }
        else if (!st.empty() && st.top() == expectedElement)
        {
            st.pop();
            expectedElement++;
        }
        else
        {
            while (!q.empty() && q.front() != expectedElement)
            {
                st.push(q.front());
                q.pop();
            }
            if (!q.empty() && q.front() == expectedElement)
            {
                q.pop();
                expectedElement++;
            }
        }
    }

    while (!st.empty() && st.top() == expectedElement)
    {
        st.pop();
        expectedElement++;
    }

    return (q.empty() && st.empty());
}

int main()
{
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    if (canArrangeInIncreasingOrder(q))
    {
        cout << "Output: Yes" << endl;
    }
    else
    {
        cout << "Output: No" << endl;
    }

    return 0;
}
