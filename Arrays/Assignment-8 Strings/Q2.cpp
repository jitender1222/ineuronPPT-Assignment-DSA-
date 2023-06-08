#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s)
{
    stack<char> stk;

    for (char c : s)
    {
        if (c == '(' || c == '*')
            stk.push(c);
        else if (!stk.empty() && (c == ')' || c == '*'))
            stk.pop();
        else
            return false;
    }

    stack<char> tempStk;

    while (!stk.empty())
    {
        char c = stk.top();
        stk.pop();

        if (c == '(' && tempStk.empty())
            return false;

        if (c == '(')
            tempStk.pop();

        if (c == '*')
            tempStk.push(c);
    }

    return true;
}

int main()
{
    string s = "((*)";
    bool result = isValid(s);
    cout << "Is Valid: " << (result ? "true" : "false") << endl;

    return 0;
}
