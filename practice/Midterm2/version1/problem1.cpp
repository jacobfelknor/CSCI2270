#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

	
struct item{
	int key;
	item *next;
};

class Hash{
private:
	int table_size = 10;

	item **table;

	int hashSum(int key){
		return abs(key%table_size);
	}

public:

	

	Hash(){
		table = new item*[table_size];
		for(int i = 0; i < table_size; i++){
			table[i] = nullptr;
		}
	}

	item* search(int key){
		int index = hashSum(key);
		
		bool found = false;
	    item *temp = table[index];
	    while(!found && temp != nullptr){
	        if(temp->key == key){
	            return temp;
	        }else{
	            temp = temp->next;
	        }
	    }

    	return nullptr;
	}


	void insert(int key){
		int index = hashSum(key);
		if(table[index] == nullptr){
			table[index] = new item;
			table[index]->key = key;
			table[index]->next = nullptr;
		}else{
			item *prev = nullptr;
			item *temp = table[index];
			while(temp != nullptr){
				prev = temp;
				temp = temp->next;
			}

			prev->next = new item;
			prev->next->key = key;
			prev->next->next = nullptr;
		}
	}


	void printTable(){
	    for (int i = 0; i < table_size; i++) {
	        cout << i <<"|| ";

	        //TODO
	        item *temp = table[i];
	        while(temp != nullptr){
	            cout << temp->key << "-->";
	            temp = temp->next;
	        }
	       cout << "NULL" << endl;
	    }

	}

	bool findThreeSum(int arr[], int length){
		for(int i = 0; i < length; i++){
			insert(arr[i]);
		}
		//printTable();

		int current;
		int need;
		for(int i = 0; i < length; i++){
			current = search(arr[i])->key;
			for(int j = 0; j < length; j++){
				if(j!=i){
					need = 0 - (current + search(arr[j])->key);
					//cout << "current:" << current << " on:" << search(arr[j])->key << " needs:" << need << endl;
					if(search(need) && search(need) != search(arr[i]) && search(need) != search(arr[j])){
						cout << endl << endl << current << ", " << search(arr[j])->key << ", " << need << endl;
						return true;
					}
				}
			}
		}

		return false;
	}
};






int main(){

	Hash h0;
	int arr_size = 6;
	int arr[arr_size];

	srand(time(NULL));

	for(int i = 0; i < arr_size; i++){
		arr[i] = rand()%40 - rand()%40;
		cout << arr[i] << " " << endl;
	}

	if(h0.findThreeSum(arr, arr_size)){
		cout << "True" << endl;
	}else{
		cout << "False" << endl;
	}
	
}