#include <iostream>
#include "Timer.h"
#include "FileControl.cpp"
#include "Algorithms.cpp"

int main() {
    FileControl filecontrol;
    Graf graf;
    graf.setDirected(false);

    filecontrol.readFile("test.txt", graf);
    graf.printIncidenceMatrix();
    
    auto successorsList = graf.getSuccessorsList();
    for(int i = 0; i < graf.getNodeNumber(); i++) {
        std::cout << "Successors of node " << i << ": ";
        for(int j = 0; j < successorsList.get(i).getSize(); j++) {
            Successor successor = successorsList.get(i).get(j);
            std::cout << "(" << successor.getName() << ", " << successor.getWeight() << ") ";
        }
        std::cout << std::endl;
    }
 
    auto MST = Algorithms::PrimsAlgorithmMatrix(graf.getIncidenceMatrix(), graf.getNodeNumber(), graf.getEdgeNumber());
    std::cout << "Minimum Spanning Tree (MST) edges:" << std::endl;
    for(int i = 0; i < MST.getSize(); i++) {
        Edge edge = MST.get(i);
        std::cout << "Edge from " << edge.getSource() << " to " << edge.getDestination() << " with weight " << edge.getWeight() << std::endl;
    }

    std::cout << "Now using the list representation of the graph:" << std::endl;

    auto MST2 = Algorithms::PrimsAlgorithmList(graf.getSuccessorsList());
    std::cout << "Minimum Spanning Tree (MST) edges:" << std::endl;
    for(int i = 0; i < MST2.getSize(); i++) {
        Edge edge = MST2.get(i);
        std::cout << "List: Edge from " << edge.getSource() << " to " << edge.getDestination() << " with weight " << edge.getWeight() << std::endl;
    }


    return 0;
}