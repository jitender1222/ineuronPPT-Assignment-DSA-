#include <iostream>

using namespace std;

int numberOfCompleteRows(int n) {
    int completeRows = 0;
    int coins = n;
    int row = 1;
    
    while (coins >= row) {
        coins -= row;
        row++;
        completeRows++;
    }
    
    return completeRows;
}

int main() {
    int n = 5;
    
    int result = numberOfCompleteRows(n);
    
    cout << result << endl;
    
    return 0;
}
