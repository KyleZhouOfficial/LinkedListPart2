#include <cstring>
#include <iostream>
#include "Node.h"

using namespace std;

const int RED = 1;
const int BLACK  = 0;

void rightRot(Node* & curr){

}

void leftRot(Node* & curr, Node* & root){
  
  Node* temp = curr->right;
  curr->right = temp->left;

  if(temp.left != NULL){
    temp->left->parent = curr;
  }
   
  temp->parent = curr->parent;

  if(x->parent == NULL){
    root=temp;
  } else if(curr == curr->parent->left){
    curr->parent->left = temp;
  }
}

void fixTree(Node* &curr, Node* &root){
  while(curr->parent->color == RED){
    //if parent is left child of gp
    if(curr->parent->parent->left == par){
      //case 1 if both parent and uncle are red then flip and check grandparent
      if(curr->parent->parent->right->color == RED){
	curr->parent->parent->color = RED;
	curr->parent->parent->right = BLACK:
	curr->parent->parent->left = BLACK;
	curr = curr->parent->parent;
      }

      //case 2 parent is red uncle black 
      else if(curr == curr->parent->right){
	curr = curr->parent;
	leftRot(curr);
      }

      if(!curr->parent->color == RED) break;
      //case 3 
      curr->parent->color = BLACK;
      curr->parent->parent->color = RED;
      rightRot(curr->parent);
      
    } else {
      if(curr->parent->parent->left == RED){
	curr->parent->parent->left->color  = BLACK;
	curr->parent->parent->right->color  = BLACK;
	curr->parent->parent->color = RED;

	curr = curr->parent->parent;
      } else if(curr == curr->parent->left){
	curr = curr->parent;
	rightRot(curr);

	curr->parent->color = BLACK;
	curr->parent->parent->color = RED;
	leftRot(curr->parent->parent);
      }
      
    }
  }
   root->color = BLACK;
}


void add(Node* &root, int val){
  if(root == NULL){
    root = new Node(NULL, NULL, NULL, val, BLACK);
  } else{
    Node* prev = root;
    Node* temp = root;
    while(temp != NULL){
      prev = temp;
      if(val > temp->key){
	temp = temp->right;
      } else {
	temp = temp->left;
      }
    }

    Node* n = new Node(prev, NULL, NULL, val, RED);

    if(prev->key > val){
      prev->right = n;
    } else{
      prev->left = n;
    }

    fixTree(Node* &par, Node* &curr);

    
    
  }
}

int main(){
  Node* root = NULL;

  char[10] input;
  while(true){
    cout << "Enter ADD, READ, or PRINT" << endl;
    cin >> input;
    
    if(strcmp(input, "ADD") == 0){
      int val;
      cout << "What number to add: " << endl;
      cin >> val;
      add(root, val);
    } else if(strcmp(input, "READ")){

    } else if(strcmp(input, "PRINT")){

    } else{
      break;
    }
  }	
		

}
