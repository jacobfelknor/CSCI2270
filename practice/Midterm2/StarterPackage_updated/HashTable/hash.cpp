#include <iostream>
using namespace std;

#include "hash.hpp"

node* HashTable::createNode(int key)
{
    node* nw = new node;
    nw->key = key;
    //nw->next = next;
    return nw;
}


HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    hashTable = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        hashTable[i] = nullptr;
}

HashTable::~HashTable(){
	node *temp;
	node *next;
	for(int i = 0; i < tableSize; i++){
		temp = hashTable[i];
		while(temp != nullptr){
			next = temp->next;
			delete temp;
			temp = next;
		}

		hashTable[i] = nullptr;
	}
}


node* HashTable::searchItem(int key)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);

    //TODO: Search the list at that specific index and return the node if found
    bool found = false;
    node *temp = hashTable[index];
    while(!found && temp != nullptr){
        if(temp->key == key){
            return temp;
        }else{
            temp = temp->next;
        }
    }

    return nullptr;

    
}


unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}



bool HashTable::insertItem(int key)
{
    if(!searchItem(key))
    {
        // TODO :
        // Use the hash function on the key to get the index/slot,
        // create a new node with the key and insert it in this slot's list
        int index = hashFunction(key);
        node* n = createNode(key);
        n->next = hashTable[index];
        hashTable[index] = n;
        return true;

     }
    else{
        cout<<"duplicate entry: "<<key<<endl;
        return false;
    }

}


void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";

        //TODO
        node *temp = hashTable[i];
        while(temp != nullptr){
            cout << temp->key << "-->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

 }
