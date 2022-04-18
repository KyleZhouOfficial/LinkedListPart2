/*
Red black tree with insertion, deletion, search, print, and read
By: Kyle Zhou
3/30/22
 */

#include <cstring>
#include <iostream>
#include <fstream>
#include "Node.h"

using namespace std;

//constants for red and black
const int RED = 1;
const int BLACK  = 0;

//right rotate
void rightRot(Node* curr, Node* & root){
  
  Node* temp = curr->left;
   //shift the child over to the other side
  curr->left = temp->right;

  if(temp->right->isLeaf != false){
    temp->right->parent = curr;
  }
    //change parent
  temp->parent = curr->parent;

    //if need to reassign root
  if(curr->parent == NULL){
    root=temp;
  } else if(curr == curr->parent->left){
    curr->parent->left = temp;
  } else{
    curr->parent->right = temp;
  }
  //reassign parent and child
  temp->right = curr;
  curr->parent = temp;
}

//left rotate
void leftRot(Node* curr, Node* &root){
  
  Node* temp = curr->right;
  //shift the child over to the other side
  curr->right = temp->left;
  
  if(temp->left->isLeaf != false){
    temp->left->parent = curr;
  }
  //change parent
  temp->parent = curr->parent;

  //if need to reassign root
  if(curr->parent == NULL){
    root=temp;
  } else if(curr == curr->parent->left){
    curr->parent->left = temp;
  } else{
    curr->parent->right = temp;
  }
  //reassign parent and child
  temp->left = curr;
  curr->parent = temp;
}

//insertion fix tree
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
    } else{ //same cases just reversed
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

     
     

//add node
void add(Node* &root, int val){
  //node to add
  Node* add = new Node(NULL, NULL, NULL, val, RED, false);
  //make children null nodes
  add->left = new Node(add);
  add->right = new Node(add);
  //if tree empty
  if(root == NULL){
    add->color = BLACK;
    root = add;
    return;
  } else{
    //find place to add
    Node* prev = NULL;
    Node* temp = root;
    while(temp != NULL && !temp->isLeaf){
      prev = temp;
      if(val > temp->key){
	temp = temp->right;
      } else {
	temp = temp->left;
      }

    }
    //assign parent to the previous node
    add->parent = prev;

    //add to left or right of previous node
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
    //call fix
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
  cout << curr->key;
  if(curr->color == BLACK){
    cout << "B";
  } else{
    cout << "R";
  }
  if(curr->parent != NULL){
    cout << curr->parent->key;
  }
  cout << endl;
  //go left 
  print(curr->left, depth+1);
}

//move node v into u
void move(Node* u, Node* v, Node* &root){
  //if u is root then v is now root
  if(u->parent == NULL){
    root = v;
  } else if(u == u->parent->left){ //reassign parents pointer
    u->parent->left = v;
  } else{
     u->parent->right = v;
  }
  //assign parent for v
  v->parent = u->parent;
}

//find minimum node in a subtree
Node* min(Node* curr){
  while(!curr->left->isLeaf){
    curr = curr->left;
  }
  return curr;
}


//fix a double black or redblack
void fixdouble(Node* &v, Node *&root){
  while(v != root && v->color == BLACK){
    Node* sib;
    //assign sibling
    if(v == v->parent->left){
      sib = v->parent->right;
      //case 1 if sibling is red swap colors of sibling and parent
      if(sib->color == RED){
	v->parent->right->color = BLACK;
	v->parent->color = RED;
	//left rotate
	leftRot(v->parent, root);
	sib = v->parent->right;
      }

      //case 2
      if(sib->right->color == BLACK && sib->left->color == BLACK){
	sib->color = RED;
	v = v->parent;
      } else{
	if(sib->right->color == BLACK){ //case 3
	  sib->left->color = BLACK;
	  sib->color = RED;
	  rightRot(sib, root);
	  sib = v->parent->right;
	}
	//case 4
	sib->color = v->parent->color;
	v->parent->color = BLACK;
	sib->right->color = BLACK;
	leftRot(v->parent, root);
	v = root;
      }
    } else{ //same cases just reversed
      sib = v->parent->left;

      if(sib->color == RED){
	v->parent->left->color = BLACK;
	v->parent->color = RED;
	rightRot(v->parent, root);
	sib = v->parent->left;
      }

      if(sib->left->color == BLACK && sib->right->color == BLACK){
	sib->color = RED;
        v = v->parent;
      } else{
	if(sib->left->color == BLACK){
	  sib->right->color = BLACK;
	  sib->color = RED;
	  leftRot(sib, root);
	  sib = v->parent->left;
	}

	sib->color = v->parent->color;
	v->parent->color = BLACK;
	sib->left->color = BLACK;
	rightRot(v->parent, root);
	v = root;
      }
    }
   
  }
   v->color = BLACK; 
}

//search function
bool searchTree(Node* root, int val){
  Node* temp = root;
  //find node to delete
  while(!temp->isLeaf){
    if(temp->key == val){
      return true;
    }
      if(val > temp->key){
	temp = temp->right;
      } else {
	temp = temp->left;
      }
  }
  return false;
}

//delete
void del(Node* &root, int val){
  if(root == NULL) return;
  if(root != NULL && root->left->isLeaf && root->right->isLeaf){
    delete root;
    root = NULL;
    return;
  }
  Node* temp = root;
  //find node to delete
  while(!temp->isLeaf){
    if(temp->key == val){
      break;
    }
      if(val > temp->key){
	temp = temp->right;
      } else {
	temp = temp->left;
      }
  }

  //original color of node deleted
  int orgcolor = temp->color;

  Node* x;
  Node* y;
  //if left is null then move the right child and delete temp;
  if(temp->left->isLeaf){
    x = temp->right;
    move(temp, x, root);
    //if right is null
  } else if(temp->right->isLeaf){
    x = temp->left;
    move(temp, x, root);
  } else{ // has two children find successor
    y = min(temp->right);
    orgcolor = y->color;
    //replace temp with y and adjust pointers
    x = y->right;
    if(y->parent == temp){
      x->parent = y;
    } else{
      move(y, y->right, root);
      y->right = temp->right;
      y->right->parent = y;
    }
    move(temp, y, root);
    y->left = temp->left;
    y->left->parent = y;
    y->color = temp->color;
  }
  delete temp;
  //if node deleted was black then creates a double black or black-red
  if(orgcolor == BLACK){
    fixdouble(x, root);
  }
}
 

int main(){
  Node* root = NULL;

  char input[10];
  while(true){
    cout << "Enter ADD, READ, QUIT, DELETE, SEARCH or PRINT" << endl;
    cin >> input;
    //add
    if(strcmp(input, "ADD") == 0){
      int val;
      cout << "What number to add: " << endl;
      cin >> val;
      add(root, val);
    } else if(strcmp(input, "READ")== 0){ //read
      ifstream myfile("num.txt");
      int num;
      while(myfile >> num){
	add(root, num);
      }
      myfile.close();
    } else if(strcmp(input, "DELETE")== 0){ //delete
      int val;
      cout << "What number to delete: " << endl;
      cin >> val;
      del(root, val);
    } else if(strcmp(input, "PRINT") == 0){ // print
      cout << "Each Node shows: Key, Color, and Parent" << endl;
      int depth = 0;
      print(root, depth);
    } else if(strcmp(input, "SEARCH") == 0){ //search
      int val;
      cout << "What number to search for: " << endl;
      cin >> val;
      bool t = searchTree(root, val);
      if(t) cout << val << " is in the tree" << endl;
      else cout << val << " is NOT in the tree" << endl;
    } else{
      break;
    }
  }	
		

}
