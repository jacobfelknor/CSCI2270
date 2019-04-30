#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

#include "PriorityQueue.hpp"


int main(int argc, char *argv[]){

	if(argc != 2){
		cout << "Usage: ./a [size of queue]" << endl;
		exit(0);
	}

	PriorityQueue q0(stoi(argv[1]));

	int choice = 0;
	string name;
	string size;
	string time;

	int totalCookTime = 0;

	while(choice!=6){
		cout << "============Main Menu============" << endl;
		cout << "1. Get group information from file" << endl;
		cout << "2. Add a group to Priority Queue" << endl;
		cout << "3. Show next group in the queue" << endl;
		cout << "4. Serve Next group" << endl;
		cout << "5. Serve Entire Queue" << endl;
		cout << "6. Quit" << endl;
		cin >> choice;

		switch(choice){
			case 1:{
				ifstream inStream;

				stringstream ss;
				string line;
				string fileName;

				cout << "Enter filename:" << endl;
				cin.ignore();
				getline(cin, fileName);

				inStream.open(fileName);

				if(inStream.is_open()){
					while(getline(inStream, line)){
						ss << line;
						ss >> name;
						ss >> size;
						ss >> time;

						q0.enqueue(name, stoi(size), stoi(time));

						//cout << name << size << time << endl;

						ss.clear();
					}
				}else{
					cout << "Error opening file" << endl;
					break;
				}


				break;
			}
			case 2:{
				cin.ignore();

				cout << "Enter Group Name:" << endl;
				getline(cin, name);
				cout << "Enter Group Size:" << endl;
				getline(cin, size);
				cout << "Enter Estimated Cooking Time:" << endl;
				getline(cin, time);

				q0.enqueue(name, stoi(size), stoi(time));

				break;
			}
			case 3:{
				if(!q0.isEmpty()){
					cout << "Group Name: " << q0.peek().groupName << endl;
					cout << "Group Size: " << q0.peek().groupSize << endl;
					cout << "Group Time: " << q0.peek().cookingTime << endl;
				}else{
					q0.peek();
				}

				break;
			}
			case 4:{
				if(!q0.isEmpty()){
					totalCookTime = totalCookTime + q0.peek().cookingTime;

					cout << "Group Name: " << q0.peek().groupName
						<< " - Total Cook Time for the Group: "
						<< totalCookTime << endl;
				}

				q0.dequeue();

				break;
			}
			case 5:{

				while(!q0.isEmpty()){
					totalCookTime = totalCookTime + q0.peek().cookingTime;

					cout << "Group Name: " << q0.peek().groupName
						<< " - Total Cook Time for the Group: "
						<< totalCookTime << endl;

					q0.dequeue();
				}

				//q0.dequeue();

				break;
			}
			case 6:{
				cout << "Goodbye!" << endl;
				break;
			}
		}
	}

	return 0;
}