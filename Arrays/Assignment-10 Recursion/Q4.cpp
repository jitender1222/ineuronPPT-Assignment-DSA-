#include <iostream>
using namespace std;

int stringLength(string str)
{
    if (str == "")
        return 0;
    return 1 + stringLength(str.substr(1));
}

int main()
{
    string str = "abcd";
    int length = stringLength(str);
    cout << length << endl;
    return 0;
}
