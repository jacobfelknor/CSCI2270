struct Node
{
	int key;
	Node *parent;
	Node *leftChild;
	Node *rightChild;
};


class BinaryST
{
private:
	Node *root;
	// create these as private functions so that root can be abstracted from the user
	void dispPreOrd( Node *n );
	void dispInOrd( Node *n );
	void dispPostOrd( Node *n );
	Node* searchRecur( Node *n , int searchKey );
	Node* getMin( Node *n );

public:
	BinaryST(); // constructor declaration
	//~BinaryST();
	void insert( int newValue );
	void disp( string Order );
	Node* search( int value );
	Node* findMin();
	Node* getRoot(){return root;}
	void deleteNode( int value );

};