#include <iostream>
#include <vector>
#include <algorithm> // For max()

using namespace std;

int main() {
    vector<int> a = {0, 23, 4, 5, 101}; // Add a dummy `0` at index 0
    vector<int> b = {0, 21, 1, 10, 100}; // Add a dummy `0` at index 0
    int n = a.size() - 1; // Adjust size for 1-based indexing

    // Dynamic programming table
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[1][0] = a[1];
    dp[1][1] = b[1];

    for (int i = 2; i <= n; ++i) {
        dp[i][0] = max(a[i] + dp[i - 1][0], a[i] + dp[i - 2][1]);
        dp[i][1] = max(b[i] + dp[i - 1][1], b[i] + dp[i - 2][0]);
    }

    cout << max(dp[n][0], dp[n][1]) << endl;
    return 0;
}
