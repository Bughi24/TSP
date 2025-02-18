#pragma once
#include "TSP.h"

int TSP::heuristic(int path[], int pathLength, int nextCity) {
    // Heuristic: use the minimum distance to the next unvisited city
    int minDist = INT_MAX;
    for (int i = 0; i < graph.numCities; ++i) {
        bool visited = false;
        for (int j = 0; j < pathLength; ++j) {
            if (path[j] == i) {
                visited = true;
                break;
            }
        }
        if (!visited && graph.getDistance(nextCity, i) < minDist) {
            minDist = graph.getDistance(nextCity, i);
        }
    }
    return minDist;
}

void TSP::aStarSearch(int start) {
    

    PriorityQueue::Node startNode;
    for (int i = 0; i < MAX_CITIES; ++i) {
        startNode.path[i] = -1; // Initialize with an invalid city
    }
    startNode.path[0] = start;
    startNode.cost = 0;
    startNode.pathLength = 1;
    startNode.cost += heuristic(startNode.path, startNode.pathLength, start);
    pq.push(startNode);

    int bestCost = INT_MAX;
    int bestPath[MAX_CITIES + 1] = { -1 }; // Initialize bestPath with an invalid city

    while (!pq.empty()) {
        PriorityQueue::Node currentNode = pq.pop();

        if (currentNode.pathLength == graph.numCities) {
            int totalCost = currentNode.cost + graph.getDistance(currentNode.path[currentNode.pathLength - 1], start);
            if (totalCost < bestCost) {
                bestCost = totalCost;
                for (int i = 0; i < currentNode.pathLength; ++i) {
                    bestPath[i] = currentNode.path[i];
                }
                bestPath[currentNode.pathLength] = start;
            }
            continue;
        }

        for (int i = 0; i < graph.numCities; ++i) {
            bool visited = false;
            for (int j = 0; j < currentNode.pathLength; ++j) {
                if (currentNode.path[j] == i) {
                    visited = true;
                    break;
                }
            }

            if (!visited && graph.getDistance(currentNode.path[currentNode.pathLength - 1], i) != INT_MAX) {
                PriorityQueue::Node newNode;
                for (int j = 0; j < currentNode.pathLength; ++j) {
                    newNode.path[j] = currentNode.path[j];
                }
                newNode.path[currentNode.pathLength] = i;
                newNode.cost = currentNode.cost + graph.getDistance(currentNode.path[currentNode.pathLength - 1], i);
                newNode.pathLength = currentNode.pathLength + 1;
                newNode.cost += heuristic(newNode.path, newNode.pathLength, i);

                pq.push(newNode);
            }
        }
    }

    cout << "A* Result: ";
    for (int i = 0; i <= graph.numCities; ++i) {
        if (bestPath[i] != -1) { // Only print valid cities
            cout << bestPath[i] << " ";
        }
    }
    cout << "Cost: " << bestCost << endl;
}