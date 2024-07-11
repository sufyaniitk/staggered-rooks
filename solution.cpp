#include <iostream>
using namespace std;

int main() {
    int n; cin >> n; // take input
    int ans[n+1][n+1]; // ans[i] is used to find the i+1 - th Bell number.

    ans[0][0] = 1; // initialise
    for (int i = 1; i < n+1; i++) {
        ans[i][0] = ans[i-1][i-1]; // copy last value from previous row into first value of current row
        for (int j = 1; j <= i; j++) {
            ans[i][j] = ans[i][j-1] + ans[i-1][j-1]; // do the stepwise addition
        }
    }

    cout << ans[n][n] - 1 << endl; // final answer is B(n+1) - 1
    return 0;
}
