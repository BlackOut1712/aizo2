#include <iostream>
class Graf{
    public:
    Graf() : edgeNumber(0), nodeNumber(0), incidenceMatrix(nullptr), successorsList(nullptr), predecessorsList(nullptr) {}
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

        if(this->isDirected){
            // For directed graphs
            this->incidenceMatrix[source][this->i] = (-1)*weight;
            this->incidenceMatrix[destination][this->i] = weight;
        }
        else{
            // For undirected graphs
            this->incidenceMatrix[source][this->i] = weight;
            this->incidenceMatrix[destination][this->i] = weight;
        }
        this->i++;
    }

    int** getIncidenceMatrix() {
        if (this->incidenceMatrix == nullptr) {
            std::cout << "Incidence matrix is not initialized. Please initiate the graph first." << std::endl;
            return nullptr;
        }
        return this->incidenceMatrix;
    }

    void initiate(int nodeNumber, int edgeNumber) {
        setNodeNumber(nodeNumber);
        setEdgeNumber(edgeNumber);
        createIncidenceMatrix();
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

    private:
    int edgeNumber; // Number of edges
    int i=0; // Edge index for adding edges
    int** incidenceMatrix; // Incidence matrix
    bool isDirected = true; // Default to directed graph 
    int nodeNumber; // Number of nodes
    int** predecessorsList; // List of predecessors
    int** successorsList; // List of successors


    void createIncidenceMatrix() {
        this->incidenceMatrix = new int*[this->nodeNumber];
        for (int i = 0; i < this->nodeNumber; ++i) {
            this->incidenceMatrix[i] = new int[this->edgeNumber];
            for(int j = 0; j < this->edgeNumber; ++j) {
                this->incidenceMatrix[i][j] = 0; 
            }    
        }
    }

    void createPredecessorsList() {
        if(!isDirected) {
            this->predecessorsList = this->successorsList;
            return;
        }       

        //blablabla
    }

    void createSuccessorsList() {
        if(successorsList = nullptr){
            std::cout << "Successors list is already created." << std::endl;
            return;
        }
        this->successorsList = new int*[this->nodeNumber];

    }

    void setEdgeNumber(int edgeNumber) {
        this->edgeNumber = edgeNumber;
    }

    void setNodeNumber(int nodeNumber) {
        this->nodeNumber = nodeNumber;
    }
};
