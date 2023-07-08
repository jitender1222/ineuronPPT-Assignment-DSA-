#include <iostream>
#include <stack>
using namespace std;

bool backspaceCompare(string s, string t)
{
    stack<char> stackS, stackT;

    for (char c : s)
    {
        if (c == '#')
        {
            if (!stackS.empty())
                stackS.pop();
        }
        else
        {
            stackS.push(c);
        }
    }

    for (char c : t)
    {
        if (c == '#')
        {
            if (!stackT.empty())
                stackT.pop();
        }
        else
        {
            stackT.push(c);
        }
    }

    return stackS == stackT;
}

int main()
{
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;

    bool areEqual = backspaceCompare(s, t);

    cout << (areEqual ? "true" : "false") << endl;

    return 0;
}
