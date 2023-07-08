#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

string reverseWords(string s)
{
    istringstream iss(s);
    string word;
    string reversedString = "";

    while (iss >> word)
    {
        reverse(word.begin(), word.end());
        reversedString += word + " ";
    }

    reversedString.pop_back(); // Remove extra space at the end
    return reversedString;
}

int main()
{
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    string reversed = reverseWords(s);

    cout << "Reversed string: " << reversed << endl;

    return 0;
}
