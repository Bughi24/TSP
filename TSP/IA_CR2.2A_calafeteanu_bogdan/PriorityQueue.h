#pragma once
#include "Graph.h"

// Class representing a priority queue
class PriorityQueue {
public:
    // Structure representing a node in the priority queue
    struct Node {
        int path[MAX_CITIES]; // Array to store the path
        int cost;             // Cost associated with the path
        int pathLength;       // Length of the path
    };

    // Constructor
    PriorityQueue() : size(0) {}

    // Function to add a node to the priority queue
    void push(const Node& node) {
        if (size < MAX_SIZE) {
            heap[size] = node;
            int current = size++;
            // Perform heapify-up to maintain the heap property
            while (current > 0 && heap[current].cost < heap[(current - 1) / 2].cost) {
                swap(heap[current], heap[(current - 1) / 2]);
                current = (current - 1) / 2;
            }
        }
    }

    // Function to remove and return the node with the minimum cost from the priority queue
    Node pop() {
        Node minNode = heap[0];
        heap[0] = heap[--size];
        // Perform heapify-down to maintain the heap property
        heapify(0);
        return minNode;
    }

    // Function to check if the priority queue is empty
    bool empty() const {
        return size == 0;
    }

private:
    static const int MAX_SIZE = 1000; // Maximum size of the priority queue
    Node heap[MAX_SIZE];               // Array to store nodes in the priority queue
    int size;                          // Current size of the priority queue

    // Function to heapify the heap at a given index
    void heapify(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        // Find the index of the smallest element among the current node, its left child, and its right child
        if (left < size && heap[left].cost < heap[smallest].cost) {
            smallest = left;
        }

        if (right < size && heap[right].cost < heap[smallest].cost) {
            smallest = right;
        }

        // If the smallest element is not the current node, swap it with the smallest child and heapify-down
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }
};
