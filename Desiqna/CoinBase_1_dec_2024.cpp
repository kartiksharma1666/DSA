#include <iostream>
#include <vector>
using namespace std;

int countSubsetsSizeKDivisibleByM(int N, int M, int K) {
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(M, vector<int>(K + 1, 0)));
    dp[0][0][0] = 1;  // 1 way to make sum 0 with 0 elements and size 0

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k <= K; k++) {
                dp[i][j][k] = dp[i - 1][j][k];  // Ignore current element
                if (k > 0) {
                    int remainder = (j - (i - 1) % M + M) % M;
                    dp[i][j][k] += dp[i - 1][remainder][k - 1];  // Include current element
                }
            }
        }
    }
    return dp[N][0][K];  // Return subsets with sum divisible by M and size K
}

int main() {
    int N = 5, M = 3, K = 2;
    cout << "Ways to pick subset of size " << K << " with sum divisible by " << M << ": " << countSubsetsSizeKDivisibleByM(N, M, K) << endl;
    return 0;
}
