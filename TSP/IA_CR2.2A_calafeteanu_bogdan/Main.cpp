#include "TSP.h"

int main() {
    // Define the number of cities
    int numCities = 4;

    // Create a graph with the specified number of cities
    Graph graph(numCities);

    // Create an array to store city information
    City* cities = new City[numCities];

    // Initialize city information
    cities[0] = { "Craiova", 0 };
    cities[1] = { "Bucuresti", 1 };
    cities[2] = { "Sibiu", 2 };
    cities[3] = { "Cluj", 3 };

    // Add distances between cities to the graph
    graph.addDistance(cities[0].getId(), cities[1].getId(), 230); // Distance from Craiova to Bucuresti
    graph.addDistance(cities[0].getId(), cities[2].getId(), 270); // Distance from Craiova to Sibiu
    graph.addDistance(cities[0].getId(), cities[3].getId(), 430); // Distance from Craiova to Cluj
    graph.addDistance(cities[1].getId(), cities[2].getId(), 280); // Distance from Bucuresti to Sibiu
    graph.addDistance(cities[1].getId(), cities[3].getId(), 450); // Distance from Bucuresti to Cluj
    graph.addDistance(cities[2].getId(), cities[3].getId(), 200); // Distance from Sibiu to Cluj

    // Create a TSP object with the graph and city information
    TSP tsp(graph, numCities, cities);

    // Perform depth-first search starting from Craiova
    tsp.depthFirstSearch(cities[0].getId());

    // Perform uniform cost search starting from Craiova
    tsp.uniformCostSearch(cities[0].getId());

    // Perform A* search starting from Craiova
    tsp.aStarSearch(cities[0].getId());

    return 0;
}
