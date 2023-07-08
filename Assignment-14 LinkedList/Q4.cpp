#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *random;
};

Node *copyRandomList(Node *head)
{
    if (head == nullptr)
        return nullptr;

    unordered_map<Node *, Node *> nodeMap;

    Node *curr = head;
    while (curr != nullptr)
    {
        Node *newNode = new Node();
        newNode->data = curr->data;
        newNode->next = nullptr;
        newNode->random = nullptr;
        nodeMap[curr] = newNode;
        curr = curr->next;
    }

    curr = head;
    while (curr != nullptr)
    {
        nodeMap[curr]->next = nodeMap[curr->next];
        nodeMap[curr]->random = nodeMap[curr->random];
        curr = curr->next;
    }

    return nodeMap[head];
}

int main()
{
    // Create a linked list with random pointers

    Node *head = new Node();
    head->data = 1;

    Node *node2 = new Node();
    node2->data = 2;
    head->next = node2;

    Node *node3 = new Node();
    node3->data = 3;
    node2->next = node3;

    Node *node4 = new Node();
    node4->data = 4;
    node3->next = node4;

    head->random = node3;
    node2->random = node4;
    node4->random = head;

    // Copy the linked list with random pointers
    Node *copiedList = copyRandomList(head);

    // Print the copied list
    Node *temp = copiedList;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
