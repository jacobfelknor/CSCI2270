#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    // Key value
    std::string name;
    // List of edges
    std::vector<adjVertex> adj;
    
    // visited member for Breadth First Traverse
    bool visited;
    // distance member for BFT
    int distance;

    // solved member for Dijkstra's
    bool solved;
    // distDijk for weighted distance
    int distDijk;

};

class Graph
{
    public:
        void addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string name);
        void displayEdges();
        void breadthFirstTraverse(std::string sourceVertex);
        vertex* dijkstraSearch(std::string start, std::string end);
        void setAllVerticesUnvisited();
        vertex* search(std::string sKey);

    private:
        std::vector<vertex> vertices;

};

#endif // GRAPH_H
