#include <iostream>
using namespace std;

string reverseStr(string s, int k)
{
    int n = s.length();
    for (int i = 0; i < n; i += 2 * k)
    {
        int left = i;
        int right = min(i + k - 1, n - 1);
        while (left < right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    return s;
}

int main()
{
    string s;
    int k;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Enter value of k: ";
    cin >> k;

    string reversed = reverseStr(s, k);

    cout << "Reversed string: " << reversed << endl;

    return 0;
}