#include <iostream>

struct Node
{
    int data;
    Node *next;
};

void retainDeleteNodes(Node *head, int M, int N)
{
    Node *current = head;
    Node *temp;

    int count;
    while (current)
    {
        // Retain M nodes
        for (count = 1; count < M && current != nullptr; count++)
            current = current->next;

        if (current == nullptr)
            return;

        // Delete N nodes
        temp = current->next;
        for (count = 1; count <= N && temp != nullptr; count++)
        {
            Node *next = temp;
            temp = temp->next;
            delete next;
        }
        current->next = temp;
        current = temp;
    }
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    Node *head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};
    head->next->next->next->next = new Node{5, nullptr};
    head->next->next->next->next->next = new Node{6, nullptr};
    head->next->next->next->next->next->next = new Node{7, nullptr};
    head->next->next->next->next->next->next->next = new Node{8, nullptr};
    head->next->next->next->next->next->next->next->next = new Node{9, nullptr};
    head->next->next->next->next->next->next->next->next->next = new Node{10, nullptr};

    int M = 2;
    int N = 2;

    std::cout << "Original Linked List: ";
    printList(head);

    retainDeleteNodes(head, M, N);

    std::cout << "Modified Linked List: ";
    printList(head);

    return 0;
}
