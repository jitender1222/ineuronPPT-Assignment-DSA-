#include <iostream>

struct Node
{
    int data;
    Node *next;
};

int nthNodeFromEnd(Node *head, int n)
{
    if (head == nullptr)
        return -1;

    Node *slowPtr = head;
    Node *fastPtr = head;

    // Move the fast pointer n positions ahead
    for (int i = 0; i < n; i++)
    {
        if (fastPtr == nullptr)
            return -1; // Invalid value of n
        fastPtr = fastPtr->next;
    }

    // Move both pointers until the fast pointer reaches the end
    while (fastPtr != nullptr)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
    }

    if (slowPtr == nullptr)
        return -1; // Invalid value of n
    return slowPtr->data;
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

    int n = 2;
    int result = nthNodeFromEnd(head, n);
    if (result != -1)
        std::cout << "Nth Node from the End: " << result << std::endl;
    else
        std::cout << "Invalid value of n!" << std::endl;

    return 0;
}
