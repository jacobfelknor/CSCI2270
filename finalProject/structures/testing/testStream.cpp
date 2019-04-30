#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;


int main(){

	ifstream inStream;

	//vector<string> files = {"/home/angusfiedler/deploy/RestCSV/American.csv", "/home/angusfiedler/deploy/RestCSV/Chinese.csv", "/home/angusfiedler/deploy/RestCSV/Indian.csv", "/home/angusfiedler/deploy/RestCSV/Italian.csv", "/home/angusfiedler/deploy/RestCSV/Mexican.csv", "/home/angusfiedler/deploy/RestCSV/Pizza.csv", "/home/angusfiedler/deploy/RestCSV/Sandwiches.csv"};
	vector<string> files = {"allRestaurants.csv", "newRestaurants.csv"};

	for(int i = 0; i < files.size(); i++){
		inStream.open(files[i]);
		stringstream ss;
		string line;

		string name;
		string category;
		string rating;
		string location;
		string lat;
		string lng;

		string distance;

		if(inStream.is_open()){
			while(getline(inStream, line)){
				//cout << line << endl;
				ss << line;
				getline(ss, name, '"');
				getline(ss, category, '"');
				getline(ss, rating, '"');
				getline(ss, location, '"');
				getline(ss, lat, '"');
				getline(ss, lng);

				//g0.addVertex(name, category, location, stof(rating), stof(distance));
				cout << name << endl;
				cout << category << endl;
				cout << rating << endl;
				cout << location << endl;
				cout << lat << endl;
				cout << lng << endl;

				ss.clear();
			}
			inStream.close();	

		}
	}


	return 0;
}