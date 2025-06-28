#include <iostream>

class Edge {

public:
    Edge() : source(-1), destination(-1), weight(0) {} // Default constructor
    Edge(int source, int destination, int weight) : source(source), destination(destination), weight(weight) {}

    int getSource() const {
        return source;
    }

    int getDestination() const {
        return destination;
    }

    int getWeight() const {
        return weight;
    }

    bool operator==(const Edge& other) const {
        return this->weight == other.weight;
    }

    bool operator<(const Edge& other) const {
        return this->weight < other.weight;
    }

    bool operator>(const Edge& other) const {
        return this->weight > other.weight;
    }

    bool operator<=(const Edge& other) const {
        return this->weight <= other.weight;
    }

    bool operator>=(const Edge& other) const {
        return this->weight >= other.weight;
    }    

private:
    int source;       // Source vertex of the edge
    int destination;  // Destination vertex of the edge
    int weight;       // Weight of the edge
};