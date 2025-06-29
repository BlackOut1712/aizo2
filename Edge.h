#ifndef EDGE_H
#define EDGE_H

#include <iostream>

class Edge {

public:
    Edge(); // Default constructor
    Edge(int source, int destination, int weight);

    int getSource() const ;

    int getDestination() const ;

    int getWeight() const ;

    bool operator==(const Edge& other) const ;

    bool operator<(const Edge& other) const ;

    bool operator>(const Edge& other) const ;

    bool operator<=(const Edge& other) const;

    bool operator>=(const Edge& other) const;

private:
    int source;       // Source vertex of the edge
    int destination;  // Destination vertex of the edge
    int weight;       // Weight of the edge
};

#include "Edge.cpp"

#endif