#include <iostream>
#include "Timer.h"
#include "FileControl.cpp"


int main() {
    FileControl filecontrol;
    Graf graf;
    filecontrol.readFile("test.txt", graf);
    graf.printIncidenceMatrix();
}