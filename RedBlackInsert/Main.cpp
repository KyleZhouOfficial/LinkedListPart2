#include <cstring>
#include <iostream>
#include "Node.h"

using namespace std;



const int RED = 1;
const int BLACK  = 0;

void rightRot(Node* curr, Node* & root){
  
  Node* temp = curr->left;
  curr->left = temp->right;

  if(temp->right->isLeaf != false){
    temp->right->parent = curr;
  }
   
  temp->parent = curr->parent;

  if(curr->parent == NULL){
    root=temp;
  } else if(curr == curr->parent->left){
    curr->parent->left = temp;
  } else{
    curr->parent->right = temp;
  }

  temp->right = curr;
  curr->parent = temp;
}

void leftRot(Node* curr, Node* &root){
  
  Node* temp = curr->right;
  curr->right = temp->left;

  if(temp->left->isLeaf != false){
    temp->left->parent = curr;
  }
   
  temp->parent = curr->parent;

  if(curr->parent == NULL){
    root=temp;
  } else if(curr == curr->parent->left){
    curr->parent->left = temp;
  } else{
    curr->parent->right = temp;
  }

  temp->left = curr;
  curr->parent = temp;
}

void fixTree(Node* curr, Node* &root){
  Node* uncle;
  while(curr->parent->color == RED){
    //if parent is left child of gp
    if(curr->parent->parent->right == curr->parent){
     uncle = curr->parent->parent->left;
      //case 1 if both parent and uncle are red then flip and check grandparent
      if(uncle != NULL && uncle->color == RED){
	uncle->color = BLACK;
	curr->parent->color = BLACK;
	curr->parent->parent->color = RED;
	curr = curr->parent->parent;
      } else{  //case 2 parent is red uncle black 
	if(curr == curr->parent->left){
	  curr = curr->parent;
	  rightRot(curr, root);
	}
	curr->parent->color = BLACK;
	curr->parent->parent->color = RED;
	leftRot(curr->parent->parent, root);

      }
    } else{
	uncle = curr->parent->parent->right;

	if(uncle != NULL && uncle->color == RED){
	  uncle->color = BLACK;
	  curr->parent->color = BLACK;
	  curr->parent->parent->color = RED;
	  curr = curr->parent->parent;
	} else{
	  if(curr == curr->parent->right){
	    curr = curr->parent;
	    leftRot(curr, root);
	  }
	  curr->parent->color = BLACK;
	  curr->parent->parent->color = RED;
	  rightRot(curr->parent->parent, root);
	}
    }
  
      if(curr == root){
	break;
      }
    }
    root->color = BLACK;
  }

     
     

    


void add(Node* &root, int val){
  Node* add = new Node(NULL, NULL, NULL, val, RED, false);
  add->left = new Node(add);
  add->right = new Node(add);
  
  if(root == NULL){
    add->color = BLACK;
    root = add;
    return;
  } else{
    
    Node* prev = NULL;
    Node* temp = root;
    while(!temp->isLeaf){
      prev = temp;
      if(val > temp->key){
	temp = temp->right;
      } else {
	temp = temp->left;
      }

    }
    add->parent = prev;

    
    if(prev->key > val){
      prev->left = add;
    } else{
      prev->right = add;
    }

    if(add->parent == NULL){
      add->color = BLACK;
      return;
    }

    if(add->parent->parent == NULL){
      return;
    }

    fixTree(add, root);

    
  }
}

//print 
void print(Node* curr, int depth){
  //if at end of link then return
  if(curr->isLeaf) return;
  //go right and increase depth
  print(curr->right, depth+1);
  //print out spaces equal to depth
  for(int i = 0; i < depth; i++) cout << " ";
  //print out current node
  cout << curr->key << endl;
  //go left 
  print(curr->left, depth+1);
}

int main(){
  Node* root = NULL;

  char input[10];
  while(true){
    cout << "Enter ADD, READ, or PRINT" << endl;
    cin >> input;
    
    if(strcmp(input, "ADD") == 0){
      int val;
      cout << "What number to add: " << endl;
      cin >> val;
      add(root, val);
    } else if(strcmp(input, "READ")== 0){

    } else if(strcmp(input, "PRINT") == 0){
      int depth = 0;
      print(root, depth);
    } else{
      break;
    }
  }	
		

}
