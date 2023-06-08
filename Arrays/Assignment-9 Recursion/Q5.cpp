#include <iostream>
using namespace std;

int findMax(int arr[], int size)
{
    if (size == 1)
        return arr[0];
    return max(arr[size - 1], findMax(arr, size - 1));
}

int main()
{
    int arr[] = {1, 4, 3, -5, -4, 8, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int maxElement = findMax(arr, size);
    cout << maxElement << endl;
    return 0;
}
