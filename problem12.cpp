#include <vector>
using namespace std;

int numberSequence(int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Base case: when n equals to 1, there is only one possible sequence for each number 1 to m.
    for (int i = 1; i <= m; ++i)
        dp[i][1] = 1;

    // Filling the dp table
    for (int j = 2; j <= n; ++j) {
        for (int i = 1; i <= m; ++i) {
            // For each dp[i][j], it can be obtained by adding up dp[k][j - 1] for k = i/2 to i.
            for (int k = i / 2; k <= i; ++k) {
                dp[i][j] += dp[k][j - 1];
            }
        }
    }

    // Summing up the last row of dp table to get the total number of possible sequences.
    int total_sequences = 0;
    for (int i = 1; i <= m; ++i)
        total_sequences += dp[i][n];

    return total_sequences;
}

int main(){


    return 0;
}
