#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct User{
	string username;
	int age;
	float gpa;
};


void addUser(User users[], string _username, float _gpa, int _age, int length);
void printList(const User users[], int length);

int main(int argc, char *argv[]){
	int N = 100;
	User users[N];
	for(int i = 0; i < N; i++){
		users[i].age = 0;
		users[i].gpa = 0;
	}

	ifstream inStream;
	inStream.open(argv[1]);

	stringstream ss;
	string line;
	string name;
	string sGpa;
	string sAge;

	int numUser = 0;
	while(getline(inStream, line, '\r')){
		ss << line;

		//cout << line << endl;
		getline(ss, name, ',');
		getline(ss, sGpa, ',');
		getline(ss, sAge);

		users[numUser].username = name;
		users[numUser].age = stoi(sAge);
		users[numUser].gpa = stof(sGpa);

		ss.clear();
		numUser++;
	}

	inStream.close();



	//(users, "Jacob", 4.0, 18, numUser++);

	ofstream outStream;
	outStream.open(argv[2]);

	for(int i = 0; i < N; i++){
		if(users[i].gpa >= stof(argv[3])){
			/*outStream << users[i].username << ",";
			outStream << users[i].gpa << ",";
			outStream << users[i].age << endl;*/

			outStream << users[i].username << " [" << users[i].gpa << "] age: " << users[i].age << endl; 
		}
	}

	outStream.close();
	printList(users, numUser);
	//cout << users[numUser]
	

	return 0;
}



void addUser(User users[], string _username, float _gpa, int _age, int length){
	User newUser;

	newUser.username = _username;
	newUser.age = _age;
	newUser.gpa = _gpa;

	users[length] = newUser;
}



void printList(const User users[], int length){
	for(int i = 0; i < length; i++){
		cout << users[i].username << " [" << users[i].gpa << "] age: " << users[i].age << endl; 
	}
}