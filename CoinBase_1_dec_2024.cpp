#include <iostream>
#include <vector>
using namespace std;

int countSubsetsSizeKDivisibleByM(int N, int M, int K) {
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(M, vector<int>(K + 1, 0)));
    dp[0][0][0] = 1;  // 1 way to make sum 0 with 0 elements

    for (int i = 1; i <= N; i++) {
        int v1 = (i - 1) % M;  // Current value modulo M
        for (int j = 0; j < M; j++) {
            for (int k = 0; k <= K; k++) {
                // Ignore the current element
                dp[i][j][k] = dp[i - 1][j][k];

                // Include the current element if k > 0
                if (k > 0) {
                    int l = (j >= v1) ? (j - v1) : (M - v1 + j);
                    dp[i][j][k] += dp[i - 1][l][k - 1];
                }
            }
        }
    }

    return dp[N][0][K];  // Ways to get sum divisible by M with exactly K elements
}

int main() {
    int N = 5, M = 3, K = 2;
    cout << "Ways to get sum divisible by " << M << " with subset size " << K 
         << ": " << countSubsetsSizeKDivisibleByM(N, M, K) << endl;
    return 0;
}
