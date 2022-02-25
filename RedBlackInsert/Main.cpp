#include <cstring>
#include <iostream>
#include "Node.h"

using namespace std;

const int RED = 1;
const int BLACK  = 0;

void rightRot(Node* & curr, Node* &root){
  
  Node* temp = curr->left;
  curr->left = temp->right;

  if(temp->right != NULL){
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

void leftRot(Node* & curr, Node* & root){
  
  Node* temp = curr->right;
  curr->right = temp->left;

  if(temp->left != NULL){
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

void fixTree(Node* &curr, Node* &root){
  while(curr->parent->color == RED){
    //if parent is left child of gp
    if(curr->parent->parent->left == curr->parent){
      //case 1 if both parent and uncle are red then flip and check grandparent
      if(curr->parent->parent->right->color == RED){
	curr->parent->parent->color = RED;
	curr->parent->parent->right->color = BLACK;
	curr->parent->parent->left->color = BLACK;
	curr = curr->parent->parent;
      }

      //case 2 parent is red uncle black 
      else if(curr == curr->parent->right){
	curr = curr->parent;
	leftRot(curr, root);
      }

      if(curr->parent->color != RED) break;
      //case 3 
      curr->parent->color = BLACK;
      curr->parent->parent->color = RED;
      rightRot(curr->parent, root);
      
    } else {
      if(curr->parent->parent->left->color == RED){
	curr->parent->parent->left->color  = BLACK;
	curr->parent->parent->right->color  = BLACK;
	curr->parent->parent->color = RED;

	curr = curr->parent->parent;
      } else if(curr == curr->parent->left){
	curr = curr->parent;
	rightRot(curr, root);

	curr->parent->color = BLACK;
	curr->parent->parent->color = RED;
	leftRot(curr->parent->parent, root);
      }
      
    }
  }
   root->color = BLACK;
}


void add(Node* &root, int val){
  if(root == NULL){
    root = new Node(NULL, NULL, NULL, val, BLACK);
    return;
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

    fixTree(prev, n);

    
    
  }
}

//print 
void print(Node* curr, int depth){
  //if at end of link then return
  if(curr == NULL) return;
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
