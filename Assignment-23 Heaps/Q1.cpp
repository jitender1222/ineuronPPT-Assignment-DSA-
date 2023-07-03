#include <iostream>
#include <string>
#include <algorithm>

int calculateDepth(const std::string &preorder)
{
    int depth = 0;
    int maxDepth = 0;

    for (char c : preorder)
    {
        if (c == 'n')
        {
            depth++;
            maxDepth = std::max(maxDepth, depth);
        }
        else if (c == 'l')
        {
            depth--;
        }
    }

    return maxDepth;
}

int main()
{
    std::string preorder1 = "nlnll";
    std::cout << "Depth: " << calculateDepth(preorder1) << std::endl;

    std::string preorder2 = "nlnnlll";
    std::cout << "Depth: " << calculateDepth(preorder2) << std::endl;

    return 0;
}
