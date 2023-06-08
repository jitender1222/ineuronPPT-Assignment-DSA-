#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char auxiliary, char destination, int &moves)
{
    if (n == 1)
    {
        cout << "move disk 1 from rod " << source << " to rod " << destination << endl;
        moves++;
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary, moves);
    cout << "move disk " << n << " from rod " << source << " to rod " << destination << endl;
    moves++;
    towerOfHanoi(n - 1, auxiliary, source, destination, moves);
}

int main()
{
    int n = 3;
    char source = '1', auxiliary = '2', destination = '3';
    int moves = 0;
    towerOfHanoi(n, source, auxiliary, destination, moves);
    cout << moves << endl;
    return 0;
}
