#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& maze, int x, int y, string& path, vector<string>& paths) {
    int N = maze.size();
    
    // Base case: If the current cell is the destination, add the path to the result
    if (x == N - 1 && y == N - 1) {
        paths.push_back(path);
        return;
    }
    
    // Directions: Up, Down, Left, Right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    char directions[] = {'U', 'D', 'L', 'R'};
    
    // Explore all four directions
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        // Check if the new cell is within bounds and not blocked
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && maze[nx][ny] == 1) {
            maze[x][y] = 0; // Mark current cell as visited
            path.push_back(directions[i]); // Append direction to the path
            dfs(maze, nx, ny, path, paths); // Explore further
            path.pop_back(); // Backtrack
            maze[x][y] = 1; // Reset current cell
        }
    }
}

vector<string> printPath(int N, vector<vector<int>> maze) {
    vector<string> paths;
    string path;
    
    // Check if the source and destination cells are unblocked
    if (maze[0][0] == 1 && maze[N - 1][N - 1] == 1) {
        dfs(maze, 0, 0, path, paths);
    }
    
    // Sort paths lexicographically
    sort(paths.begin(), paths.end());
    
    return paths;
}

int main() {
    // Example usage
    int N = 4;
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                 {1, 1, 0, 1},
                                 {1, 1, 0, 0},
                                 {0, 1, 1, 1}};
    
    vector<string> paths = printPath(N, maze);
    
    if (paths.empty()) {
        cout << "-1\n"; // No path exists
    } else {
        for (const string& path : paths) {
            cout << path << " "; // Output paths
        }
        cout << endl;
    }

    return 0;
}
