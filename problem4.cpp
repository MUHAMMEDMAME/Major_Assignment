#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
    int first, second;
};

bool comparePairs(const Pair& a, const Pair& b) {
    return a.second < b.second; // Sort pairs based on the second number in ascending order
}

int maxChainLen(vector<Pair>& pairs, int n) {
    // Sort pairs based on the second number in ascending order
    sort(pairs.begin(), pairs.end(), comparePairs);

    // Initialize variables
    int maxLength = 0;
    int end = INT_MIN;

    // Iterate through sorted pairs
    for (int i = 0; i < n; ++i) {
        // If the first number of the current pair is greater than or equal to the end
        // of the previous pair, update the end and increment the maxLength
        if (pairs[i].first > end) {
            end = pairs[i].second;
            maxLength++;
        }
    }

    return maxLength;
}

int main() {
    // Example usage
    int n = 5;
    vector<Pair> pairs = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
    cout << maxChainLen(pairs, n) << endl; // Output: 3

    return 0;
}
