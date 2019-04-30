#include <iostream>
using namespace std;

#include "BST.hpp"
int COUNT = 10;

Node* BST:: createNode(int data)
{
    Node* newNode = new Node;
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


BST::BST()
{

}

BST::BST(int data)
{
    root = createNode(data);
    //<< "New tree created with "<<data<<endl;
}


void BST:: destroyNode(Node *currNode){
     if(currNode!=NULL)
     {
         destroyNode(currNode->left);
         destroyNode(currNode->right);

         delete currNode;
         currNode = NULL;
     }
 }

BST::~BST(){
     destroyNode(root);
}

void BST::print2DUtil( int space)
{
  print2DUtilHelper(root, space);
}



Node* BST:: addNodeHelper(Node* currNode, int data)
{
    if(currNode == NULL){
        return createNode(data);
    }
    else if(currNode->key < data){
        currNode->right = addNodeHelper(currNode->right,data);
    }
    else if(currNode->key > data){
        currNode->left = addNodeHelper(currNode->left,data);
    }
    return currNode;

}

void BST:: addNode(int data)
{
    addNodeHelper(root, data);
    //cout<<data<<" has been added"<<endl;
}


Node* BST::getMaxValueNode(Node* currNode){
    if(currNode->right == NULL){
        return currNode;
    }
    return getMaxValueNode(currNode->right);
}

Node* BST::getMinValueNode(Node* currNode){

    if(currNode->left == NULL){
      return currNode;
    }
    return getMinValueNode(currNode->left);
}


Node* BST::deleteNodeHelper(Node *currNode, int value)
{

  if(currNode == NULL)
  {
    return NULL;
  }
  else if(value < currNode->key)
  {
    currNode->left = deleteNodeHelper(currNode->left, value);
  }
  else if(value > currNode->key)
  {
    currNode->right = deleteNodeHelper(currNode->right, value);
  }
  // We found the node with the value
  else
  {
    //TODO Case : No child
    if(currNode->left == NULL && currNode->right == NULL)
    {
      delete currNode;
      currNode = nullptr;
    }
    //TODO Case : Only right child
    else if(currNode->left == NULL)
    {
      Node *temp = currNode;
      currNode = currNode->right;
      delete temp;
    }
    //TODO Case : Only left child
    else if(currNode->right == NULL)
    {
      Node *temp = currNode;
      currNode = currNode->left;
      delete temp;
    }
    //TODO Case: Both left and right child
    else
    {
      ///Replace with Minimum from right subtree
      Node *min = getMinValueNode(currNode->right);
      currNode->key = min->key;
      currNode->right = deleteNodeHelper(currNode->right, min->key);
      delete min;


    }

  }
return currNode;
}


void BST::deleteNode(int value){
    deleteNodeHelper(root, value);
}


Node* BST::searchKeyHelper(Node* currNode, int data){
    if(currNode == NULL)
        return NULL;

    if(currNode->key == data)
        return currNode;

    if(currNode->key > data)
        return searchKeyHelper(currNode->left, data);

    return searchKeyHelper (currNode->right, data);
}


bool BST::searchKey(int key){
    Node* tree = searchKeyHelper(root, key);
    if(tree != NULL) {
        return true;
    }
    cout<<"Key not present in the tree"<<endl;
    return false;
}



void BST:: printTreeHelper(Node* currNode){
     if(currNode)
     {
        printTreeHelper( currNode->left);
        cout << " "<< currNode->key;
        printTreeHelper( currNode->right);
     }
 }


 void BST:: printTree(){
     printTreeHelper(root);
     cout<<endl;
}


void BST::print2DUtilHelper(Node *currNode, int space)
{
    // Base case
    if (currNode == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtilHelper(currNode->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", currNode->key);

    // Process left child
    print2DUtilHelper(currNode->left, space);
}

