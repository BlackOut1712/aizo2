#ifndef Graf_h
#define Graf_h

#include <iostream>

class Graf{
    public:
        Graf();
        ~Graf();

        void addEdge(int source, int destination, int weight);
        void initiate(int nodeNumber, int edgeNumber);
        void printIncidenceMatrix();

    private:
        int edgeNumber; // Liczba krawędzi
        int i=0; // Indeks krawędzi
        int** incidenceMatrix; // Macierz incydencji
        bool isDirected = true; // Czy graf jest skierowany
        int nodeNumber; // Liczba wierzchołków
        int** predecessorsList; // Lista poprzedników
        int** successorsList; // Lista następników

        void createIncidenceMatrix();
        void createPredecessorsList();
        void createSuccessorsList();
        void setEdgeNumber(int edgeNumber);
        void setNodeNumber(int nodeNumber);
};

#endif