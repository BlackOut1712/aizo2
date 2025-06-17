#include <iostream>
#include <string>
#include <fstream>
#include "Graf.h"

using namespace std;

class FileControl{
    private:
    char readBuffer[50];
    
    public:
    FileControl();

    void readFile(const string filename){
        /* This function reads data from a file and processes it */
        
        fstream file;
        file.open(filename, ios::in);
        if(!file) {
            cout << "File not found." << endl;
            return;
        }

        file.getline(readBuffer, sizeof(readBuffer), '\t');
        int nodeNumber = stoi(readBuffer);

        file.getline(readBuffer, sizeof(readBuffer), '\n');
        int edgeNumber = stoi(readBuffer);

        int SourceNode, DestinationNode, Weight;

        while(!file.eof()){
            file.getline(readBuffer, sizeof(readBuffer), '\t');
            SourceNode = stoi(readBuffer);

            file.getline(readBuffer, sizeof(readBuffer), '\t');
            DestinationNode = stoi(readBuffer);

            file.getline(readBuffer, sizeof(readBuffer), '\n');
            Weight = stoi(readBuffer);

            //Create the edge
            //Graf::addEdge(SourceNode, DestinationNode, Weight);
            //Rownolegle dodawac do macierzy i listy nastepnikow???
        }

        file.close();
    }
};