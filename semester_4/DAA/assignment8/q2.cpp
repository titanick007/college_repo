#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

// Define the dimensions of the maze
const int ROWS = 5;
const int COLS = 5;

// Function to check if a cell is valid to move into
bool isValid(int x, int y, vector<vector<int>>& maze) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y] == 1;
}

// Function to perform BFS to solve the maze
bool solveMaze(vector<vector<int>>& maze, pair<int, int> start, pair<int, int> end) {
    // Create a queue for BFS
    queue<pair<int, int>> q;

    // Mark the start cell as visited
    maze[start.first][start.second] = 0; // Assuming 0 represents visited

    // Enqueue the start cell
    q.push(start);

    // Array to represent possible moves (up, down, left, right)
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // Perform BFS
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        // Check if we have reached the destination
        if (current == end)
            return true;

        // Explore adjacent cells
        for (int i = 0; i < 4; ++i) {
            int newX = current.first + dx[i];
            int newY = current.second + dy[i];

            // Check if the new cell is valid and not visited
            if (isValid(newX, newY, maze)) {
                // Mark the new cell as visited
                maze[newX][newY] = 0;
                // Enqueue the new cell
                q.push({newX, newY});
            }
        }
    }

    // If destination not reached
    return false;
}

int main() {
    // Example maze represented as a 2D grid
    vector<vector<int>> maze = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 1, 1},
        {1, 0, 1, 1, 0},
        {1, 1, 1, 0, 1}
    };

    pair<int, int> start = {0, 0}; // Start position
    pair<int, int> end = {4, 4}; // End position

    if (solveMaze(maze, start, end))
        cout << "Path found from start to end." << endl;
    else
        cout << "No path found from start to end." << endl;

    return 0;
}

