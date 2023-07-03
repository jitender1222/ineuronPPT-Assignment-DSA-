#include <iostream>
#include <vector>
#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorderTraversal(TreeNode *root, std::vector<int> &values)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left, values);
    values.push_back(root->val);
    inorderTraversal(root->right, values);
}

void convertToBST(TreeNode *root, std::vector<int> &values, int &index)
{
    if (root == nullptr)
        return;

    convertToBST(root->left, values, index);
    root->val = values[index++];
    convertToBST(root->right, values, index);
}

void binaryTreeToBST(TreeNode *root)
{
    std::vector<int> values;
    int index = 0;

    inorderTraversal(root, values);
    std::sort(values.begin(), values.end());

    convertToBST(root, values, index);
}

void inorderPrint(TreeNode *root)
{
    if (root == nullptr)
        return;

    inorderPrint(root->left);
    std::cout << root->val << " ";
    inorderPrint(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(4);

    std::cout << "Binary Tree before conversion: ";
    inorderPrint(root);
    std::cout << std::endl;

    binaryTreeToBST(root);

    std::cout << "Binary Tree after conversion: ";
    inorderPrint(root);
    std::cout << std::endl;

    return 0;
}
