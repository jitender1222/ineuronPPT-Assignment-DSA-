#include <iostream>
#include <stack>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void printRootToLeafPaths(Node *root)
{
    if (root == nullptr)
        return;

    std::stack<std::pair<Node *, std::string>> stack;
    stack.push(std::make_pair(root, std::to_string(root->data)));

    while (!stack.empty())
    {
        Node *currNode = stack.top().first;
        std::string currPath = stack.top().second;
        stack.pop();

        if (currNode->left == nullptr && currNode->right == nullptr)
        {
            std::cout << currPath << std::endl;
        }

        if (currNode->left)
        {
            stack.push(std::make_pair(currNode->left, currPath + "->" + std::to_string(currNode->left->data)));
        }

        if (currNode->right)
        {
            stack.push(std::make_pair(currNode->right, currPath + "->" + std::to_string(currNode->right->data)));
        }
    }
}

int main()
{
    Node *root = newNode(6);
    root->left = newNode(3);
    root->right = newNode(5);
    root->left->left = newNode(2);
    root->left->right = newNode(5);
    root->right->right = newNode(4);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);

    std::cout << "Root-to-Leaf Paths:" << std::endl;
    printRootToLeafPaths(root);

    return 0;
}
