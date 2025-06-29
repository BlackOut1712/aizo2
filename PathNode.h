#ifndef PATHNODE_H
#define PATHNODE_H

class PathNode{
    public:
    PathNode();
    PathNode(int Node);
    PathNode(int Node, int predecessor, int pathValue);
    
    int getNode();
    int getPathValue();
    int getPredecessor();
    void setPredecessor(int predecessor);
    void setPathValue(int pathValue);
    void update();

    bool operator<(const PathNode& other);
    bool operator>(const PathNode& other);
    bool operator>=(const PathNode& other);
    bool operator<=(const PathNode& other);
    //void operator=(const PathNode& other);

    //bool operator!=(const PathNode& other);
    bool operator==(const PathNode& other);

    private:
        int Node;
        int predecessor;
        int pathValue;
};

#include "PathNode.cpp"
#endif