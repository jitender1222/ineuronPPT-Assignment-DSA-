#include <iostream>
#include <vector>

int countStudents(std::vector<int> &students, std::vector<int> &sandwiches)
{
    int n = students.size();
    int m = sandwiches.size();
    int i = 0;
    int j = 0;

    while (i < n && j < m)
    {
        if (students[i] == sandwiches[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }

    return n - j;
}

int main()
{
    std::vector<int> students = {1, 1, 0, 0};
    std::vector<int> sandwiches = {0, 1, 0, 1};
    std::cout << countStudents(students, sandwiches) << std::endl; // Output: 0

    students = {1, 1, 1, 0, 0, 1};
    sandwiches = {1, 0, 0, 0, 1, 1};
    std::cout << countStudents(students, sandwiches) << std::endl; // Output: 3

    return 0;
}
