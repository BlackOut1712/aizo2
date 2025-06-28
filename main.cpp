#include <iostream>
#include "Timer.h"
#include "FileControl.cpp"
#include "Algorithms.cpp"
#include <cstring>
#include <string>

int main(int argc, char* argv[]) {
    
    if(argc < 2 || strcmp(argv[1], "--help") == 0) {
        std::cout << "FILE TEST MODE:\nUsage:\n   ./aizo --file <problem> <algorithm> <inputFile> [outputFile]\n<problem> Problem to solve (0 - MST, 1 - shortest path)\n<algorithm> Algorithm for the problem\n     For MST (0 - all, 1 - Prims)\n     For shortest (0 - all, 1 - Dijkstra, ...)\n<inputFile> Input file containing the graf.\n[outputFile] If provided, solved problem will be stored there.\nBENCHMARK MODE:\nUsage:\n   ./aizo --test <problem> <algorithm> <size> <density>\n<outputFile>\n<problem> Problem to solve (0 - MST, 1 - shortest path)\n<algorithm> Algorithm for the problem\n     For MST (0 - all, 1 - Prims, ...)\n     For shortest (0 - all, 1 - Dijkstra, ...)\n<size> Number of nodes.\n<density> Density of edges.\n<outputFile> File where the benchmark results should be saved\n(every measured time is stored in seperate line).\nHELP MODE:\nUsage:\n   ./YourProject --help\nDisplays this help message.\nNotes:\n- The help message will also appear if no arguments are provided.\n- Ensure that either --file or --test mode is specified;\nthey are mutually exclusive.";
        return -1;
    }
    
    else if((argc == 5 || argc == 6) && strcmp(argv[1],"--file")==0){
        Timer timer;
        FileControl filecontrol;
        Graf graf;
        int problem = atoi(argv[2]);
        int algorithm = atoi(argv[3]);
        if(problem==0){
            graf.setDirected(false);
            std::string filename(argv[4]);
            filecontrol.readFile(filename, graf);

            if(algorithm == 1 || algorithm == 0){
                timer.start();
                Algorithms::PrimsAlgorithmMatrix(graf.getIncidenceMatrix(),graf.getNodeNumber(), graf.getEdgeNumber());
                timer.stop();
                int matrixTime = timer.result();
                std::cout<<"Algorytm Prima z uzyciem macierzy: "<< matrixTime<< " ms. \n";
                //OUTPUT FILE!~!!

                timer.reset();
                timer.start();
                Algorithms::PrimsAlgorithmList(graf.getSuccessorsList());
                timer.stop();
                int listTime = timer.result();
                std::cout<<"Algorytm Prima z uzyciem listy nastepnikow: "<< listTime << " ms. \n";
                //OUTPUTFILE!!!!!!!
            }
        }
        
        else if(problem == 1){
            std::string filename(argv[4]);
            filecontrol.readFile(filename, graf);
            if(algorithm == 1 || algorithm == 0){
                std::cout<<"Do implementacji";
            }
        }
    }
//    ./aizo --test <problem> <algorithm> <size> <density>
    
    else if(argc == 6 && strcmp(argv[1],"--test")==0){
        Timer timer;
        FileControl filecontrol;
        Graf graf;

        int problem = atoi(argv[2]);
        int algorithm = atoi(argv[3]);
        int size = atoi(argv[4]);
        double density = atof(argv[5])/100;
        if(density == 0){
            std::cout<<"Gestosc nie moze byc = 0";
            return -1;
        }

        if(problem == 0){
            graf.setDirected(false);
            graf.generateGraf(size, density);
            
            timer.reset();
            timer.start();
            auto x =Algorithms::PrimsAlgorithmMatrix(graf.getIncidenceMatrix(), graf.getNodeNumber(), graf.getEdgeNumber());
            timer.stop();
            int matrixTime = timer.result();

            std::cout<<"Algorytm Prima z uzyciem macierzy: " << matrixTime << " us\n";
            
            timer.reset();
            timer.start();
            auto y =Algorithms::PrimsAlgorithmList(graf.getSuccessorsList());
            timer.stop();
            int listTime = timer.result();

            std::cout<<"Algorytm Prima z uzyciem listy nastepnikow: " << listTime << " us\n";
            
            if(x == y){
                std::cout<<"To samo \n";
                return 0;
            }
            std::cout<<"Nie to samo?";
            return -1;

        }

    }
    
    
    
    
    
    /*
    
    
    
    
    FileControl filecontrol;
    Graf graf;
    

    //filecontrol.readFile("test.txt", graf);
    graf.setDirected(false);
    graf.generateGraf(10, 0.9); // Generate a graph with 5 nodes and 50% density
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
*/

    return 0;
}