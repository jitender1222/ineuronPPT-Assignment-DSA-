#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *bottom;
};

Node *mergeLists(Node *a, Node *b)
{
    if (a == nullptr)
        return b;
    if (b == nullptr)
        return a;

    Node *result = nullptr;

    if (a->data <= b->data)
    {
        result = a;
        result->bottom = mergeLists(a->bottom, b);
    }
    else
    {
        result = b;
        result->bottom = mergeLists(a, b->bottom);
    }

    result->next = nullptr;
    return result;
}

Node *flattenLinkedList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    head->next = flattenLinkedList(head->next);
    head = mergeLists(head, head->next);

    return head;
}

void printFlattenedLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->bottom;
    }
}

int main()
{
    // Create a linked list

    Node *head = new Node();
    head->data = 5;

    Node *node2 = new Node();
    node2->data = 10;
    head->next = node2;

    Node *node3 = new Node();
    node3->data = 19;
    node2->next = node3;

    Node *node4 = new Node();
    node4->data = 28;
    node3->next = node4;

    head->bottom = new Node();
    head->bottom->data = 7;

    head->next->bottom = new Node();
    head->next->bottom->data = 20;

    head->next->next->bottom = new Node();
    head->next->next->bottom->data = 22;

    head->next->next->next->bottom = new Node();
    head->next->next->next->bottom->data = 35;

    head->bottom->bottom = new Node();
    head->bottom->bottom->data = 8;

    head->next->bottom->bottom = new Node();
    head->next->bottom->bottom->data = 50;

    head->next->next->bottom->bottom = new Node();
    head->next->next->bottom->bottom->data = 40;

    head->next->next->next->bottom->bottom = new Node();
    head->next->next->next->bottom->bottom->data = 45;

    // Flatten the linked list
    head = flattenLinkedList(head);

    // Print the flattened linked list
    printFlattenedLinkedList(head);

    return 0;
}
