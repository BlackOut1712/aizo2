#include <iostream>
#include "Edge.cpp"
#include "Successor.h"
#include "ArrayList.h"
#include "PriorityQueue.h"
#include "Unionn.h"
#include "PathNode.h"

using namespace std;

class Algorithms{
    public:
        Algorithms(){}
        ~Algorithms(){}

        //static void BellmanFordAlgorithmList(int** successorsList, int nodeNumber, int edgeNumber) {}

        //static void BellmanFordAlgorithmMatrix(int** incidenceMatrix, int nodeNumber, int edgeNumber) {}

        //static void DijkstraAlgorithmList(int** successorsList, int nodeNumber, int edgeNumber) {}

        static ArrayList<Edge> DijkstraAlgorithmMatrix(int** incidenceMatrix, int nodeNumber, int edgeNumber, int startNode, int endNode) {

            //Edge List - lista krawedzi
            ArrayList<Edge> EdgeList;

            //S -  zbiór zawierający poprzednikow i wagi najkrótszych ścieżek ze źródła do wierzchołków 
            ArrayList<PathNode> S;

            //Q - kolejka priorytetowa pathNodes (klucz - ścieżka)
            PriorityQueue<PathNode> queue;


            //Initialize-Single-Source
            for(int i=0; i<nodeNumber; i++){
                PathNode Node(i);
                if(i==startNode){
                    Node.setPathValue(0);
                    Node.setPredecessor(i);
                }
                queue.add(Node);
                S.add(Node);
            }

            while(!queue.isEmpty()){
                PathNode u = queue.extractMIN();
                S.set(u.getNode(), u);
                ArrayList<Edge> edges;

                //Looking for all edges leaving this node.
                for(int i=0; i<edgeNumber; i++){
                    if(incidenceMatrix[u.getNode()][i]<0){
                        for(int j=0; j<nodeNumber; j++){
                            if(incidenceMatrix[j][i]>0){
                                Edge edge(u.getNode(), j, incidenceMatrix[j][i]);
                                //std::cout << "Edge from " << u.getNode() << " to " << j << " with weight " << incidenceMatrix[j][i] << std::endl;
                                edges.add(edge);
                            }
                        }
                    }
                }

                //add to EdgeList
                for(int i=0; i<edges.getSize(); i++){
                    EdgeList.add(edges.get(i));
                }

                //std::cout<<"Usuwam wierzcholek " << u.getNode() << std::endl;

                //Relax
                for(int i=0; i<edges.getSize(); i++){
                    //if new path is smaller than an old path
                    int newPath = S.get(u.getNode()).getPathValue()+edges.get(i).getWeight();
                    //std::cout << S.get(u.getNode()).getPathValue()  << " + " << edges.get(i).getWeight() << " = " << newPath << std::endl;
                    int oldPath =  S.get(edges.get(i).getDestination()).getPathValue();
                    if(newPath < oldPath){
                        //std::cout << "Wierzcholek " << edges.get(i).getDestination() << " poprzednik: " << u.getNode();
                        PathNode updatedNode(edges.get(i).getDestination(), u.getNode(), newPath);
                        S.set(edges.get(i).getDestination(), updatedNode);
                        int index = queue.getIndex(updatedNode);
                        if(index>=0){
                            queue.update(index, updatedNode);

                        }
                    }
                }
            }

            //Scieżka jako Lista Krawędzi:
            ArrayList<Edge> Path;
            int i = endNode;
            while(S.get(i).getNode()!=startNode){
                PriorityQueue<Edge> possibilities; //In case there are multiple edges from the same source to the same destination
                int current = S.get(i).getNode();
                int previous = S.get(i).getPredecessor();
                for(int j=0; j<EdgeList.getSize(); j++){
                    if(EdgeList.get(j).getSource() == previous && EdgeList.get(j).getDestination() == current){
                        possibilities.add(EdgeList.get(j));                        
                    }
                }
                
                if(!possibilities.isEmpty()){
                    Path.add(possibilities.extractMIN());
                }

                i = previous;
            }

            //Reverse
            int PathSize = Path.getSize();
            for(int j=0; j<PathSize/2; j++){
                Edge temp = Path.get(j);
                Path.set(j, Path.get(PathSize-1-j));
                Path.set(PathSize-1-j, temp);
            }
                        
            return Path;

        }

        //static void KruskalAlgorithmList(int** successorsList, int nodeNumber, int edgeNumber) {}

        /*
        static ArrayList<Edge> KruskalAlgorithmMatrix(int** incidenceMatrix, int nodeNumber, int edgeNumber) {
            ArrayList<Edge> MST; // Minimum Spanning Tree
            PriorityQueue<Edge> queue; // Priority queue to hold edges

            // Add all edges to the priority queue
            for(int i = 0; i < edgeNumber; i++){
                for(int j = 0; j < nodeNumber; j++){
                    if(incidenceMatrix[j][i] != 0){ // Check if the edge exists
                        Edge edge(j, i, abs(incidenceMatrix[j][i]));
                        queue.add(edge); // Add the edge to the priority queue
                    }
                }
            }    
            
            ArrayList<ArrayList<Unionn>> unions; // List of unions
            for(int i = 0; i < nodeNumber; i++){
                ArrayList<Unionn> unionX; // Create a new union for each node
                Unionn newUnion(i); // Create a new union with the node number
                unionX.add(newUnion); // Add the new union to the list of unions
                unions.add(unionX); // Add the union to the list of unions
            }
            
            while(MST.getSize() < nodeNumber - 1 && !queue.isEmpty()) {
                Edge edge = queue.extractMIN(); // Get the minimum edge from the queue
                int source = edge.getSource(); // Get the source of the edge
                int destination = edge.getDestination(); // Get the destination of the edge

                
            }

        
        }
        */
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

        static int askForStartingNode(int nodeNumber) {
            cout<< "Insert a starting node (0 to " << nodeNumber - 1 << "): ";
            int startNode;
            try{
            cin >> startNode;
            }catch (const std::exception& e) {
                cout << "Invalid input." << endl;
                return -1;
            }
            return startNode;
        }

        static int askForEndNode(int nodeNumber) {
            cout<< "Insert a end node (0 to " << nodeNumber - 1 << "): ";
            int endNode;
            try{
            cin >> endNode;
            }catch (const std::exception& e) {
                cout << "Invalid input." << endl;
                return -1;
            }
            return endNode;
        }
};