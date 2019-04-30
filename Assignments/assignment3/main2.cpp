/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
#include <iostream>
#include <string>

// you may include more libraries as needed

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{
    CountryNetwork network1;
    string choice;

    while(choice != "8"){
        displayMenu();
        getline(cin, choice);
            if(stoi(choice) == 1){
                network1.loadDefaultSetup();
                network1.printPath();
            }else if(stoi(choice) == 2){
                network1.printPath();
            }else if(stoi(choice) == 3){
                if(network1.isEmpty()){
                    cout << "nothing in path" << endl;
                }
                string message, country;
                cout << "Enter name of the country to receive the message:" << endl;
                getline(cin, country);
                cout << "Enter the message to send:" << endl;
                getline(cin, message);
                network1.transmitMsg(country, message);
                
            }else if(stoi(choice) == 4){
                string newCountry, previous;
                Country *tmpPtr = new Country;
                cout << "Enter a new country name:" << endl;
                getline(cin, newCountry);
                cout << "Enter the previous country name (or First):" << endl;
                getline(cin, previous);
                tmpPtr = network1.searchNetwork(previous);
                if(tmpPtr == nullptr && previous != "First"){
                    cout << "INVALID country...Please enter a VALID previous country name:" << endl;
                }else{
                    network1.insertCountry(tmpPtr, newCountry);
                }
                network1.printPath();
                
            }else if(stoi(choice) == 5){
                string country;
                cout << "Enter a country name:" << endl;
                getline(cin, country);
                network1.deleteCountry(country);
                network1.printPath();
            }else if(stoi(choice) == 6){
                network1.reverseEntireNetwork();
                network1.printPath();
            }else if(stoi(choice) == 7){
                network1.deleteEntireNetwork();
            }else if(stoi(choice) == 8){
                cout << "Quitting... cleaning up path: " << endl;
                network1.printPath();
                network1.deleteEntireNetwork();
                if(network1.isEmpty()){
                    cout << "Path cleaned" << endl;
                    cout << "Goodbye!" << endl;
                }else{
                    cout << "Error: Path NOT cleaned" << endl;
                    //choice = 0;
                }
            }
    }
    

}

/*
 * Purpose: displays a menu with options
 */
void displayMenu()
{
    cout << endl;
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Delete Country " << endl;
    cout << " 6. Reverse Network" << endl;
    cout << " 7. Clear Network " << endl;
    cout << " 8. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}