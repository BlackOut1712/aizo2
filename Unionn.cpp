#include <iostream>

#include "Unionn.h"

int Unionn::unionCounter = 0;

Unionn::Unionn(int NodeNumber) {
    this->nodeNumber = NodeNumber;
    this->unionId = unionCounter++;
}

int Unionn::getNodeNumber() const {
    return this->nodeNumber;
}

int Unionn::getUnionId() const {
    return this->unionId;
}

void Unionn::unite(Unionn& other) {
    if (this->unionId != other.unionId) {
        // Merge the two unions by updating the union ID of the other union
        other.unionId = this->unionId;
    }
}

void Unionn::unite(ArrayList<Unionn>& unions) {
    for (int i = 0; i < unions.getSize(); ++i) {
        unite(unions.get(i));
    }
}