#pragma once
#include "Graph.h"
#include "PriorityQueue.h"
#include <iostream>

using namespace std;

class TSP {
public:
    Graph graph;
    int numCities;
    City *cities = new City[numCities];

    TSP(Graph g,int numCities,City* c) : graph(g),numCities(numCities) {
        for (int i = 0; i < numCities; i++)
        {
            cities[i] = c[i];
        }
    }

    void depthFirstSearch(int start);
    void uniformCostSearch(int start);
    void aStarSearch(int start);

private:
    void dfs(int current, bool visited[], int path[], int& pathIndex, int& bestCost, int bestPath[], int currentCost);
    PriorityQueue pq;
    int heuristic(int path[], int pathLength, int nextCity);
};

