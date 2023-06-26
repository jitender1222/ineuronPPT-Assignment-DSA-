#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    Node *newNode = new Node();
    if (!newNode)
    {
        cout << "Memory error!\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *constructBST(int arr[], int size)
{
    if (size == 0)
        return NULL;

    Node *root = createNode(arr[0]);
    queue<Node *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < size)
    {
        Node *temp = q.front();
        q.pop();

        if (i < size && arr[i] < temp->data)
        {
            temp->left = createNode(arr[i]);
            q.push(temp->left);
            i++;
        }

        if (i < size && arr[i] > temp->data)
        {
            temp->right = createNode(arr[i]);
            q.push(temp->right);
            i++;
        }
    }

    return root;
}

void inOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main()
{
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node *root = constructBST(arr, size);

    cout << "In-order traversal of the constructed BST:\n";
    inOrderTraversal(root);

    return 0;
}
