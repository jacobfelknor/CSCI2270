// comment
#include "Graph.h"
#include <vector>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;


void Graph::addEdge(string v1, string v2, int weight){
	for(int i = 0; i < vertices.size();i++){
		if(vertices[i].name==v1){
			for( int j = 0; j < vertices.size(); j++){
				if(vertices[j].name == v2 && i!=j){
					adjVertex av;
					av.v = &vertices[j];
					av.weight = weight;
					vertices[i].adj.push_back(av);
					// add another vertex in the other direction
					adjVertex av2;
					av2.v = &vertices[i];
					av2.weight = weight;
					vertices[j].adj.push_back(av2);
				}
			}
		}
	}

}
void Graph::addVertex(string n){
	bool found = false;

	for(int i = 0; i<vertices.size(); i++){
		if(vertices[i].name == n){
			found = true;
			cout << vertices[i].name << " already exists" << endl;
		}
	}

		if(!found){
			vertex v;
			v.name = n;
			v.distance = 0;
			v.visited = false;
			v.solved = false;
			v.distDijk = 0;
			vertices.push_back(v);
		}

}

void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<" --> ";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout << vertices[i].adj[j].v->name << " ";
        }
        cout<<endl;
    }

}

void Graph::breadthFirstTraverse(string sourceVertex){
	// Since we don't have a search function, implement
	// here to find the starting vertex

	// need a pointer to keep track of starting vertex

	vertex *vStart = search(sourceVertex);

	cout << "starting vertex (root): " << vStart->name << "-> ";

	vStart->visited = true;

	// Use the STL queue to keep track of vertices to be
	// visited

	queue<vertex*> q;

	// Enqueue the starting vertex
	q.push(vStart);

	// Need another vertex pointer 
	vertex *n;


	while(!q.empty()){
		// q dequeue
		n = q.front(); // like a peek
		q.pop();

		for(int x = 0; x < n->adj.size(); x++){
			//check if vertex visited
			if(!n->adj[x].v->visited){
				n->adj[x].v->distance = n->distance+1;
				n->adj[x].v->visited=true;
				q.push(n->adj[x].v);
				cout << n->adj[x].v->name << "("
					<< n->adj[x].v->distance << ") ";

			}
		}

	}
	cout << endl;


}
vertex* Graph::dijkstraSearch(string start, string end){
	vertex *vStart = search(start);
	if(!vStart){
		cout << "Start city not found" << endl;
		return nullptr;
	}
	vertex *vEnd = search(end);
	if(!vEnd){
		cout << "Destination city not found" << endl;
		return nullptr;
	}
	vStart->solved = true;

	// Create a list to store solved vertices
	// and append vStart
	vector<vertex*> solvedList;
	solvedList.push_back(vStart);

	while(!vEnd->solved){
		int minDist = INT_MAX;
		// pointer to keep track of solved node
		vertex *solvedV = nullptr;

		// iterater across list of solved vertices
		for(int i=0; i<solvedList.size(); i++){
			vertex *s = solvedList[i];
			// now iterate s's adjacency list

			for(int j = 0; j < s->adj.size(); j++){
				if(!s->adj[j].v->solved){
					//calculate the distance from vSTart
					int dist = s->distDijk + s->adj[j].weight;
					// check if the distance is less than smallest distance thusfar
					if(dist<minDist){
						solvedV = s->adj[j].v;
						minDist = dist;
						//if you had parent ptr, update it here
					}
				}	
			}
			
		}

		solvedV->distDijk = minDist;
		// solvedV->parent
		solvedV->solved = true;
		solvedList.push_back(solvedV);

	}

	return vEnd;


}

void Graph::setAllVerticesUnvisited()
{
  int i;
  for(i=0; i<vertices.size(); i++) {
      vertices[i].visited = false;
      vertices[i].solved = false;
      vertices[i].distance = 0;
      vertices[i].distDijk = 0;
  }
}

vertex* Graph::search(string sKey){
	vertex *vFound = nullptr;
	for(int i=0; i<vertices.size(); i++){
		if(vertices[i].name == sKey)
			vFound = &vertices[i];
	}
	return vFound;
}

