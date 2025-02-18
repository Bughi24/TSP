#include "TSP.h"

// Depth-first search implementation
void TSP::dfs(int current, bool visited[], int path[], int& pathIndex, int& bestCost, int bestPath[], int currentCost) {
    visited[current] = true;
    path[pathIndex++] = current;

    // If all cities are visited, calculate the cost and update the best path if needed
    if (pathIndex == graph.numCities) {
        currentCost += graph.getDistance(current, path[0]);
        if (currentCost < bestCost) {
            bestCost = currentCost;
            for (int i = 0; i < pathIndex; i++) {
                bestPath[i] = path[i];
            }
            bestPath[pathIndex] = path[0];
        }
    }
    else {
        // Visit unvisited cities recursively
        for (int i = 0; i < graph.numCities; i++) {
            if (!visited[i] && graph.getDistance(current, i) != INT_MAX) {
                dfs(i, visited, path, pathIndex, bestCost, bestPath, currentCost + graph.getDistance(current, i));
            }
        }
    }

    // Backtrack and mark the current city as unvisited
    visited[current] = false;
    --pathIndex;
}

// Depth-first search method
void TSP::depthFirstSearch(int start) {
    bool visited[MAX_CITIES] = { false }; // Array to track visited cities
    int path[MAX_CITIES + 1];             // Array to store the current path
    int bestPath[MAX_CITIES + 1];         // Array to store the best path
    int pathIndex = 0;                     // Index to track the current path
    int bestCost = INT_MAX;                // Variable to store the best cost

    // Perform depth-first search starting from the specified city
    dfs(start, visited, path, pathIndex, bestCost, bestPath, 0);

    // Print the result
    cout << "DFS Result: ";
    for (int i = 0; i <= graph.numCities; i++) {
        cout << cities[bestPath[i]].getName() << " "; // Print city names instead of indices
    }
    cout << "Cost: " << bestCost << endl;
}
