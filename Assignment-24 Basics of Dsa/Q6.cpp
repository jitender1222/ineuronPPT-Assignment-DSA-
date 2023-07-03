#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

vector<string> topKFrequent(vector<string> &words, int k)
{
    unordered_map<string, int> count;
    for (string word : words)
        count[word]++;

    auto compare = [](pair<string, int> &a, pair<string, int> &b)
    {
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    };

    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(compare)> pq(compare);

    for (auto it = count.begin(); it != count.end(); it++)
    {
        pq.push(*it);
        if (pq.size() > k)
            pq.pop();
    }

    vector<string> result(k);

    for (int i = k - 1; i >= 0; i--)
    {
        result[i] = pq.top().first;
        pq.pop();
    }

    return result;
}

int main()
{
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;
    vector<string> topK = topKFrequent(words, k);

    for (string word : topK)
    {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
