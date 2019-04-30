#include <iostream>
#include <vector>
#include "Graph.h"

using namespace std;


int main()
{
	Graph g;

	g.addVertex("Boulder");
	g.addVertex("Denver");
	g.addVertex("Cheyenne");
	g.addVertex("Fruita");
	g.addVertex("Moab");
	g.addVertex("Vegas");

	g.addEdge("Boulder","Denver",30);
	g.addEdge("Boulder","Cheyenne",80);
	g.addEdge("Boulder","Fruita",300);
	g.addEdge("Fruita","Denver",310);
	g.addEdge("Cheyenne","Moab",400);
	g.addEdge("Moab","Fruita",20);
	g.addEdge("Vegas","Moab",200);


	//g.displayEdges();

	//	g.breadthFirstTraverse("Fruita");
	//  g.setAllVerticesUnvisited();

	string start, end;
	cout << "Enter a starting city: ";
	cin >> start;

	cout << "\nEnter a destination city: ";
	cin >> end;
	vertex* vEnd = g.dijkstraSearch(start,end);

	if(vEnd!=nullptr){
		cout << "min distance from " << start << " to " << end
			<< " is " << vEnd->distDijk << endl;
	}

    return 0;
}
