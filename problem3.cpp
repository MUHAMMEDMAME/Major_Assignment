//
//  problem3.cpp
//  Major_Assignment
//
//  Created by muhammed on 9.05.2024.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id, deadline, profit;
};

bool compareJobs(const Job& a, const Job& b) {
    return a.deadline < b.deadline; // Sort jobs by deadline in non-decreasing order
}

vector<int> JobScheduling(vector<Job>& jobs, int N) {
    // Sort jobs based on deadline in non-decreasing order
    sort(jobs.begin(), jobs.end(), compareJobs);

    // Find maximum deadline
    int maxDeadline = 0;
    for (const auto& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    // Initialize dp table
    vector<vector<int>> dp(N + 1, vector<int>(maxDeadline + 1, 0));

    // Iterate through jobs
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= maxDeadline; ++j) {
            if (jobs[i - 1].deadline <= j) {
                // Consider the current job
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - jobs[i - 1].deadline] + jobs[i - 1].profit);
            } else {
                // Don't consider the current job
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return {N, dp[N][maxDeadline]};
}

int main() {
    // Example usage
    int N = 4;
    vector<Job> jobs = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    vector<int> result = JobScheduling(jobs, N);
    cout << result[0] << " " << result[1] << endl; // Output: 2 60

    return 0;
}
