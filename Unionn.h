#ifndef UNIONN_H
#define UNIONN_H

#include <iostream>
#include "ArrayList.h"

class Unionn {
public:
    Unionn(int NodeNumber);
    ~Unionn();

    int getNodeNumber() const;
    int getUnionId() const;
    void unite(Unionn& other);
    void unite(ArrayList<Unionn>& unions);

private:
    static int unionCounter;
    int nodeNumber;
    int unionId;
};

#endif
