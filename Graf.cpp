#include <iostream>
#include "Successor.h"
#include "ArrayList.h"
class Graf{
    public:
    Graf() : edgeNumber(0), incidenceMatrix(nullptr), nodeNumber(0) {}
    ~Graf() {
        for (int i = 0; i < this->nodeNumber; ++i) {
            delete[] this->incidenceMatrix[i];
        }
        delete[] this->incidenceMatrix;

    }

    void addEdge(int source, int destination, int weight) {
        if(source < 0 || source >= this->nodeNumber || destination < 0 || destination >= this->nodeNumber || this->incidenceMatrix == nullptr) {
            std::cout << "Invalid edge or incidence matrix not initialized." << std::endl;
            return;
        }
        if(this->i >= this->edgeNumber) {
            std::cout << "Edge index exceeds the number of edges." << std::endl;
            return;
        }

        // For directed graphs
        if(this->isDirected){
            //For matrix
            this->incidenceMatrix[source][this->i] = (-1)*weight;
            this->incidenceMatrix[destination][this->i] = weight; 
            
            // For successors list
            Successor successor(destination, weight);
            if(!this->successorsList.get(source).contains(successor)){
                this->successorsList.get(source).add(successor);
            }
        }

        // For undirected graphs
        else{
            this->incidenceMatrix[source][this->i] = weight;
            this->incidenceMatrix[destination][this->i] = weight;
            
            // For successors list
            Successor successor(destination, weight);
            Successor successorReverse(source, weight);

            if(!this->successorsList.get(source).contains(successor)){
                this->successorsList.get(source).add(successor);
            }
            if(!this->successorsList.get(destination).contains(successorReverse)){
                this->successorsList.get(destination).add(successorReverse);
            }
        }


        this->i++;
    }

    int getEdgeNumber() const {
        return this->edgeNumber;
    }    

    int** getIncidenceMatrix() {
        if (this->incidenceMatrix == nullptr) {
            std::cout << "Incidence matrix is not initialized. Please initiate the graph first." << std::endl;
            return nullptr;
        }
        return this->incidenceMatrix;
    }

    int getNodeNumber() const {
        return this->nodeNumber;
    }

    ArrayList<ArrayList<Successor>> getSuccessorsList() {
        return this->successorsList;
    }

    void initiate(int nodeNumber, int edgeNumber) {
        setNodeNumber(nodeNumber);
        setEdgeNumber(edgeNumber);
        createIncidenceMatrix();
        createSuccessorsList();
    }

    void printIncidenceMatrix() {
        if (this->incidenceMatrix == nullptr) {
        std::cout << "Incidence matrix is not initialized." << std::endl;
        return;
        }
        
        std::cout << "Incidence Matrix:" << std::endl;
        for (int i = 0; i < this->nodeNumber; ++i) {
            for (int j = 0; j < this->edgeNumber; ++j) {
                std::cout << this->incidenceMatrix[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }

    void setDirected(bool isDirected) {
        this->isDirected = isDirected;
    }

    private:
    int edgeNumber; // Number of edges
    int i=0; // Edge index for adding edges
    int** incidenceMatrix; // Incidence matrix
    bool isDirected = true; // Default to directed graph 
    int nodeNumber; // Number of nodes
    ArrayList<ArrayList<Successor>> successorsList; // List of successors


    void createIncidenceMatrix() {
        this->incidenceMatrix = new int*[this->nodeNumber];
        for (int i = 0; i < this->nodeNumber; ++i) {
            this->incidenceMatrix[i] = new int[this->edgeNumber];
            for(int j = 0; j < this->edgeNumber; ++j) {
                this->incidenceMatrix[i][j] = 0; 
            }    
        }
    }

    void createSuccessorsList() {
        if(!successorsList.isEmpty()){
            std::cout << "Successors list is already created." << std::endl;
            return;
        }
        for(int i=0; i < this->nodeNumber; i++) {
            ArrayList<Successor> successors;
            this->successorsList.add(successors);
        }
    }

    void setEdgeNumber(int edgeNumber) {
        this->edgeNumber = edgeNumber;
    }

    void setNodeNumber(int nodeNumber) {
        this->nodeNumber = nodeNumber;
    }
};
