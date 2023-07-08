#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *removeLoop(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (slow != fast)
        return head;

    slow = head;

    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = nullptr;

    return head;
}

int main()
{
    // Create a linked list with a loop

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

    Node *node5 = new Node();
    node5->data = 5;
    node4->next = node5;

    // Creating a loop
    node5->next = node2;

    // Removing the loop
    head = removeLoop(head);

    // Print the linked list after removing the loop
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
