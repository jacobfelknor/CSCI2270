#include <iostream>
using namespace std;

#include "graphs.hpp"


int main(){

	Graph g0;

	g0.addVertex(4);
	g0.addVertex(23);

	g0.addEdge(4,23);


	//g0.displayEdges();
	//g0.printDFT();
	g0.printBFT();


	return 0;
}