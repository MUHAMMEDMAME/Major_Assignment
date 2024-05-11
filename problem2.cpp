#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id, deadline, profit;
};

bool compareJobs(const Job& a, const Job& b) {
    return a.profit > b.profit; // Sort jobs by profit in decreasing order
}

vector<int> JobScheduling(vector<Job>& jobs, int N) {

    sort(jobs.begin(), jobs.end(), compareJobs);


    vector<bool> slots(N, false);

    int count = 0, totalProfit = 0;


    for (int i = 0; i < N; ++i) {
        int deadline = jobs[i].deadline;

        for (int j = min(N, deadline) - 1; j >= 0; --j) {
            if (!slots[j]) {
                slots[j] = true; // Mark slot as unavailable
                count++; // Increment count of scheduled jobs
                totalProfit += jobs[i].profit; // Add profit of the scheduled job
                break;
            }
        }
    }

    return {count, totalProfit};
}

int main() {
    // Example usage
    int N = 4;
    vector<Job> jobs = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    vector<int> result = JobScheduling(jobs, N);
    cout << result[0] << " " << result[1] << endl; // Output: 2 60

    return 0;
}

