#include <iostream>
#include <string>
#include <fstream>
#include "Graf.cpp"

using namespace std;

class FileControl{
    private:
    char readBuffer[50];
    
    public:
    FileControl(){};

    void raport(const string filename, int NodesNumber, double density, int time){
        fstream file;
        file.open(filename, ios::out | ios::app);
        if(!file){
            std::cout<<"Report file not found." << std::endl;
            return;
        }

        file << NodesNumber << ";" << density << ";" << time << "\n";
        file.close();
    }

    void readFile(const string filename, Graf& graf){
        /* This function reads data from a file and processes it */
        
        fstream file;
        file.open(filename, ios::in);
        if(!file) {
            cout << "File not found." << endl;
            return;
        }

        file.getline(readBuffer, sizeof(readBuffer), '\t');
        int edgeNumber = stoi(readBuffer);

        file.getline(readBuffer, sizeof(readBuffer), '\n');
        int nodeNumber = stoi(readBuffer);

        //cout << "Node Number: " << nodeNumber << ", Edge Number: " << edgeNumber << endl;
        graf.initiate(nodeNumber, edgeNumber);

        int SourceNode, DestinationNode, Weight;

        while(!file.eof()){
            file.getline(readBuffer, sizeof(readBuffer), '\t');
            SourceNode = stoi(readBuffer);

            file.getline(readBuffer, sizeof(readBuffer), '\t');
            DestinationNode = stoi(readBuffer);

            file.getline(readBuffer, sizeof(readBuffer), '\n');
            Weight = stoi(readBuffer);

            //cout << "Source: " << SourceNode << ", Destination: " << DestinationNode << ", Weight: " << Weight << endl;
            //Create the edge
            graf.addEdge(SourceNode, DestinationNode, Weight);
            //Rownolegle dodawac do macierzy i listy nastepnikow???
        }

        file.close();
    }
};