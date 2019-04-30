#include <iostream>
using namespace std;

#include "hash.hpp"

int main(){
	int a[] = {15, 11, 27, 8, 12, 7, 18};
    int n = 7;

    // 7 is count of buckets in hash table
    HashTable ht(7);

    // insert the keys into the hash table.
    // SILVER TODO : Complete insertItem() function
    for (int i = 0; i < n; i++) {
        ht.insertItem(a[i]);
    }


    ht.printTable();

    cout << endl;

    ht.~HashTable();

    ht.printTable();
}