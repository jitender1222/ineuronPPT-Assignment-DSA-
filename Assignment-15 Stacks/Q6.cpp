#include <iostream>
#include <stack>
using namespace std;

int evaluatePostfixExpression(string postfix)
{
    stack<int> st;

    for (char c : postfix)
    {
        if (isdigit(c))
        {
            st.push(c - '0');
        }
        else
        {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();

            switch (c)
            {
            case '+':
                st.push(operand1 + operand2);
                break;
            case '-':
                st.push(operand1 - operand2);
                break;
            case '*':
                st.push(operand1 * operand2);
                break;
            case '/':
                st.push(operand1 / operand2);
                break;
            }
        }
    }

    return st.top();
}

int main()
{
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfixExpression(postfix);

    cout << "Result: " << result << endl;

    return 0;
}
