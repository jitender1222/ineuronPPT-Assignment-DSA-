#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *reverseLinkedList(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;
    Node *next = nullptr;

    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node *addOne(Node *head)
{
    head = reverseLinkedList(head);

    Node *temp = head;
    Node *prev = nullptr;
    int carry = 1;

    while (temp != nullptr)
    {
        int sum = temp->data + carry;
        carry = sum / 10;
        temp->data = sum % 10;
        prev = temp;
        temp = temp->next;
    }

    if (carry > 0)
    {
        Node *newNode = new Node();
        newNode->data = carry;
        newNode->next = nullptr;
        prev->next = newNode;
    }

    head = reverseLinkedList(head);
    return head;
}

void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    // Create a linked list

    Node *head = new Node();
    head->data = 4;

    Node *node2 = new Node();
    node2->data = 5;
    head->next = node2;

    Node *node3 = new Node();
    node3->data = 6;
    node2->next = node3;

    // Add 1 to the linked list
    head = addOne(head);

    // Print the updated linked list
    printLinkedList(head);

    return 0;
}
