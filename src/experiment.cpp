#include <iostream>
#include <fstream>
#include <random>
#include "bst.hh"
#include "vector.hh"

using namespace std;

void characteristics(BST<string> arbol){
    //arbol.print();
    //cout << "Tree size: " << arbol.get_size() << endl;
    cout << "Leafs: " << arbol.get_leafs() << endl;
    cout << "Levels: " << arbol.get_height() << endl; 
    cout << "Number nodes to left: " << arbol.get_left_nodes() << endl;
    cout << "Number nodes to right: " << arbol.get_right_nodes() << endl;
}

int main() {

    double totalLeafs = 0, totalLevels = 0, nodesLeft = 0, nodesRight = 0; 
    unsigned int reps = 1000;


    for(unsigned int i = 0; i<reps; i++){
        
        Vector<string> animals;
        BST<string> arbol;
        ifstream file("data.csv");
        string line;
        random_device rd;

        mt19937 gen(rd());

        if (!file.is_open()) {
            cout << "Error al abrir el archivo." << endl;
            return 0;
        }

        while (getline(file, line)) {
            animals.push_back(line);
        }

        animals.QuickSort();
        
        while ( animals.getSize()!=0) {
            uniform_int_distribution<> distrib(0, animals.getSize() - 1);
            unsigned int randomz = distrib(gen);
            arbol.insert(animals.at(randomz));
            animals.remove(randomz);
        }

            totalLeafs += arbol.get_leafs();
            totalLevels += arbol.get_height();
            nodesLeft += arbol.get_left_nodes();
            nodesRight += arbol.get_right_nodes();

            characteristics(arbol);
            cout << endl;
    }

    cout << "Average leafs: " << totalLeafs/reps << endl; 
    cout << "Average levels: " << totalLevels/reps << endl;
    cout << "Average nodes to left: " << nodesLeft/reps << endl;
    cout << "Average nodes to right: " << nodesRight/reps << endl;

    return 0;
}
