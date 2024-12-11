#include <iostream>
#include <vector>
using namespace std;

// Dimensions of the maze
const int rows = 15;
const int cols = 15;

// Function to print the maze
void printMaze(char maze[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << maze[i][j] << ' ';
        }
        cout << endl;
    }
}

// DFS function to find the path
bool dfs(int x, int y, char maze[rows][cols]) {
    // Check bounds and if the cell is a wall or already visited
    if (x < 0 || y < 0 || x >= rows || y >= cols || maze[x][y] == '#' || maze[x][y] == '*')
        return false;

    // Check if we reached the end
    if (maze[x][y] == 'E')
        return true;

    // Mark the current cell as visited
    if (maze[x][y] != 'S') maze[x][y] = '*';

    // Explore all directions (down, up, right, left)
    if (dfs(x + 1, y, maze)) return true; // Down
    if (dfs(x - 1, y, maze)) return true; // Up
    if (dfs(x, y + 1, maze)) return true; // Right
    if (dfs(x, y - 1, maze)) return true; // Left

    // Backtrack if no path is found
    if (maze[x][y] != 'S') maze[x][y] = ' ';
    return false;
}

int main() {
    // Updated maze layout
    char maze[rows][cols] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'E'},
        {'#', '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', ' ', '#'},
        {'#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#'},
        {'#', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#'},
        {'S', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    // Print the original maze
    cout << "Original Maze:\n";
    printMaze(maze);

    // Perform DFS from the start point (13, 0)
    if (dfs(13, 0, maze)) {
        cout << "\nPath Found (DFS):\n";
    }
    else {
        cout << "\nNo Path Found!\n";
    }

    // Print the maze with the path
    printMaze(maze);

    return 0;
}
