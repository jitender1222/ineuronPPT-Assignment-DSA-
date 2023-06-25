#include <iostream>

using namespace std;

bool isBadVersion(int version)
{
    // API function to check if a version is bad
    // Implementation not provided
}

int firstBadVersion(int n)
{
    int left = 1;
    int right = n;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}

int main()
{
    int n = 5;
    int bad = 4;
    int firstBad = firstBadVersion(n);

    cout << "First Bad Version: " << firstBad << endl;

    return 0;
}
