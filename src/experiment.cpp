#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include "bst.hh"
#include "vector.hh"

using namespace std;

int main() {

    double totalLeafs = 0, totalLevels = 0, nodesLeft = 0, nodesRight = 0; 
    unsigned int reps = 100;

    srand(static_cast<unsigned int>(time(0)));
  
    Vector<unsigned int> elements;
    BST<unsigned int> arbol;

    for (unsigned int i = 0; i < 100000; i++) {
        elements.push_back(i);
    }

    while(elements.getSize() > 0){
        unsigned int index = rand() % elements.getSize();
        unsigned int random = elements.at(index);

        arbol.insert(random);
        elements.remove(index);
    }
        
    totalLeafs += arbol.get_leafs();
    totalLevels += arbol.get_height();
    nodesLeft += arbol.get_left_nodes();
    nodesRight += arbol.get_right_nodes();

    cout << "Average leafs: " << totalLeafs << endl; 
    cout << "Average levels: " << totalLevels << endl;
    cout << "Average nodes to left: " << nodesLeft << endl;
    cout << "Average nodes to right: " << nodesRight << endl;

    return 0;
}
