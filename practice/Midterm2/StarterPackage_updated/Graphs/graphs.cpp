#include<iostream>
#include <vector>
#include <queue>
using namespace std;

#include "graphs.hpp"

Graph::Graph(){

}

Graph::~Graph(){

}

void Graph::addEdge(int v1, int v2){

	for(int i = 0; i < vertices.size(); i++){
		if(vertices[i].id == v1){
			for(int j = 0; j < vertices.size(); j++){
				if(vertices[j].id == v2 && i!=j){
					vertex* av;
					av = &vertices[j];
					vertices[i].Edges.push_back(av);
					//add another vertexx in other direction
					// Edges av2;
					// av2.v = &vertices[i];
					// vertices[j].adj.push_back(av2);
				}
			}
		}
	}

}

void Graph::addVertex(int id){
	bool found = false;

	for(int i = 0; i < vertices.size(); i++){
		if(vertices[i].id == id){
			found = true;
			cout << vertices[i].id << " already exists" << endl;

		}
	}

	if(!found){
		vertex v;
		v.id = id;
		vertices.push_back(v);
	}
	
}


void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].id<<" --> ";
        for(int j = 0; j < vertices[i].Edges.size(); j++){
            cout << vertices[i].Edges[j]->id << " ";
        }
        cout<<endl;
    }

}


void Graph::setAllVerticesUnvisited(){
	for(int i = 0; i < vertices.size(); i++){
		vertices[i].visited = false;
	}
}




void Graph::printDFT(){
	setAllVerticesUnvisited();
	for(int i = 0; i < vertices.size(); i++){
		if(!vertices[i].visited)
			DFTraversal(&vertices[i]);
	}
}

void Graph::DFTraversal(vertex *v){
	cout << v->id << endl;
	DFT_recursive(v);
}


void Graph::DFT_recursive(vertex *v){
	v->visited = true;
	for(int i = 0; i < v->Edges.size(); i++){
		if(!v->Edges[i]->visited){
			cout << v->Edges[i]->id << endl;
			DFT_recursive(v->Edges[i]);
		}
	}
}


void Graph::printBFT(){
	setAllVerticesUnvisited();
	for(int i = 0; i < vertices.size(); i++){
		if(!vertices[i].visited)
			BFTraversal(&vertices[i]);
	}
}


void Graph::BFTraversal(vertex *v){
	cout << v->id << endl;
	v->visited = true;

	queue<vertex*> q;
	q.push(v);

	vertex *n;

	while(!q.empty()){
		n = q.front();
		q.pop();

		for(int i = 0; i < n->Edges.size(); i++){
			if(!n->Edges[i]->visited){
				n->Edges[i]->visited = true;
				q.push(n->Edges[i]);
				cout << n->Edges[i]->id << endl;
			}
		}
	}
}


vertex* Graph::findVertex(int id){
	vertex *v;

	for(int i = 0; i < vertices.size(); i++){
		if(vertices[i].id == id){
			v = &vertices[i];
		}
	}


	return v;

}