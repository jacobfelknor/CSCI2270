#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

#include "Graph.hpp"


int main(int argc, char *argv[]){

	vector<string> v;
	Graph g0;

	ifstream inStream;
	inStream.open(argv[1]);

	if(inStream.is_open()){
		stringstream ss;
		string line;
		string city;
		string distance;

		getline(inStream, line);
		ss << line;

		while(getline(ss, city, ',')){
			v.push_back(city);
		}

		for(int i = 1; i < v.size(); i++){
			g0.addVertex(v[i]);
		}

		ss.clear();

		int index1 = 1;
		int index2 = 1;
		while(getline(inStream, line)){
			index2 = 1;
			ss << line;
			getline(ss, city, ',');
			while(getline(ss, distance, ',')){
				if(stoi(distance)>0){
					g0.addEdge(v[index1], v[index2], stoi(distance));
					cout << " ... Reading in " << v[index1] << " -- " << v[index2] << " -- "
					<< distance << endl;
				}
				index2++;
			}

			index1++;
			ss.clear();
		}


		cout << "------------------------------ " << endl
		<< "Breadth First Traversal" << endl 
		<< "------------------------------" << endl;
		g0.printBFT();

		cout << "------------------------------ " << endl
		<< "Depth First Traversal" << endl 
		<< "------------------------------" << endl;
		g0.printDFT();

		cout << "------------------------------ " << endl
		<< "Display Edges" << endl 
		<< "------------------------------" << endl;
		g0.displayEdges();

	}else{
		cout << "Error opening file" << endl;
		exit(0);
	}

	return 0;
}