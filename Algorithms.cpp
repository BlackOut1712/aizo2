#include <iostream>
#include "Edge.cpp"
#include "Successor.h"
#include "ArrayList.h"
#include "PriorityQueue.h"

using namespace std;

class Algorithms{
    public:
        Algorithms(){}
        ~Algorithms(){}

        //static void BellmanFordAlgorithmList(int** successorsList, int nodeNumber, int edgeNumber) {}

        //static void BellmanFordAlgorithmMatrix(int** incidenceMatrix, int nodeNumber, int edgeNumber) {}

        //static void DijkstraAlgorithmList(int** successorsList, int nodeNumber, int edgeNumber) {}

        //static void DijkstraAlgorithmMatrix(int** incidenceMatrix, int nodeNumber, int edgeNumber) {}

        //static void KruskalAlgorithmList(int** successorsList, int nodeNumber, int edgeNumber) {}

        //static void KruskalAlgorithmMatrix(int** incidenceMatrix, int nodeNumber, int edgeNumber) {}

        static ArrayList<Edge> PrimsAlgorithmList(ArrayList<ArrayList<Successor>> successorsList) {
            int Node = 0; // Starting node for Prim's algorithm
            ArrayList<int> visitedNodes; // List of visited nodes
            ArrayList<Edge> MST;
            PriorityQueue<Edge> queue; 

            for(int i = 0; i < successorsList.get(Node).getSize(); i++){
                Successor successor = successorsList.get(Node).get(i);
                Edge edge(Node, successor.getName(), successor.getWeight());
                queue.add(edge); // Add the edge to the priority queue
            }

            visitedNodes.add(Node); // Mark the node as visited

            while(!queue.isEmpty()){

                //queue.print();

                Edge edge = queue.extractMIN(); // Get the minimum edge from the queue
                int destination = edge.getDestination(); // Get the destination of the edge

                // If the destination node has not been visited yet
                if(!visitedNodes.contains(destination)){
                    visitedNodes.add(destination); // Mark the destination node as visited
                    //cout << "Adding edge from " << edge.getSource() << " to " << edge.getDestination() << " with weight " << edge.getWeight() << endl;
                    MST.add(edge); // Add the edge to the Minimum Spanning Tree (MST)

                    // Find all edges from the newly visited node
                    for(int i = 0; i < successorsList.get(destination).getSize(); i++){
                        Successor successor = successorsList.get(destination).get(i);
                        Edge newEdge(destination, successor.getName(), successor.getWeight());
                        queue.add(newEdge); // Add the new edge to the queue
                    }
                }
            }
            return MST; // Return the Minimum Spanning Tree (MST)
        }

        static ArrayList<Edge> PrimsAlgorithmMatrix(int** incidenceMatrix, int nodeNumber, int edgeNumber) {
            
            int Node = 0; // Starting node for Prim's algorithm
            ArrayList<int> visitedNodes; // List of visited nodes
            ArrayList<Edge> MST;
            PriorityQueue<Edge> queue; 

            //Znalezc wszystkie krawedzie wychodzace z wierzcholka
            for(int i = 0; i < edgeNumber; i++){
                if(incidenceMatrix[Node][i]!=0){
                    for(int j = 0; j < nodeNumber; j++){
                        if(incidenceMatrix[j][i] != 0 && j != Node){ // Check if the edge is not self-loop
                            Edge edge(Node, j, abs(incidenceMatrix[Node][i]));
                            queue.add(edge); // Add the edge to the priority queue
                        }
                    }
                }
            }
            visitedNodes.add(Node); // Mark the node as visted

            while(!queue.isEmpty()){
                Edge edge = queue.extractMIN(); // Get the minimum edge from the queue
                int destination = edge.getDestination(); // Get the destination of the edge

                // If the destination node has not been visited yet
                if(!visitedNodes.contains(destination)){
                    visitedNodes.add(destination); // Mark the destination node as visited
                    MST.add(edge); // Add the edge to the Minimum Spanning Tree (MST)

                    // Find all edges from the newly visited node
                    for(int i = 0; i < edgeNumber; i++){
                        if(incidenceMatrix[destination][i] != 0){
                            for(int j = 0; j < nodeNumber; j++){
                                if(incidenceMatrix[j][i] != 0 && j != destination){ // Check if the edge is not self-loop
                                    Edge newEdge(destination, j, abs(incidenceMatrix[destination][i]));
                                    queue.add(newEdge); // Add the new edge to the queue
                                }
                            }
                        }
                    }
                }
            }
            return MST;
        }

    private:
        int startNode = -1; // Initialize startNode to -1 to indicate it hasn't been set yet
        int endNode = -1; // Initialize endNode to -1 to indicate it hasn't been set yet

        void askForStartingNode(int nodeNumber) {
            cout<< "Insert a starting node (0 to " << nodeNumber - 1 << "): ";
            try{
            cin >> this->startNode;
            }catch (const std::exception& e) {
                cout << "Invalid input." << endl;
            }
        }

        void askForEndNode(int nodeNumber) {
            cout<< "Insert a end node (0 to " << nodeNumber - 1 << "): ";
            try{
            cin >> this->endNode;
            }catch (const std::exception& e) {
                cout << "Invalid input." << endl;
            }
        }
};