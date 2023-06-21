#include <iostream>
#include <stack>

using namespace std;

int reverseNumber(int num)
{
    stack<int> st;
    while (num > 0)
    {
        st.push(num % 10);
        num /= 10;
    }

    int reversedNum = 0;
    int multiplier = 1;

    while (!st.empty())
    {
        reversedNum += st.top() * multiplier;
        st.pop();
        multiplier *= 10;
    }

    return reversedNum;
}

int main()
{
    int num = 365;
    int reversedNum = reverseNumber(num);
    cout << "Output: " << reversedNum << endl;

    return 0;
}
