for(int i = 0; i < hashTableSize; i++){
		if(hashTable[i] != nullptr){
			cout << "'" << hashTable[i]->word << "' at index " << i << ". Count:" << hashTable[i]->count << endl;
			
			wordItem *temp = hashTable[i];
			while(temp->next != nullptr){
				cout << "	'" << temp->next->word << "' under index " << i << ". Count:" << temp->next->count << endl;
				temp = temp->next;
			}
			
		}
			
	}



//traversal

	for(int i = 0; i < hashTableSize; i++){
		if(hashTable[i] != nullptr){
			
			
			wordItem *temp = hashTable[i];
			while(temp->next != nullptr){
				
				temp = temp->next;
			}
			
		}
			
	}
