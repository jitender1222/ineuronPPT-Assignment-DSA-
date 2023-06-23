#include <deque>

class DataStream
{
private:
    std::deque<int> stream;
    int value;
    int k;

public:
    DataStream(int value, int k)
    {
        this->value = value;
        this->k = k;
    }

    bool consec(int num)
    {
        stream.push_back(num);
        if (stream.size() < k)
        {
            return false;
        }
        if (stream.size() > k)
        {
            stream.pop_front();
        }
        for (int i = 0; i < k; i++)
        {
            if (stream[i] != value)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    DataStream ds(5, 3);
    ds.consec(5);
    ds.consec(5);
    ds.consec(5);
    ds.consec(3);
    ds.consec(5);

    return 0;
}
