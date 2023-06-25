#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    auto comp = [](const ListNode *a, const ListNode *b)
    {
        return a->val > b->val;
    };
    priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> pq(comp);

    for (ListNode *list : lists)
    {
        if (list)
            pq.push(list);
    }

    ListNode dummy(0);
    ListNode *tail = &dummy;

    while (!pq.empty())
    {
        ListNode *curr = pq.top();
        pq.pop();
        tail->next = curr;
        tail = tail->next;

        if (curr->next)
            pq.push(curr->next);
    }

    return dummy.next;
}

int main()
{
    // Create the input linked lists
    vector<ListNode *> lists;
    // Add code to create and populate the lists...

    // Merge the lists
    ListNode *mergedList = mergeKLists(lists);

    // Print the merged list
    while (mergedList)
    {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    return 0;
}
