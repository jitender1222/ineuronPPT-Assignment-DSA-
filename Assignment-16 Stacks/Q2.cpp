#include <iostream>
#include <stack>

using namespace std;

void sortStack(stack<int> &s)
{
    stack<int> tmpStack;

    while (!s.empty())
    {
        int tmp = s.top();
        s.pop();

        while (!tmpStack.empty() && tmpStack.top() > tmp)
        {
            s.push(tmpStack.top());
            tmpStack.pop();
        }

        tmpStack.push(tmp);
    }

    // Copy the elements back to the original stack
    while (!tmpStack.empty())
    {
        s.push(tmpStack.top());
        tmpStack.pop();
    }
}

int main()
{
    stack<int> s;
    s.push(34);
    s.push(3);
    s.push(31);
    s.push(98);
    s.push(92);
    s.push(23);

    sortStack(s);

    cout << "Output: ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
