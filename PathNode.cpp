#include <iostream>
#include "PathNode.h"

PathNode::PathNode(){
    this->Node = -1;
    this->predecessor = -1;         //as null
    this->pathValue = __INT16_MAX__; //as infinity;
}

PathNode::PathNode(int Node){
    this->Node = Node;
    this->predecessor = -1;         //as null
    this->pathValue = __INT16_MAX__; //as infinity;
}

PathNode::PathNode(int Node, int predecessor, int pathValue){
    this->Node = Node;
    this->predecessor = predecessor;
    this->pathValue = pathValue;
}

int PathNode::getNode(){
    return Node;
}

int PathNode::getPathValue(){
    return pathValue;
}

int PathNode::getPredecessor(){
    return predecessor;
}

void PathNode::setPredecessor(int predecessor){
    this->predecessor = predecessor;
}
    
void PathNode::setPathValue(int pathValue){
    this->pathValue = pathValue;
}

bool PathNode::operator<(const PathNode& other){
    return pathValue<other.pathValue;
}

bool PathNode::operator>(const PathNode& other){
    return pathValue>other.pathValue;
}


bool PathNode::operator>=(const PathNode& other){
    return pathValue>=other.pathValue;
}

bool PathNode::operator<=(const PathNode& other){
    return pathValue<=other.pathValue;
}

bool PathNode::operator==(const PathNode& other){
    return this->Node==other.Node;
}

/*
void PathNode::operator=(const PathNode& other){
    Node = other.Node;
    pathValue = other.pathValue;
    predecessor = predecessor;
}

bool PathNode::operator==(const PathNode& other){
    return pathValue==other.pathValue;
}

bool PathNode::operator!=(const PathNode& other){
    return pathValue!=other.pathValue;
}
*/