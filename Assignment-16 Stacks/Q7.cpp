#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int remainingWordsAfterDestruction(const vector<string> &words)
{
    stack<string> st;

    for (const string &word : words)
    {
        if (!st.empty() && st.top() == word)
        {
            st.pop();
        }
        else
        {
            st.push(word);
        }
    }

    return st.size();
}

int main()
{
    vector<string> words = {"ab", "aa", "aa", "bcd", "ab"};
    int remaining = remainingWordsAfterDestruction(words);

    cout << "Output: " << remaining << endl;

    return 0;
}
