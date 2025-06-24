#include <iostream>

using namespace std;

class algorithms{
    public:
        algorithms(){}
        ~algorithms(){}

        void BellmanFordAlgorithmList(int** successorsList, int nodeNumber, int edgeNumber) {}

        void BellmanFordAlgorithmMatrix(int** incidenceMatrix, int nodeNumber, int edgeNumber) {}

        void DijkstraAlgorithmList(int** successorsList, int nodeNumber, int edgeNumber) {}

        void DijkstraAlgorithmMatrix(int** incidenceMatrix, int nodeNumber, int edgeNumber) {}

        void KruskalAlgorithmList(int** successorsList, int nodeNumber, int edgeNumber) {}

        void KruskalAlgorithmMatrix(int** incidenceMatrix, int nodeNumber, int edgeNumber) {}

        void PrimsAlgorithmList(int** successorsList, int nodeNumber, int edgeNumber) {}

        void PrimsAlgorithmMatrix(int** incidenceMatrix, int nodeNumber, int edgeNumber) {
            //Starting Node = 0

            
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