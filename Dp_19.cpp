#include <iostream>
#include <vector>
using namespace std;

int main() {
    int y;
    cin >> y;
    
    // Create DP table
    vector<vector<int>> dp(y + 1, vector<int>(3, 0));

    // Base cases
    if (y >= 1) {
        dp[1][0] = dp[1][1] = dp[1][2] = 1;
    }

    // Fill DP table
    for (int i = 2; i <= y; i++) {
        dp[i][0] = dp[i - 1][0] 
                   + (i >= 2 ? dp[i - 2][0] : 0) 
                   + (i >= 6 ? dp[i - 6][0] : 0);

        dp[i][1] = dp[i - 1][1] 
                   + (i >= 2 ? dp[i - 2][1] : 0) 
                   + (i >= 4 ? dp[i - 4][0] : 0) 
                   + (i >= 6 ? dp[i - 6][1] : 0);

        dp[i][2] = dp[i - 1][2] 
                   + (i >= 2 ? dp[i - 2][2] : 0) 
                   + (i >= 4 ? dp[i - 4][1] : 0) 
                   + (i >= 6 ? dp[i - 6][2] : 0);
    }

    // Calculate result
    cout << dp[y][0] + dp[y][1] + dp[y][2];
    return 0;
}
