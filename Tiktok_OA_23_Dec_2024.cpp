#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int countValidStrings(int n, int k) {
    // Initialize dp and prefix sum arrays
    vector<vector<int>> dp(n + 1, vector<int>(26, 0));
    vector<vector<int>> prefix(n + 1, vector<int>(26, 0));

    // Base case: Strings of length 1
    for (int c = 0; c < 26; c++) {
        dp[1][c] = 1;
        prefix[1][c] = (c == 0) ? dp[1][c] : (prefix[1][c - 1] + dp[1][c]) % MOD;
    }

    // Compute dp[i][c] using prefix sums
    for (int i = 2; i <= n; i++) {
        for (int c = 0; c < 26; c++) {
            int l = max(0, c - k);
            int r = min(25, c + k);

            if (l > 0)
                dp[i][c] = (prefix[i - 1][r] - prefix[i - 1][l - 1] + MOD) % MOD;
            else
                dp[i][c] = prefix[i - 1][r];

            // Update the prefix sum for dp[i]
            prefix[i][c] = (c == 0) ? dp[i][c] : (prefix[i][c - 1] + dp[i][c]) % MOD;
        }
    }

    // Calculate the total count of valid strings of length n
    int result = 0;
    for (int c = 0; c < 26; c++) {
        result = (result + dp[n][c]) % MOD;
    }

    return result;
}

int main() {
    int n, k;
    cout << "Enter string length (n) and max difference (k): ";
    cin >> n >> k;

    cout << "Number of valid strings: " << countValidStrings(n, k) << endl;

    return 0;
}
