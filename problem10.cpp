#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

void DFS(vector<vector<char>>& board, int i, int j, vector<string>& result, string& current, unordered_set<string>& dictionary) {
    int rows = board.size();
    int cols = board[0].size();

    // Base case: If the current prefix is not in the dictionary, return
    if (current.size() > 0 && dictionary.find(current) == dictionary.end()) {
        return;
    }

    // Base case: If the current word is found in the dictionary, add it to the result
    if (dictionary.find(current) != dictionary.end()) {
        result.push_back(current);
        // Remove the word from the dictionary to avoid duplicates
        dictionary.erase(current);
    }

    // Directions: Up, Down, Left, Right, Diagonals
    int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
    
    char temp = board[i][j]; // Store the current character before exploration
    board[i][j] = '*'; // Mark the current cell as visited
    
    // Explore all adjacent cells
    for (int k = 0; k < 8; ++k) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && board[ni][nj] != '*') {
            current.push_back(board[ni][nj]); // Append the character to the current word
            DFS(board, ni, nj, result, current, dictionary); // Explore further
            current.pop_back(); // Backtrack
        }
    }
    
    board[i][j] = temp; // Restore the original character
}

vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
    vector<string> result;
    unordered_set<string> dict(dictionary.begin(), dictionary.end());
    string current = "";
    int rows = board.size();
    int cols = board[0].size();

    // Start DFS from each cell on the board
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            current.push_back(board[i][j]);
            DFS(board, i, j, result, current, dict);
            current.pop_back();
        }
    }

    // Sort the result in lexicographical order
    sort(result.begin(), result.end());

    return result;
}

int main() {
    // Example usage
    vector<vector<char>> board = {{'C','A','P'}, {'A','N','D'}, {'T','I','E'}};
    vector<string> dictionary = {"CAT"};
    vector<string> words = wordBoggle(board, dictionary);
    for (const string& word : words) {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}
