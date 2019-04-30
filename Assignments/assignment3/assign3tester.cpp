#include "CountryNetwork.hpp"
#include <iostream>
#include <string>

// you may include more libraries as needed

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{
    CountryNetwork network1;

    network1.loadDefaultSetup();

    network1.printPath();

    //network1.reverseEntireNetwork();

    network1.transmitMsg("China", "hello");
     network1.transmitMsg("China", "fucker");

}