#include <iostream>
#include <string>
using namespace std;

#include "MovieTree.hpp"


void dispHelper(TreeNode *n){

	if(n == nullptr){

	}else{
		if(n->leftChild != nullptr){
			dispHelper(n->leftChild);
		}

		cout << "Movies starting with letter: " << n->titleChar << endl;
		LLMovieNode *temp = n->head;
		while(temp != nullptr){
			cout << " >> " << temp->title << " " << temp->rating << endl;
			temp = temp->next;
		}

		if(n->rightChild != nullptr){
			dispHelper(n->rightChild);
		}
	}

	
}

TreeNode *searchTree(TreeNode *n, string title){
	char firstLetter = title[0];
	if(n != nullptr){
		//cout << "node visited: " << n->key << endl;
		if(n->titleChar == firstLetter){
			return n;
		}else if(n->titleChar > firstLetter){
			return searchTree(n->leftChild, title);
		}else{
			return searchTree(n->rightChild, title);
		}
	}else{
		cout << "Movie: " << title << " not found, cannot delete." << endl;
		return nullptr;
	}
}


TreeNode *getMin(TreeNode *n){
	while(n->leftChild != nullptr){
		n = n->leftChild;
	}

	return n;
}


MovieTree::MovieTree(){
	root = nullptr;

}

void destructorHelper(TreeNode *node){

	if(node){
	    /*TODO first delete both subtrees */
	    destructorHelper(node->leftChild);
	    destructorHelper(node->rightChild);
	    /* TODO then delete the node */
	    LLMovieNode *temp, *current = node->head;
	    while(current != nullptr){
	    	temp = current->next;
	    	delete current;
	    	current = temp;
	    }
	    node->head = nullptr;
	    delete node;
	}

}

MovieTree::~MovieTree(){
	destructorHelper(root);
	root = nullptr;
}

void MovieTree::printMovieInventory(){
	dispHelper(root);
}

void MovieTree::addMovie(int ranking, string title, int year, float rating){
	char firstLetter = title[0];
	//cout << firstLetter << endl;
	
	TreeNode *prev = nullptr;
	TreeNode *temp = root;

	LLMovieNode *n = new LLMovieNode;
	n->title = title;
	n->ranking = ranking;
	n->year = year;
	n->rating = rating;
	n->next = nullptr;


	while(temp != nullptr && temp->titleChar != firstLetter){
		prev =temp;

		if(firstLetter < temp->titleChar){
			temp = temp->leftChild;
		}else{
			temp = temp->rightChild;
		}
	}

	if(prev == nullptr){
		if(temp == nullptr){
			TreeNode *newTreeNode = new TreeNode;
			newTreeNode->head = n;
			newTreeNode->titleChar = firstLetter;
			root = newTreeNode;
		}else{
			LLMovieNode *tempMovie = temp->head;
			LLMovieNode *last = nullptr;
			while(tempMovie != nullptr && n->title.compare(tempMovie->title) >= 0){
				last = tempMovie;
				tempMovie = tempMovie->next;
			}

			if(tempMovie != temp->head){
				n->next = last->next;
				last->next = n;
			}else{
				n->next = temp->head;
				temp->head = n;
			}
		}
		
	}else if(firstLetter < prev->titleChar){
		if(prev->leftChild == nullptr){
			TreeNode *newTreeNode = new TreeNode;
			prev->leftChild = newTreeNode;
			newTreeNode->parent = prev;
			newTreeNode->head = n;
			newTreeNode->titleChar = firstLetter;
		}else{
			LLMovieNode *tempMovie = temp->head;
			LLMovieNode *last = nullptr;
			while(tempMovie != nullptr && n->title.compare(tempMovie->title) >= 0){
				last = tempMovie;
				tempMovie = tempMovie->next;
			}

			if(tempMovie != temp->head){
				n->next = last->next;
				last->next = n;
			}else{
				n->next = temp->head;
				temp->head = n;
			}
		}
	}else if(firstLetter > prev->titleChar){
		if(prev->rightChild == nullptr){
			TreeNode *newTreeNode = new TreeNode;
			prev->rightChild = newTreeNode;
			newTreeNode->parent = prev;
			newTreeNode->head = n;
			newTreeNode->titleChar = firstLetter;
		}else{
			LLMovieNode *tempMovie = temp->head;
			LLMovieNode *last = nullptr;
			while(tempMovie != nullptr && n->title.compare(tempMovie->title) >= 0){
				last = tempMovie;
				tempMovie = tempMovie->next;
			}

			if(tempMovie != temp->head){
				n->next = last->next;
				last->next = n;
			}else{
				n->next = temp->head;
				temp->head = n;
			}
		}
	}


}

void MovieTree::deleteMovie(string title){
	TreeNode *n = searchTree(root, title);

	//simply deleting movie in the linked list
	if(n != nullptr){

		LLMovieNode *tempMovie;
		LLMovieNode *lastMovie = nullptr;

		if(n->head->title == title){
			tempMovie = n->head;
			n->head = n->head->next;
			delete tempMovie;
			tempMovie = nullptr;

		}else{

			lastMovie = n->head;
			tempMovie = n->head->next;
			bool found = false;

			while(tempMovie != nullptr && !found){
				if(tempMovie->title == title){
					found = true;
				}else{
					lastMovie = tempMovie;
					tempMovie = tempMovie->next;
				}
			}

			if(found){
				if(tempMovie->next == nullptr){
					lastMovie->next = nullptr;
				}else{
					lastMovie->next = tempMovie->next;
				}

				delete tempMovie;
				tempMovie = nullptr;
				lastMovie = nullptr;
			}

		}

		//linked list becomes empty, must delete TreeNode
		if(n->head == nullptr){
			if(n != root){
				if(n->leftChild == nullptr && n->rightChild == nullptr){
					if(n == n->parent->leftChild){
						n->parent->leftChild = nullptr;
					}else{
						n->parent->rightChild = nullptr;
					}
				}else if(n->leftChild != nullptr && n->rightChild != nullptr){
					TreeNode *min = getMin(n->rightChild);

					if(min == n->rightChild){
						if(n == n->parent->leftChild){
							n->parent->leftChild = min;
						}else{
							n->parent->rightChild = min;
						}

						min->parent = n->parent;
						min->leftChild = n->leftChild;
						min->leftChild->parent = min;
					}else{
						min->parent->leftChild = min->rightChild;

						if(min->rightChild != nullptr){
							min->rightChild->parent = min->parent;
						}

						if(n == n->parent->leftChild){
							n->parent->leftChild = min;
						}else{
							n->parent->rightChild = min;
						}

						min->parent = n->parent;
						min->leftChild = n->leftChild;
						min->leftChild->parent = min;
						min->rightChild = n->rightChild;
						min->rightChild->parent = min;
					}
				}else{
					if(n->leftChild != nullptr){
						n->leftChild->parent = n->parent;

						if(n == n->parent->leftChild){
							n->parent->leftChild = n->leftChild;
						}else{
							n->parent->rightChild = n->leftChild;
						}
					}else{
						n->rightChild->parent = n->parent;

						if(n = n->parent->leftChild){
							n->parent->leftChild = n->rightChild;
						}else{
							n->parent->rightChild = n->rightChild;
						}
					}

				}

			}else{

				if(n->rightChild == nullptr && n->leftChild == nullptr){
					root = nullptr;
				}else if(n->rightChild == nullptr && n->leftChild != nullptr){
					root = n->leftChild;
					root->parent = nullptr;
				}else if(n->rightChild != nullptr && n->leftChild == nullptr){
					root = n->rightChild;
					root->parent = nullptr;
				}else{

					TreeNode *min = getMin(n->rightChild);

					if(min == n->rightChild){
						min->leftChild = n->leftChild;
						min->parent = nullptr;
						root = min;
					}else{
						min->parent->leftChild = min->rightChild;

						if(min->rightChild != nullptr){
							min->rightChild->parent = min->parent;
						}

						min->leftChild = n->leftChild;
						min->rightChild = n->rightChild;
						n->rightChild->parent = min;
						min->parent = nullptr;
						root = min;

					}

				}
			}

			delete n;
			n = nullptr;

		}
		
	}

	
	
}



