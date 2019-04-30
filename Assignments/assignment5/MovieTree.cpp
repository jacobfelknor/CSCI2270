#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;

#include "MovieTree.hpp"


void dispHelper(MovieNode *n){

	if(n == nullptr){

	}else{
		if(n->leftChild != nullptr){
			dispHelper(n->leftChild);
		}

		cout << "Movie: " << n->title << " " << n->rating << endl;

		if(n->rightChild != nullptr){
			dispHelper(n->rightChild);
		}
	}

	
}

void queryHelper(MovieNode *n, float rating, int year){

	if((n->year >= year) && (n->rating >= rating)){
		cout << n->title << "(" << n->year << ") " << n->rating << endl; 
	}

	if(n->leftChild != nullptr){
		queryHelper(n->leftChild, rating, year);
	}

	if(n->rightChild != nullptr){
		queryHelper(n->rightChild, rating, year);
	}
}

MovieNode *searchHelper(MovieNode *n, string title){
	if(n == nullptr || n->title == title){
		return n;
	}

	if(n->title.compare(title) < 0){
		return searchHelper(n->rightChild, title);
	}

	return searchHelper(n->leftChild, title);
}

void averageHelper(MovieNode *n, int &count, float &totalRating){

	if(n == nullptr){

	}else{
		
		if(n->leftChild != nullptr){
			averageHelper(n->leftChild, count, totalRating);
		}

		count++;
		totalRating = totalRating + n->rating;

		if(n->rightChild != nullptr){
			averageHelper(n->rightChild, count, totalRating);
		}
	}


}

void destructorHelper(MovieNode *node){

	if(node){
	    /*TODO first delete both subtrees */
	    destructorHelper(node->leftChild);
	    destructorHelper(node->rightChild);
	    /* TODO then delete the node */
	    delete node;
	}

}


MovieTree::MovieTree(){
	root = nullptr;
}

MovieTree::~MovieTree(){
	destructorHelper(root);
	root = nullptr;
}

MovieNode* MovieTree::search(string title){
	return searchHelper(root, title);
}

void MovieTree::printMovieInventory(){
	dispHelper(root);
}


void MovieTree::addMovieNode(int ranking, string title, int year, float rating){
	MovieNode *prev = nullptr;
	MovieNode *temp = root;

	MovieNode *n = new MovieNode;
	n->title = title;
	n->ranking = ranking;
	n->year = year;
	n->rating = rating;


	while(temp != nullptr){
		prev =temp;

		if(n->title.compare(temp->title) < 0){
			temp = temp->leftChild;
		}else{
			temp = temp->rightChild;
		}
	}


	if(prev == nullptr){
		root = n;
	}else if(n->title.compare(prev->title) < 0){
		prev->leftChild = n;
		n->parent = prev;
	}else{
		prev->rightChild = n;
		n->parent = n;
	}


}

void MovieTree::findMovie(string title){
	MovieNode *node = search(title);
	if(node != nullptr){
		cout << "Movie Info:" << endl;
		cout << "==================" << endl;
		cout << "Ranking:" << node->ranking << endl;
		cout << "Title  :" << node->title << endl;
		cout << "Year   :" << node->year << endl;
		cout << "rating :" << node->rating << endl; 
	}else{
		cout << "Movie '" << title << "' not found. " << endl;
	}
	
}

void MovieTree::queryMovies(float rating, int year){
	cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
	queryHelper(root, rating, year);
}

void MovieTree::averageRating(){
	int count = 0;
	float totalRating = 0;
	float average = 0;
	averageHelper(root, count, totalRating);
	if(count != 0){
		average = totalRating/float(count);
	}else{
		average = 0;
	}
	

	cout << "Average rating:" << average << endl;
}