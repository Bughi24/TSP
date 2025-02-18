#include "TSP.h"

// Uniform Cost Search method
void TSP::uniformCostSearch(int start) {
    // Initialize the start node with the given start city
    PriorityQueue::Node startNode;
    startNode.path[0] = start;
    startNode.cost = 0;
    startNode.pathLength = 1;

    // Push the start node into the priority queue
    pq.push(startNode);

    // Initialize variables to store the best cost and best path
    int bestCost = INT_MAX;
    int bestPath[MAX_CITIES + 1];

    // Perform uniform cost search until the priority queue is empty
    while (!pq.empty()) {
        // Pop the node with the lowest cost from the priority queue
        PriorityQueue::Node currentNode = pq.pop();

        // If all cities are visited, calculate the total cost and update the best path if needed
        if (currentNode.pathLength == graph.numCities) {
            int totalCost = currentNode.cost + graph.getDistance(currentNode.path[currentNode.pathLength - 1], start);
            if (totalCost < bestCost) {
                bestCost = totalCost;
                for (int i = 0; i < currentNode.pathLength; i++) {
                    bestPath[i] = currentNode.path[i];
                }
                bestPath[currentNode.pathLength] = start;
            }
            continue;
        }

        // Explore unvisited neighboring cities
        for (int i = 0; i < graph.numCities; i++) {
            bool visited = false;
            for (int j = 0; j < currentNode.pathLength; j++) {
                if (currentNode.path[j] == i) {
                    visited = true;
                    break;
                }
            }

            // If the neighboring city is unvisited and there is a direct connection, create a new node and push it into the priority queue
            if (!visited && graph.getDistance(currentNode.path[currentNode.pathLength - 1], i) != INT_MAX) {
                PriorityQueue::Node newNode;
                for (int j = 0; j < currentNode.pathLength; ++j) {
                    newNode.path[j] = currentNode.path[j];
                }
                newNode.path[currentNode.pathLength] = i;
                newNode.cost = currentNode.cost + graph.getDistance(currentNode.path[currentNode.pathLength - 1], i);
                newNode.pathLength = currentNode.pathLength + 1;

                pq.push(newNode);
            }
        }
    }

    // Print the result
    cout << "UCS Result: ";
    for (int i = 0; i <= graph.numCities; ++i) {
        cout << cities[bestPath[i]].getName() << " ";
    }
    cout << "Cost: " << bestCost << endl;
}
