#include <iostream>
#include <vector>

using namespace std;

bool validMountainArray(vector<int> &arr)
{
    int n = arr.size();
    int i = 0;

    // Check if the array is valid based on the given conditions
    while (i < n - 1 && arr[i] < arr[i + 1])
    {
        i++;
    }

    // Check if the peak is not at the beginning or end of the array
    if (i == 0 || i == n - 1)
    {
        return false;
    }

    // Check if the descending part of the array is valid
    while (i < n - 1 && arr[i] > arr[i + 1])
    {
        i++;
    }

    return i == n - 1;
}

int main()
{
    vector<int> arr = {0, 3, 2, 1};

    bool result = validMountainArray(arr);

    cout << boolalpha << result << endl;

    return 0;
}
