#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void convertToDoublyLinkedList(TreeNode *root, TreeNode *&prev, TreeNode *&head)
{
    if (root == nullptr)
        return;

    convertToDoublyLinkedList(root->left, prev, head);

    if (prev == nullptr)
        head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }

    prev = root;

    convertToDoublyLinkedList(root->right, prev, head);
}

void printDoublyLinkedList(TreeNode *head)
{
    while (head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->right;
    }
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(30);
    root->right->right = new TreeNode(35);

    TreeNode *prev = nullptr;
    TreeNode *head = nullptr;

    convertToDoublyLinkedList(root, prev, head);

    std::cout << "Doubly Linked List: ";
    printDoublyLinkedList(head);
    std::cout << std::endl;

    return 0;
}
