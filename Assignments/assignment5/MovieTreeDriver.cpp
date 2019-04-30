#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace std;

#include "MovieTree.hpp"



int main(int argc, char *argv[]){

	MovieTree tree1;

	ifstream inputStream;
	inputStream.open(argv[1]);

	stringstream ss;
	string line;
	string sRanking;
	string title;
	string sYear;
	string sRating;


	if(inputStream.is_open()){

		while(getline(inputStream, line)){
			ss << line;
			getline(ss, sRanking, ',');
			getline(ss, title, ',');
			getline(ss, sYear, ',');
			getline(ss, sRating, ',');
			
			tree1.addMovieNode(stoi(sRanking), title, stoi(sYear), stof(sRating));

			ss.clear();
		}
		string choice = "0";
		while(stoi(choice) != 6){
			cout << "======Main Menu======" << endl;
			cout << "1. Find a movie" << endl;
			cout << "2. Query movies" << endl;
			cout << "3. Print the inventory" << endl;
			cout << "4. Average Rating of movies" << endl;
			cout << "5. Destruct Tree" << endl;
			cout << "6. Quit" << endl;

			getline(cin, choice);
			switch(stoi(choice)){
				case 1:{
					string title;
					cout << "Enter title:" << endl;
					getline(cin, title);
					tree1.findMovie(title);
					break;
				}
				case 2:{
					string minRate;
					string minYear;
					cout << "Enter minimum rating:" << endl;
					getline(cin, minRate);
					cout << "Enter minimum year:" << endl;
					getline(cin, minYear);
					tree1.queryMovies(stof(minRate), stoi(minYear));
					break;
				}
				case 3:{
					tree1.printMovieInventory();
					break;
				}
				case 4:{
					tree1.averageRating();
					break;
				}
				case 5:{
					tree1.~MovieTree();
					break;
				}
				case 6:{
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


