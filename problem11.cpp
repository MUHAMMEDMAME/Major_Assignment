
#include<iostream>
#include<numeric>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int>& pages, int n, int m, int mid) {
    int students = 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (pages[i] > mid) {
            return false;
        }
        if (sum + pages[i] > mid) {
            students++;
            sum = pages[i];
        } else {
            sum += pages[i];
        }
    }
    return students <= m;
}

int findPages(int N, vector<int> A, int M) {
    if (N < M) {
        return -1;
    }
    int start = *max_element(A.begin(), A.end());
    int end = accumulate(A.begin(), A.end(), 0);
    int result = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isPossible(A, N, M, mid)) {
            result = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }

        int main(){

            return 0;
        }
    }
    return result;
}
