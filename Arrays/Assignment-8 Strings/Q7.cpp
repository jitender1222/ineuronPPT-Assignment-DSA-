#include <iostream>
#include <stack>
#include <string>

using namespace std;

string decodeString(string s)
{
    stack<int> countStack;
    stack<string> stringStack;
    string currString = "";
    int currCount = 0;

    for (char c : s)
    {
        if (isdigit(c))
        {
            currCount = currCount * 10 + (c - '0');
        }
        else if (c == '[')
        {
            countStack.push(currCount);
            stringStack.push(currString);
            currCount = 0;
            currString = "";
        }
        else if (c == ']')
        {
            int count = countStack.top();
            countStack.pop();
            string decodedString = "";

            for (int i = 0; i < count; i++)
                decodedString += currString;

            currString = stringStack.top() + decodedString;
            stringStack.pop();
        }
        else
        {
            currString += c;
        }
    }

    return currString;
}

int main()
{
    string s = "3[a]2[bc]";
    string result = decodeString(s);
    cout << "Decoded String: " << result << endl;

    return 0;
}
