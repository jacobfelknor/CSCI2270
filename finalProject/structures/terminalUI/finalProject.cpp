#include <iostream>
#include <vector>
using namespace std;

#include "finalProject.h"


bool operator<(const vertex& v1, const vertex& v2){return v1.weight > v2.weight;}

Graph::Graph(){

}

Graph::~Graph(){

}


void Graph::addVertex(string restaurantName, string category, string location, double rating, double lat, double lng, float distance){
	vertex v1;
	v1.name = restaurantName;
	v1.category = category;
	v1.location = location;
	v1.distance = distance;
	v1.lat = lat;
	v1.lng = lng;
	v1.rating = rating;
	v1.saved = false;
	v1.count = 0;
	vertices.push_back(v1);
	
}

void Graph::addEdge(string restaurant1, string restaurant2){
	for(int i = 0; i < vertices.size(); i++){
		if(vertices[i].name == restaurant1){
			for(int j = 0; j < vertices.size(); j++){
				if(vertices[j].name == restaurant2 && j!=i){
					Edge e0;
					e0.v = &vertices[j];
					//e0.distance = distance;
					vertices[i].Edges.push_back(e0);
					//add vertex in other direction
					Edge e1;
					e1.v = &vertices[i];
					//e1.distance = distance;
					vertices[j].Edges.push_back(e1);
				}
			}
		}
	}


}


bool Graph::inEdges(vertex *v1, vertex *v2){
	for(int i = 0; i < v1->Edges.size(); i++){
		if(v2->name == v1->Edges[i].v->name)
			return true;
	}

	return false;
}

void Graph::buildEdges(){
	for(int i = 0; i < vertices.size(); i++){
		string category = vertices[i].category;
		
		for(int j = 0; j < vertices.size(); j++){
			if(vertices[j].category == category && j!=i && !inEdges(&vertices[i], &vertices[j])){
				Edge e0;
				e0.v = &vertices[j];
				//e0.distance = distance;
				vertices[i].Edges.push_back(e0);
				//add vertex in other direction
				Edge e1;
				e1.v = &vertices[i];
				//e1.distance = distance;
				vertices[j].Edges.push_back(e1);
			}
		}

	}

}


void Graph::displayEdges(){
	for(int i = 0; i < vertices.size(); i++){
		cout << vertices[i].name << "-->";
		for(int j = 0; j < vertices[i].Edges.size(); j++){
			if(j < vertices[i].Edges.size()-1){
				cout << vertices[i].Edges[j].v->name << "-->";
			}else{
				cout << vertices[i].Edges[j].v->name << endl;
			}
		}
		cout << endl;
	}
}


vertex* Graph::findVertex(string name){
	vertex *found = nullptr;
	for(int i = 0; i < vertices.size(); i++){
		if(vertices[i].name == name){
			if(!found){
				found = &vertices[i];
			}else if(found->distance > vertices[i].distance){
				found = &vertices[i];
			}
		}
	}

	return found;
}


vertex* Graph::findVertex(string name, string location){
	vertex *found = nullptr;
	for(int i = 0; i < vertices.size(); i++){
		if(vertices[i].name == name && vertices[i].location == location){
			found = &vertices[i];
			break;
		}
	}

	return found;
}


void Graph::setWeights(vector<vertex*> recommendations){
	float distance;
    float rating;
    int count;
    float weight;
	for(int i = 0; i < recommendations.size(); i++){
		distance = recommendations[i]->distance;
		rating = recommendations[i]->rating;
		count = recommendations[i]->count;
		weight = count + 3*rating - 2*distance;
		recommendations[i]->weight = weight;
	}
}


bool Graph::inRecommendations(vertex *v, vector<vertex*> recommendations){
	for(int i = 0; i < recommendations.size(); i++){
		if(recommendations[i]->name == v->name)
			return true;
	}

	return false;
}


void Graph::recommend(){

	vector<vertex*> recommendations;

	if(savedRestaurants.size() == 0)
		return;

	for(int i = 0; i < savedRestaurants.size(); i++){
		
		for(int j = 0; j < savedRestaurants[i]->Edges.size(); j++){
			if(!inRecommendations(savedRestaurants[i]->Edges[j].v, recommendations) && !savedRestaurants[i]->Edges[j].v->saved){
				recommendations.push_back(savedRestaurants[i]->Edges[j].v);

			}else{
				savedRestaurants[i]->Edges[j].v->count++;
			}
		}
	}


	setWeights(recommendations);

	//after weights are set, reset counts so they reflect the # of times 
	//restaurant has been saved

	for(int i = 0; i < savedRestaurants.size(); i++){
		
		for(int j = 0; j < savedRestaurants[i]->Edges.size(); j++){
			if(savedRestaurants[i]->Edges[j].v->saved){
				savedRestaurants[i]->Edges[j].v->count--;
			}
		}
	}


	vector<vertex> tempRec;

	for(int i = 0; i < recommendations.size(); i++){
		tempRec.push_back(*recommendations[i]);
	}

	sort(tempRec.begin(), tempRec.end());

	// IF USING CATCHALL METHOD, BUILD JSON. IF TERMINAL METHOD, COUT RECOMMENDATIONS

	//buildJSON(tempRec);

	string numRec;
	cout << "How many recommendations do you want to see?" << endl;
	getline(cin, numRec);

	if(recommendations.size() >= stoi(numRec)){
		cout << "Top " << numRec << " recommendations: " << endl;
		for(int i = 0; i < stoi(numRec); i++){
			displayVertex(&tempRec[i]);
			}
	}else{
		cout << "Top " << recommendations.size() << " recommendations:" << endl;
		for(int i = 0; i < recommendations.size(); i++){
			displayVertex(&tempRec[i]);
		}
	}

}

void Graph::recommend(string category){

	vector<vertex*> recommendations;

	if(savedRestaurants.size() == 0){
		return;
	}

	bool catCheck = false;
	for(int i = 0; i < savedRestaurants.size(); i++){
		if(savedRestaurants[i]->category == category){
			catCheck == true;
		}
	}

	if(catCheck){
		for(int i = 0; i < savedRestaurants.size(); i++){
			
			for(int j = 0; j < savedRestaurants[i]->Edges.size(); j++){
				if(!inRecommendations(savedRestaurants[i]->Edges[j].v, recommendations) && !savedRestaurants[i]->Edges[j].v->saved && savedRestaurants[i]->Edges[j].v->category == category){
					recommendations.push_back(savedRestaurants[i]->Edges[j].v);

				}else{
					savedRestaurants[i]->Edges[j].v->count++;
				}
			}
		}
	}else{
		for(int i = 0; i < vertices.size(); i++){
			if(vertices[i].category == category){
				recommendations.push_back(&vertices[i]);
			}
		}
	}


	setWeights(recommendations);

	//after weights are set, reset counts so they reflect the # of times 
	//restaurant has been saved

	for(int i = 0; i < savedRestaurants.size(); i++){
		
		for(int j = 0; j < savedRestaurants[i]->Edges.size(); j++){
			if(savedRestaurants[i]->Edges[j].v->saved){
				savedRestaurants[i]->Edges[j].v->count--;
			}
		}
	}


	vector<vertex> tempRec;

	for(int i = 0; i < recommendations.size(); i++){
		tempRec.push_back(*recommendations[i]);
	}

	sort(tempRec.begin(), tempRec.end());

	// IF USING CATCHALL METHOD, BUILD JSON. IF TERMINAL METHOD, COUT RECOMMENDATIONS

	//buildJSON(tempRec);

	string numRec;
	cout << "How many recommendations do you want to see?" << endl;
	getline(cin, numRec);

	if(recommendations.size() >= stoi(numRec)){
		cout << "Top " << numRec << " recommendations: " << endl;
		for(int i = 0; i < stoi(numRec); i++){
			displayVertex(&tempRec[i]);
			}
	}else{
		cout << "Top " << recommendations.size() << " recommendations:" << endl;
		for(int i = 0; i < recommendations.size(); i++){
			displayVertex(&tempRec[i]);
		}
	}

}

void Graph::saveRestaurant(string restaurantName){
	bool found = false;
	for(int i = 0; i < savedRestaurants.size(); i++){
		if(savedRestaurants[i]->name == restaurantName){
			found = true;
			savedRestaurants[i]->count++;
		}
	}

	if(!found){
		vertex *v = findVertex(restaurantName);
		savedRestaurants.push_back(v);
		v->saved = true;
		v->count++;
	}
}

void Graph::removeSaved(string restaurantName){
	bool found = false;
	string choice;

	for(int i = 0; i < savedRestaurants.size(); i++){
		if(savedRestaurants[i]->name == restaurantName){
			found == true;
			cout << "Are you sure you want to remove " <<
			savedRestaurants[i]->name << "? Y/n" << endl;
			getline(cin, choice);
			if(choice == "Y"){
				vertex *target = findVertex(restaurantName);
				target->saved = false;
				target->count = 0;
				savedRestaurants.erase(savedRestaurants.begin() + i);
				cout << "Restaurant removed" << endl;
			}else{
				cout << "No changes made" << endl;
			}
			break;
		}
	}
}


void Graph::displayVertex(vertex *v){
	cout << v->name << endl;
	cout << "	Category: " << v->category << endl;
	cout << "	Location: " << v->location<< endl;
	//distance below is "as the crow flies"
	cout << "	Distance: " << v->distance << " miles" << endl;
	cout << "	Rating: " << v->rating << endl;
	cout << "	Count: " << v->count << endl;
	cout << "	Weight: " << v->weight << endl;
}

void Graph::displayAllVertices(){
	for(int i = 0; i < vertices.size(); i++){
		displayVertex(&vertices[i]);
	}
}

void Graph::displaySaved(){
	for(int i = 0; i < savedRestaurants.size(); i++){
		displayVertex(savedRestaurants[i]);
	}
}



void Graph::buildJSON(vector<vertex> tempRec){
	// SEPERATE RESTAURANT METHOD

	vector<jsonVertex> outs(5);

	for(int i = 0; i < 5; i++){
		outs[i].name = tempRec[i].name;
		outs[i].category = tempRec[i].category;
		outs[i].location = tempRec[i].location;
		outs[i].distance = tempRec[i].distance;
		outs[i].rating = tempRec[i].rating;
		outs[i].category = tempRec[i].category;
	}




	//FILE STREAM METHOD

	//ofstream writeFile1("/home/angusfiedler/deploy/static/1.json");
	ofstream writeFile1("1.json");
	WriteJSON(writeFile1, outs[0]);

	// ofstream writeFile2("/home/angusfiedler/deploy/static/2.json");
	ofstream writeFile2("2.json");
	WriteJSON(writeFile2, outs[1]);

	// ofstream writeFile3("/home/angusfiedler/deploy/static/3.json");
	ofstream writeFile3("3.json");
	WriteJSON(writeFile3, outs[2]);

	//ofstream writeFile4("/home/angusfiedler/deploy/static/4.json");
	ofstream writeFile4("4.json");
	WriteJSON(writeFile4, outs[3]);

	//ofstream writeFile5("/home/angusfiedler/deploy/static/5.json");
	ofstream writeFile5("5.json");
	WriteJSON(writeFile5, outs[4]);


	//STRING VARIABLE METHOD:

	// string rec1 = ToJSON(outs[0]);
	// string rec2 = ToJSON(outs[1]);
	// string rec3 = ToJSON(outs[2]);
	// string rec4 = ToJSON(outs[3]);
	// string rec5 = ToJSON(outs[4]);


}


void Graph::saveData(){

	ofstream outStream;

	// outStream.open("/home/angusfiedler/deploy/static/savedRestaurants.csv");
	outStream.open("savedRestaurants.csv");
	for(int i = 0; i < savedRestaurants.size(); i++){
		outStream << savedRestaurants[i]->name << "," << savedRestaurants[i]->count << endl;
	}

	outStream.close();

	outStream.open("allRestaurants.csv");

	for(int i = 0; i < vertices.size(); i++){
		outStream << vertices[i].name << '"' << vertices[i].category << '"' << vertices[i].rating << '"' << vertices[i].location << '"' << vertices[i].lat << '"' << vertices[i].lng << endl;
	}
}

void Graph::loadData(){
	ifstream inStream;
	//inStream.open("/home/angusfiedler/deploy/static/savedRestaurants.csv");
	inStream.open("savedRestaurants.csv");

	string name;
	string count;
	while(getline(inStream, name, ',')){
		getline(inStream, count);

		for(int i = 0; i < stoi(count); i++){
			saveRestaurant(name);
		}

	}

	inStream.close();

}