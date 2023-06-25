#include <deque>

class FrontMiddleBackQueue
{
private:
    std::deque<int> queue;

public:
    FrontMiddleBackQueue()
    {
    }

    void pushFront(int val)
    {
        queue.push_front(val);
    }

    void pushMiddle(int val)
    {
        int mid = queue.size() / 2;
        queue.insert(queue.begin() + mid, val);
    }

    void pushBack(int val)
    {
        queue.push_back(val);
    }

    int popFront()
    {
        if (queue.empty())
        {
            return -1;
        }
        int val = queue.front();
        queue.pop_front();
        return val;
    }

    int popMiddle()
    {
        if (queue.empty())
        {
            return -1;
        }
        int mid = queue.size() / 2;
        int val = queue[mid];
        queue.erase(queue.begin() + mid);
        return val;
    }

    int popBack()
    {
        if (queue.empty())
        {
            return -1;
        }
        int val = queue.back();
        queue.pop_back();
        return val;
    }
};

int main()
{
    FrontMiddleBackQueue q;
    q.pushFront(1);
    q.pushBack(2);
    q.pushMiddle(3);
    q.pushMiddle(4);
    q.popFront();
    q.popMiddle();
    q.popMiddle();
    q.popBack();
    q.popFront();

    return 0;
}
