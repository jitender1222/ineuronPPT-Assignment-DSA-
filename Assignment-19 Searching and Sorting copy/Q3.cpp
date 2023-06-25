#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &nums, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArray(n1);
    vector<int> rightArray(n2);

    for (int i = 0; i < n1; i++)
        leftArray[i] = nums[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = nums[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
            nums[k++] = leftArray[i++];
        else
            nums[k++] = rightArray[j++];
    }

    while (i < n1)
        nums[k++] = leftArray[i++];

    while (j < n2)
        nums[k++] = rightArray[j++];
}

void mergeSort(vector<int> &nums, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        merge(nums, left, mid, right);
    }
}

vector<int> sortArray(vector<int> &nums)
{
    int n = nums.size();
    mergeSort(nums, 0, n - 1);
    return nums;
}

int main()
{
    // Create the input array
    vector<int> nums;
    // Add code to populate the array...

    // Sort the array
    vector<int> sortedArray = sortArray(nums);

    // Print the sorted array
    for (int num : sortedArray)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
