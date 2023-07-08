#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

vector<int> nextLargerNodes(ListNode *head)
{
    vector<int> result;

    if (head == nullptr)
        return result;

    stack<int> stack;
    ListNode *curr = head;

    while (curr != nullptr)
    {
        while (!stack.empty() && result[stack.top()] < curr->val)
        {
            result[stack.top()] = curr->val;
            stack.pop();
        }
        stack.push(result.size());
        result.push_back(curr->val);
        curr = curr->next;
    }

    while (!stack.empty())
    {
        result[stack.top()] = 0;
        stack.pop();
    }

    return result;
}

int main()
{
    // Create a linked list

    ListNode *head = new ListNode(2);
    ListNode *node2 = new ListNode(7);
    ListNode *node3 = new ListNode(4);
    ListNode *node4 = new ListNode(3);
    ListNode *node5 = new ListNode(5);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // Find the next greater node for each node
    vector<int> result = nextLargerNodes(head);

    // Print the result
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
