#include <iostream>
#include <cctype>
using namespace std;

bool isConsonant(char c)
{
    c = tolower(c);
    return (c >= 'b' && c <= 'z' && c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u');
}

int countConsonants(string str)
{
    int count = 0;
    for (char c : str)
    {
        if (isConsonant(c))
            count++;
    }
    return count;
}

int main()
{
    string str = "Hello World";
    int count = countConsonants(str);
    cout << count << endl;
    return 0;
}
