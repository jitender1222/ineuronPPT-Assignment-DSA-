#include <iostream>

struct Node
{
    int data;
    Node *next;
};

bool isCircularLinkedList(Node *head)
{
    // An empty list or a list with a single node is not circular
    if (head == nullptr || head->next == nullptr)
        return false;

    // Start from the head node
    Node *slowPtr = head;
    Node *fastPtr = head;

    // Move slowPtr by one node and fastPtr by two nodes
    while (fastPtr != nullptr && fastPtr->next != nullptr)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        // If they meet at the same node, the list is circular
        if (slowPtr == fastPtr)
            return true;
    }

    // If fastPtr reaches the end of the list, it's not circular
    return false;
}

int main()
{
    Node *head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};

    // Create a circular linked list by connecting the last node to the head
    head->next->next->next->next = head;

    if (isCircularLinkedList(head))
        std::cout << "The linked list is circular." << std::endl;
    else
        std::cout << "The linked list is not circular." << std::endl;

    return 0;
}
