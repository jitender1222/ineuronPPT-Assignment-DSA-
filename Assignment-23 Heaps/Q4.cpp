#include <iostream>
#include <map>
#include <queue>

struct Node
{
    int data;
    int hd; // horizontal distance
    Node *left;
    Node *right;
};

Node *newNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->hd = 0;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void printBottomView(Node *root)
{
    if (root == nullptr)
        return;

    std::map<int, int> bottomViewMap;
    std::queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        int hd = temp->hd;

        bottomViewMap[hd] = temp->data;

        if (temp->left)
        {
            temp->left->hd = hd - 1;
            q.push(temp->left);
        }

        if (temp->right)
        {
            temp->right->hd = hd + 1;
            q.push(temp->right);
        }
    }

    for (auto it = bottomViewMap.begin(); it != bottomViewMap.end(); ++it)
    {
        std::cout << it->second << " ";
    }
}

int main()
{
    Node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(25);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    std::cout << "Bottom View: ";
    printBottomView(root);
    std::cout << std::endl;

    return 0;
}
