#include <iostream>
#include <stack>

using namespace std;

void deleteMiddleElement(stack<int> &st, int current = 0)
{
    if (st.empty())
    {
        return;
    }

    int middle = st.size() / 2 + 1;
    int top = st.top();
    st.pop();

    if (current != middle)
    {
        deleteMiddleElement(st, current + 1);
    }

    if (current != middle)
    {
        st.push(top);
    }
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    deleteMiddleElement(st);

    cout << "Output: ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
