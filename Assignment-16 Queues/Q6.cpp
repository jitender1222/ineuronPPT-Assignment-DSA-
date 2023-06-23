#include <queue>
#include <vector>
#include <algorithm>

std::vector<int> deckRevealedIncreasing(std::vector<int> &deck)
{
    std::sort(deck.begin(), deck.end(), std::greater<int>());
    std::queue<int> q;
    q.push(deck[0]);

    for (int i = 1; i < deck.size(); i++)
    {
        q.push(q.front());
        q.pop();
        q.push(deck[i]);
    }

    std::vector<int> result;
    while (!q.empty())
    {
        result.push_back(q.front());
        q.pop();
    }

    std::reverse(result.begin(), result.end());

    return result;
}

int main()
{
    std::vector<int> deck = {17, 13, 11, 2, 3, 5, 7};
    std::vector<int> orderedDeck = deckRevealedIncreasing(deck);

    return 0;
}
