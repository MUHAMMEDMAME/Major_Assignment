//Name:Mohamad Nour Maama
//major assignment
//id:221504813

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the maximum number of meetings
int maxMeetings(vector<int>& start, vector<int>& end, int N) {
    // Combine start and end times into pairs and sort based on end times
    vector<pair<int, int>> meetings;
    for (int i = 0; i < N; ++i) {
        meetings.push_back({end[i], start[i]}); // Pairing end time with start time
    }
    sort(meetings.begin(), meetings.end());

    // Initialize variables
    int count = 1;
    int endTime = meetings[0].first;  // End time of the first meeting
    
    // Iterate through sorted meetings
    for (int i = 1; i < N; ++i) {
        // If the start time of the current meeting is greater than or equal to
        // the end time of the previously selected meeting, increment count and update endTime
        if (meetings[i].second >= endTime) {
            count++;
            endTime = meetings[i].first;
        }
    }
    
    return count;
}
int main() {
    // Example usage
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    int N = 6;
    cout << maxMeetings(start, end, N) << endl;  // Output: 4
    
    return 0;
}
