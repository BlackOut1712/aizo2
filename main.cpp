#include <iostream>
#include "Timer.h"
#include "FileControl.cpp"
#include "Algorithms.cpp"
#include <cstring>
#include <string>

int main(int argc, char* argv[]) {
    srand(0);
    if(argc < 2 || strcmp(argv[1], "--help") == 0) {
        std::cout << "FILE TEST MODE:\nUsage:\n   ./aizo --file <problem> <algorithm> <inputFile> [outputFile]\n<problem> Problem to solve (0 - MST, 1 - shortest path)\n<algorithm> Algorithm for the problem\n     For MST (0 - all, 1 - Prims)\n     For shortest (0 - all, 1 - Dijkstra, ...)\n<inputFile> Input file containing the graf.\n[outputFile] If provided, solved problem will be stored there.\nBENCHMARK MODE:\nUsage:\n   ./aizo --test <problem> <algorithm> <size> <density>\n<outputFile>\n<problem> Problem to solve (0 - MST, 1 - shortest path)\n<algorithm> Algorithm for the problem\n     For MST (0 - all, 1 - Prims, ...)\n     For shortest (0 - all, 1 - Dijkstra, ...)\n<size> Number of nodes.\n<density> Density of edges. (from 0 to 1)\n<outputFile> File where the benchmark results should be saved\n(every measured time is stored in seperate line).\nHELP MODE:\nUsage:\n   ./YourProject --help\nDisplays this help message.\nNotes:\n- The help message will also appear if no arguments are provided.\n- Ensure that either --file or --test mode is specified;\nthey are mutually exclusive.";
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
                std::cout<<"Algorytm Prima z uzyciem macierzy: "<< matrixTime<< " us. \n";
                //OUTPUT FILE!~!!

                timer.reset();
                timer.start();
                Algorithms::PrimsAlgorithmList(graf.getSuccessorsList());
                timer.stop();
                int listTime = timer.result();
                std::cout<<"Algorytm Prima z uzyciem listy nastepnikow: "<< listTime << " us. \n";
                //OUTPUTFILE!!!!!!!
            }
        }
        
        else if(problem == 1){
            std::string filename(argv[4]);
            filecontrol.readFile(filename, graf);
            if(algorithm == 1 || algorithm == 0){
                int startNode = Algorithms::askForStartingNode(graf.getNodeNumber());
                int endNode = Algorithms::askForEndNode(graf.getNodeNumber());

                timer.start();
                auto solution = Algorithms::DijkstraAlgorithmMatrix(graf.getIncidenceMatrix(), graf.getNodeNumber(), graf.getEdgeNumber(), startNode, endNode);
                timer.stop();
                int MatrixTime = timer.result();
                std::cout<<"Algorytm Dijkstry z uzyciem macierzy: "<<MatrixTime << "us. \n";

                for(int i=0; i<solution.getSize(); i++){
                    std::cout << "From " << solution.get(i).getSource() << " to " << solution.get(i).getDestination() << " with weight " << solution.get(i).getWeight() << std::endl;
                }
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
        double density = atof(argv[5]);
        if(density == 0){
            std::cout<<"Gestosc nie moze byc = 0";
            return -1;
        }

        if(problem == 0){
            graf.setDirected(false);
            graf.generateGraf(size, density);
            
            if(algorithm == 1 || algorithm == 0){
            timer.reset();
            timer.start();
            auto x =Algorithms::PrimsAlgorithmMatrix(graf.getIncidenceMatrix(), graf.getNodeNumber(), graf.getEdgeNumber());
            timer.stop();
            int matrixTime = timer.result();
            filecontrol.raport("PrimMatrix.txt", graf.getNodeNumber(), density, matrixTime);
            //std::cout<<"Algorytm Prima z uzyciem macierzy: " << matrixTime << " us\n";
            
            timer.reset();
            timer.start();
            auto y =Algorithms::PrimsAlgorithmList(graf.getSuccessorsList());
            timer.stop();
            int listTime = timer.result();

            filecontrol.raport("PrimList.txt", graf.getNodeNumber(), density, listTime);
            //std::cout<<"Algorytm Prima z uzyciem listy nastepnikow: " << listTime << " us\n";
            }
        }

        else if(problem == 1){
            graf.generateGraf(size, density);
            if(algorithm == 1 || algorithm == 0){
                int startNode = Algorithms::askForStartingNode(graf.getNodeNumber());
                int endNode = Algorithms::askForEndNode(graf.getNodeNumber());

                //graf.printIncidenceMatrix();
                timer.start();
                auto solution = Algorithms::DijkstraAlgorithmMatrix(graf.getIncidenceMatrix(), graf.getNodeNumber(), graf.getEdgeNumber(), startNode, endNode);
                timer.stop();
                int MatrixTime = timer.result();
                std::cout<<"Algorytm Dijkstry z uzyciem macierzy: "<<MatrixTime << "us. \n";

                
                for(int i=0; i<solution.getSize(); i++){
                    std::cout << "From " << solution.get(i).getSource() << " to " << solution.get(i).getDestination() << " with weight " << solution.get(i).getWeight() << std::endl;
                }
                
            }
        }

    }
    
    return 0;
}