#include <iostream>
using namespace std;

bool rotateString(string s, string goal)
{
    if (s.length() != goal.length())
        return false;

    string temp = s + s;

    if (temp.find(goal) != string::npos)
        return true;
    else
        return false;
}

int main()
{
    string s, goal;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string goal: ";
    cin >> goal;

    bool canRotate = rotateString(s, goal);

    cout << (canRotate ? "true" : "false") << endl;

    return 0;
}
