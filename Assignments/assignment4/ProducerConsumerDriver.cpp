/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>
#include <string>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[])
{

	ProducerConsumer pc1;

	bool check = true;
	int choice;
	int ITEM_NO;
	string newItem;
	string consumed;

	while(check){
		menu();
		cin >> choice;
		switch(choice){
			case 1:{
				cout << "Enter the number of items to be produced:" << endl;
				cin >> ITEM_NO;
				for(int i = 0; i < ITEM_NO; i++){
					cout << "Item" << i+1 << ":" << endl;
					cin >> newItem;
					pc1.enqueue(newItem);
				}
				//cout << "*----------------------------------------*" << endl;
				break;
			}
			case 2:{
				cout << "Enter the number of items to be consumed:" << endl;
				cin >> ITEM_NO;
				if(ITEM_NO > pc1.queueSize()){
					ITEM_NO = pc1.queueSize();
					for(int i = 0; i < ITEM_NO; i++){
						consumed = pc1.peek();
						pc1.dequeue();
						cout << "Consumed: " << consumed << endl;
					}
					cout << "No more items to consume from queue" << endl;
				}else{
					for(int i = 0; i < ITEM_NO; i++){
						consumed = pc1.peek();
						pc1.dequeue();
						cout << "Consumed: " << consumed << endl;
					}
					//cout << "*----------------------------------------*" << endl;
				}
				break;
			}
			case 3:{
				cout << "Number of items in the queue:" << pc1.queueSize() << endl;
				exit(0);
				break;
			}
		}
	}
}
