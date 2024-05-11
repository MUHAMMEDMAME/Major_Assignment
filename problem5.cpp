#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
    int first, second;
};

bool comparePairs(const Pair& a, const Pair& b) {
    return a.first < b.first; // Sort pairs based on the first number in ascending order
}

int maxChainLen(vector<Pair>& pairs, int n) {
    // Sort pairs based on the first number in ascending order
    sort(pairs.begin(), pairs.end(), comparePairs);

    // Initialize dp table with all values as 1
    vector<int> dp(n, 1);

    // Iterate through pairs
    for (int i = 1; i < n; ++i) {
        // Check all previous pairs
        for (int j = 0; j < i; ++j) {
            // If the current pair can follow the previous pair, update dp table
            if (pairs[i].first > pairs[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // Find the maximum value in the dp table
    int maxLength = *max_element(dp.begin(), dp.end());

    return maxLength;
}

int main() {
    // Example usage
    int n = 5;
    vector<Pair> pairs = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
    cout << maxChainLen(pairs, n) << endl; // Output: 3

    return 0;
}
