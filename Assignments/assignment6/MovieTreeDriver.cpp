#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

#include "MovieTree.hpp"


int main(int argc, char *argv[]){

	MovieTree tree1;

	ifstream inStream;
	inStream.open(argv[1]);

	stringstream ss;
	string line;
	string sRank;
	string title;
	string sYear;
	string sRating;

	if(inStream.is_open()){
		while(getline(inStream, line)){
			ss << line;
			getline(ss, sRank, ',');
			getline(ss, title, ',');
			getline(ss, sYear, ',');
			getline(ss, sRating, ',');

			tree1.addMovie(stoi(sRank), title, stoi(sYear), stof(sRating));

			ss.clear();
		}
		string choice = "0";
		while(stoi(choice) != 3){
			cout << "======Main Menu======" << endl;
			cout << "1. Print the inventory" << endl;
			cout << "2. Delete a movie" << endl;
			cout << "3. Quit" << endl;

			getline(cin, choice);

			switch(stoi(choice)){
				case 1:{
					tree1.printMovieInventory();
					break;
				}
				case 2:{
					string delTitle;
					cout << "Enter a movie title:" << endl;
					getline(cin, delTitle);
					tree1.deleteMovie(delTitle);
					break;
				}
				case 3:{
					cout << "Goodbye!" << endl;
					break;
				}
			}
		}
	}else{
		cout << "Error opening file." << endl;
	}


	return 0;
}