#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void deleteLastOccurrence(Node *head, int key)
{
    Node *lastOccur = nullptr;
    Node *current = head;
    Node *prev = nullptr;

    while (current != nullptr)
    {
        if (current->data == key)
            lastOccur = prev;
        prev = current;
        current = current->next;
    }

    if (lastOccur != nullptr)
    {
        Node *temp = lastOccur->next;
        lastOccur->next = temp->next;
        delete temp;
    }
    else if (head->data == key)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void displayList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(5);
    head->next->next->next->next = createNode(2);
    head->next->next->next->next->next = createNode(4);
    head->next->next->next->next->next->next = createNode(2);

    int key = 2;

    cout << "Input: LinkedList: ";
    displayList(head);
    cout << "Key = " << key << endl;

    deleteLastOccurrence(head, key);

    cout << "Output: ";
    displayList(head);

    return 0;
}
