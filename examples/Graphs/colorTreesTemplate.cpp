// Write a c++ function to color vertices based on distance from the source. The function takes one 
// parameter: starting vertex. Color the source node as "Red". 
// Color all its neighbors(1 hop away from source) as "Black". Color all vertices that are 2 hops away 
// from source as "Red", 3 hops away as "Black" and so on. Use the built-in C++ queue data structure to 
// implement the queue.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct vertex;

struct adjVertex{
    vertex *v;
};

struct vertex{
    std::string name;
	bool visited;
	string color;
    std::vector<adjVertex> adj;
};

class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(std::string v1, std::string v2);
        void addVertex(std::string name);
        void displayVertices();
		void colorVertices(string sourceVertex);
    protected:
    private:
        std::vector<vertex> vertices;

};

Graph::Graph()
{

}

Graph::~Graph()
{
    //dtor
}
void Graph::addEdge(string v1, string v2){

    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(unsigned int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = &vertices[i];
                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}
void Graph::addVertex(string n){
    bool found = false;
    for( int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            //cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
		v.visited = false;
		v.color = "";
        vertices.push_back(v);

    }
}

void Graph::displayVertices(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<" --> ";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout << vertices[i].adj[j].v->name << " ";
        }
        cout<<endl;
    }

}
 
void Graph::colorVertices(string sourceVertex)
{
    // **************************
    // STUDENT SOLUTION GOES HERE
    // **************************

    vertex *vStart;

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == sourceVertex){
            vStart = &vertices[i];
        }
    }

    cout << "starting vertex (root): " << vStart->name << "-> ";

    vStart->visited = true;
    vStart->color = "Red";

    //use the STL queue to keep track of vertices to be visited

    queue<vertex*> q;

    //enqueue the starting vertex
    q.push(vStart);

    //need another vertex pointer 
    vertex *n;


    while(!q.empty()){
        // q dequeue 
        n = q.front(); // like a peek
        q.pop();

        for(int x = 0; x < n->adj.size(); x++){
            //check if vertex has been visisted 
            if(!n->adj[x].v->visited){
               
                n->adj[x].v->visited = true;
                q.push(n->adj[x].v);
                cout << n->adj[x].v->name; 

                //ADD SOLUTION HERE
                if(n->color == "Red"){
                    n->adj[x].v->color = "Black";
                }else{
                    n->adj[x].v->color = "Red";
                }
            }
        }
    } 

    cout << endl;
}

int main() {
	Graph g;

    g.addVertex("a");
    g.addVertex("b");
    g.addVertex("c");
    g.addVertex("d");
    g.addVertex("e");
    g.addVertex("f");

    g.addEdge("a", "b");
    g.addEdge("a", "e");
    g.addEdge("b", "c");
    g.addEdge("b", "f");
    g.addEdge("c", "d");
    g.addEdge("c", "e");
    
    g.colorVertices("a");
	g.displayVertices();
	return 0;
}