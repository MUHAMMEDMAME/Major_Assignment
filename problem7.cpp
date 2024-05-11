#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int v, vector<vector<int>>& graph, int m, vector<int>& color) {
    if (v == graph.size()) {
        return true; // All vertices are colored
    }

    for (int c = 1; c <= m; ++c) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c; // Assign color c to vertex v

            // Recur for next vertex
            if (graphColoringUtil(v + 1, graph, m, color)) {
                return true;
            }

            // If assigning color c doesn't lead to a solution, backtrack
            color[v] = 0;
        }
    }

    return false; // No valid color found for this vertex
}

bool graphColoring(vector<vector<int>>& graph, int m) {
    vector<int> color(graph.size(), 0); // Initialize colors for all vertices as 0

    // Start coloring from vertex 0
    if (graphColoringUtil(0, graph, m, color)) {
        return true; // Solution found
    }

    return false; // No solution found
}

int main() {
    int N = 4; // Number of vertices
    int M = 3; // Number of colors
    int E = 5; // Number of edges

    // Define the graph as an adjacency matrix
    vector<vector<int>> graph(N, vector<int>(N, 0));
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2}};

    // Mark edges in the graph
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        graph[u][v] = graph[v][u] = 1; // Mark edge between vertices u and v
    }

    // Check if graph can be colored with at most M colors
    if (graphColoring(graph, M)) {
        cout << "1\n"; // Graph can be colored
    } else {
        cout << "0\n"; // Graph cannot be colored
    }

    return 0;
}
