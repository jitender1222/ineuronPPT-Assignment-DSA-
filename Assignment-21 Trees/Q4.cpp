#include <iostream>
#include <queue>

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *nextRight;

    Node(int x) : data(x), left(nullptr), right(nullptr), nextRight(nullptr) {}
};

void connectNodesAtSameLevel(Node *root)
{
    if (root == nullptr)
        return;

    std::queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        Node *prev = nullptr;

        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (prev != nullptr)
                prev->nextRight = curr;

            prev = curr;

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }
    }
}

void printLevelOrderTraversal(Node *root)
{
    while (root != nullptr)
    {
        Node *temp = root;
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->nextRight;
        }
        std::cout << std::endl;
        root = root->left;
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    connectNodesAtSameLevel(root);

    std::cout << "Nodes connected at the same level: " << std::endl;
    printLevelOrderTraversal(root);

    return 0;
}
