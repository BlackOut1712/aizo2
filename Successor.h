#ifndef SUCCESSOR_H
#define SUCCESSOR_H

class Successor {
    public:
        Successor();
        Successor(int name, int weight);
        int getWeight();
        int getName();
        bool operator==(const Successor& other) const;


    private:
        int weight = -1; // Default weight is -1
        int name = -1; // Default name is -1
};

#include "Successor.cpp"
#endif