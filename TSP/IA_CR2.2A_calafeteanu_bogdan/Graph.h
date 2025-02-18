#pragma once
#include "City.h"

class Graph
{
public:
    int distances[MAX_CITIES][MAX_CITIES]; // Matrix to store distances between cities
    int numCities; // Number of cities in the graph

    // Constructor to initialize the graph with the given number of cities
    Graph(int n)
    {
        numCities = n;

        // Initialize distances between all cities
        for (int i = 0; i < MAX_CITIES; i++)
        {
            for (int j = 0; j < MAX_CITIES; j++)
            {
                // Set distance to 0 if it's the same city, otherwise set it to infinity
                if (i == j)
                {
                    distances[i][j] = 0;
                }
                else
                {
                    distances[i][j] = INT_MAX;
                }
            }
        }
    }

    // Function to add a distance between two cities to the graph
    void addDistance(int city1, int city2, int distance)
    {
        distances[city1][city2] = distance;
        distances[city2][city1] = distance; // Assuming the graph is undirected, so distances are symmetric
    }

    // Function to get the distance between two cities from the graph
    int getDistance(int city1, int city2)
    {
        return distances[city1][city2];
    }

};
