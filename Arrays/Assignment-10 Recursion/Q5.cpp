#include <iostream>
using namespace std;

int countSubstringsWithSameStartAndEnd(string str)
{
    int count = 0;
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        count++;
        char currentChar = str[i];
        for (int j = i + 1; j < n; j++)
        {
            if (str[j] == currentChar)
                count++;
        }
    }
    return count;
}

int main()
{
    string str = "abcab";
    int count = countSubstringsWithSameStartAndEnd(str);
    cout << count << endl;
    return 0;
}
