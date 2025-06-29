#include <iostream>
#include "Edge.h"

    Edge::Edge() : source(-1), destination(-1), weight(0) {} // Default constructor
    Edge::Edge(int source, int destination, int weight) : source(source), destination(destination), weight(weight) {}

    int Edge::getSource() const {
        return source;
    }

    int Edge::getDestination() const {
        return destination;
    }

    int Edge::getWeight() const {
        return weight;
    }

    bool Edge::operator==(const Edge& other) const {
        return this->weight == other.weight;
    }

    bool Edge::operator<(const Edge& other) const {
        return this->weight < other.weight;
    }

    bool Edge::operator>(const Edge& other) const {
        return this->weight > other.weight;
    }

    bool Edge::operator<=(const Edge& other) const {
        return this->weight <= other.weight;
    }

    bool Edge::operator>=(const Edge& other) const {
        return this->weight >= other.weight;
    }    
