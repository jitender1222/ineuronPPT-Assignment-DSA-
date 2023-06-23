#include <queue>

class RecentCounter
{
private:
    std::queue<int> requests;

public:
    RecentCounter()
    {
    }

    int ping(int t)
    {
        requests.push(t);
        while (requests.front() < t - 3000)
        {
            requests.pop();
        }
        return requests.size();
    }
};

int main()
{
    RecentCounter recentCounter;
    recentCounter.ping(1);
    recentCounter.ping(100);
    recentCounter.ping(3001);
    recentCounter.ping(3002);

    return 0;
}
