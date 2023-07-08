#include <iostream>
#include <stack>
using namespace std;

string reverseString(string s)
{
    stack<char> st;

    for (char c : s)
    {
        st.push(c);
    }

    string reversed = "";
    while (!st.empty())
    {
        reversed += st.top();
        st.pop();
    }

    return reversed;
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    string reversed = reverseString(s);

    cout << "Reversed string: " << reversed << endl;

    return 0;
}
