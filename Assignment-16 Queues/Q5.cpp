#include <vector>

int findTheWinner(int n, int k)
{
    std::vector<int> friends(n);
    int currFriend = 0;

    for (int i = 1; i <= n; i++)
    {
        friends[currFriend] = i;
        currFriend = (currFriend + k - 1) % (n - i + 1);
    }

    return friends[0];
}

int main()
{
    int n = 5;
    int k = 2;

    int winner = findTheWinner(n, k);

    return 0;
}
