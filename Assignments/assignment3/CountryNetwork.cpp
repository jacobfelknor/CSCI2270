/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

Country *head; 

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
	head = nullptr;
}


/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
	if(head == nullptr){
		return true;
	}else{
		return false;
	}
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName)
{

	if(previous == nullptr && head != nullptr){
		cout << "adding: " << countryName << " (HEAD)" << endl;
		Country *temp = new Country;
		temp -> name = countryName;
		temp -> next = head;
		temp -> numberMessages = 0;
		head = temp;
		temp = nullptr;
	}

	if(isEmpty()){
		cout << "adding: " << countryName << " (HEAD)" << endl;
		head = new Country;
		head -> name = countryName;
		head -> numberMessages = 0;
		head -> next = nullptr;
	}

	if(previous != nullptr){
		Country *temp = head;
		Country *newCountry = new Country;
		bool found = false;

		if(head->next == nullptr){
			cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
			head->next = newCountry;
			newCountry->next = nullptr;
			newCountry->name = countryName;
			newCountry->numberMessages = 0;
		}else if(previous == head){
			cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
			newCountry->next = head->next;
			head->next = newCountry;
			newCountry->name = countryName;
			newCountry->numberMessages = 0;
		}else{
			while((temp->next != nullptr) && !found){
				if(temp->next == previous){
					cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
					found = true;
					temp = temp->next;
					newCountry->next = temp->next;
					temp -> next = newCountry;
					newCountry->name = countryName;
					newCountry->numberMessages = 0;
				}else{
					temp = temp -> next;
				}
			}
		}
		temp = nullptr;
	}


}


/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
void CountryNetwork::deleteCountry(string countryName)
{
	Country *searchPtr = new Country;

	searchPtr = searchNetwork(countryName);

	if(searchPtr == nullptr){
		cout << "Country does not exist." << endl;
		delete searchPtr;
		searchPtr = nullptr;
	}else if(searchPtr == head){
		head = head->next;
		delete searchPtr;
		searchPtr = nullptr;
	}else{
		Country *temp = new Country;
		temp = head;
		while(temp->next != searchPtr){
			temp = temp->next;
		}
		temp->next = searchPtr->next;
		delete searchPtr;
		temp = nullptr;
		searchPtr = nullptr;
	}

}


/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
	deleteEntireNetwork();

	insertCountry(nullptr, "United States");
    Country *USA = searchNetwork("United States");

    insertCountry(USA, "Canada");
    Country *Canada = searchNetwork("Canada");

    insertCountry(Canada, "Brazil");
    Country *Brazil = searchNetwork("Brazil");

    insertCountry(Brazil, "India");
    Country *India = searchNetwork("India");

    insertCountry(India, "China");
    Country *China = searchNetwork("China");

    insertCountry(China, "Australia");
    Country *Australia = searchNetwork("Australia");

}


/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
	Country *returnNode = nullptr;
	Country *tmp = head;

	bool found = false;

	while(!found && tmp != nullptr){
		if(tmp->name == countryName){
			found = true;
			returnNode = tmp;
			return returnNode;
		}else{
			tmp = tmp->next;
		}

	}

	if(!found){
		return nullptr;
	}
	
}


/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork()
{
	Country *temp, *current = head;
	bool check = false;

	while(current != nullptr){
		cout << "deleting: " << current->name << endl; 
		temp = current->next;
		delete current;
		current = temp;
		check = true;
	}
	head = nullptr;
	temp = nullptr;
	if(check){
		cout << "Deleted network" << endl;
	}
	
}


/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string msg)
{
	cout << endl;
	Country *temp = new Country;
	temp = head;

	while(temp->name != receiver){
		temp->message = msg;
		temp->numberMessages++;
		cout << temp->name << " [# messages received: " << temp->numberMessages <<
		"] received: " << temp->message << endl;
		temp = temp->next;
	}

	temp->message = msg;
	temp->numberMessages++;
	cout << temp->name << " [# messages received: " << temp->numberMessages <<
	"] received: " << temp->message << endl;

	temp = nullptr;
}


/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
    Country *current = head;
	cout << "== CURRENT PATH ==" << endl;

	if(current == nullptr){
		cout << "nothing in path" << endl;
		cout << "===" << endl;
	}else{
		while(current != nullptr){
			cout << current -> name << " -> ";
			current = current -> next;
		}

		cout << "NULL" << endl;
		cout << "===" << endl;
	}

}


/*
 * Purpose: reverse the entire network t
 * @param ptr head of list
 */
void CountryNetwork::reverseEntireNetwork()
{	
	Country *temp1 = new Country;
	Country *start = new Country;
	int count = 0;
	
	temp1 = head;

	if(temp1 != nullptr){
		while(temp1->next != nullptr){
			temp1 = temp1->next;
			count++;
		}

		for(int i = 0; i < count; i++){
			Country *temp = head;
			Country *newCountry = new Country;
			bool found = false;

			if(head->next == nullptr){
				head->next = newCountry;
				newCountry->next = nullptr;
				newCountry->name = head->name;
			}else if(temp1 == head){
				newCountry->next = head->next;
				head->next = newCountry;
				newCountry->name = head->name;
			}else{
				while((temp->next != nullptr) && !found){
					if(temp->next == temp1){
						found = true;
						temp = temp->next;
						newCountry->next = temp->next;
						temp -> next = newCountry;
						newCountry->name = head->name;
					}else{
						temp = temp -> next;
					}
				}
			}
			temp = nullptr;
			deleteCountry(head->name);
		}
	}

	//delete start;
	//start = nullptr;
}


