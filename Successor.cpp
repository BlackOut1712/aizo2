#include <iostream>
#include <compare>
#include "Successor.h"

    Successor::Successor() {
        this->weight = -1; // Default weight is -1
        this->name = -1; // Default name is -1
    }

    Successor::Successor(int name, int weight) {
        this->name = name;
        this->weight = weight;
    }
    
    int Successor::getWeight(){
        return weight;
    }

    int Successor::getName(){
        return name;
    }

    bool Successor::operator==(const Successor& other) const {
        return this->weight == other.weight && this->name == other.name;
    }


