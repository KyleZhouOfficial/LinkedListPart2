#include <iostream>
#include "Node.h"

using namespace std;

//find a node
bool get(Node* root, int find){
  Node* x = root;
  while(x != NULL){
    if(x->getData() < find) x = x->getRight();
    if(x->getData() > find) x = x->getLeft();
    if(x->getData() == find) return true;
  }
  return false;
}

Node* insert(Node* &curr, int data){
  //if reach null link then insert 
  if(curr == NULL) return new Node(data);
  //if the current node is less than data then go right
  if(curr->getData() < data) curr->setRight(insert(curr->getRight(), data));
  //go left
  if(curr->getData() >= data) curr->setLeft(insert(curr->getLeft(), data));
  //return current node to reset links
  return x;
}

//print 
void dfs(Node* curr, int depth){
  //if at end of link then return
  if(curr == NULL) return;
  //go right and increase depth
  dfs(curr->getRight(), depth+1);
  //print out spaces equal to depth
  for(int i = 0; i < depth; i++) cout << " ";
  //print out current node
  cout << curr->getData() << endl;
  //go left 
  dfs(curr->getLeft(), depth+1);
}

//delete minimum
Node* deleteMin(Node* &curr){
  //if left link is null then delete current node and reset link
  if(curr->getLeft() == NULL){
    delete curr;
    return curr->getRigh();
  }
  //reset links
  curr->setLeft(deleteMin(curr->getLeft()));
  return curr;
}

//find minimum node
Node* min(Node* curr){
  //go left until it is null
  if(curr == NULL) return NULL;
  while(curr->getLeft() != NULL){
    curr = curr->getLeft();
  }
  return curr;
  
}

//delete function
Node* delete(Node* &curr, int data){
  // if cant find node then return null
  if(curr == NULL) return NULL;
  // traverse tree
  if(curr->getData() < data) curr->setRight(delete(curr->getRight(), data));
  else if(curr->getData() >= data) curr->setLeft(delete(curr->getLeft(), data));
  //if found node to delete
  else{
    //if right is null then reset link with left
    if(curr->getRight() == NULL) return curr->getLeft();
    //if left is null then reset link with right
    if(curr->getLeft() == NULL) return curr->getRight();

    //case if both children are not NULL
    //get current node
    Node* &t = curr;
    //set curr to minimum node in right subtree
    Node* curr = new Node(min(curr->getRight())->getData());
    //set the right to right subtree after deleting the minimum
    curr->setRight(deleteMin(t.right));
    //set the left to original nodes left
    curr-setLeft(t->getLeft());
    delete t;
  }
  return curr;
}

int main(){
  cout << "To read input from user type USER or FILE for file input" << endl;
  char input[10];
  cin >> input;
  if(strcmp(input, "USER")){
    
  } else if(strcmp(input, "FILE")){

  }
}
