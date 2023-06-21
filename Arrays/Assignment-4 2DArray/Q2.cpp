#include <iostream>
#include <unordered_set>

struct Node
{
    int data;
    Node *next;
};

bool detectLoop(Node *head)
{
    std::unordered_set<Node *> visited;
    while (head != nullptr)
    {
        if (visited.find(head) != visited.end())
            return true;
        visited.insert(head);
        head = head->next;
    }
    return false;
}

int main()
{
    Node *head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};

    // Create a loop for testing
    head->next->next->next->next = head;

    if (detectLoop(head))
        std::cout << "Loop Found!" << std::endl;
    else
        std::cout << "No Loop Found!" << std::endl;

    return 0;
}
