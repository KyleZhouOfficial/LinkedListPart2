/*
Kyle Zhou
2/17/22
Binary Search Tree program allows for insertion deletion and input from user/file
*/
#include <iostream>
#include "Node.h"
#include <fstream>
#include <cstring>

using namespace std;

//find a node
bool get(Node* root, int find){
  Node* x = root;
  while(x != NULL){
    if(x->getData() < find) x = x->getRight();
    else if(x->getData() > find) x = x->getLeft();
    else  return true;
  }
  return false;
}

Node* insert(Node* curr, int data){
  //if reach null link then insert 
  if(curr == NULL) return new Node(data);
  //if the current node is less than data then go right
  if(curr->getData() < data) curr->setRight(insert(curr->getRight(), data));
  //go left
  if(curr->getData() >= data) curr->setLeft(insert(curr->getLeft(), data));
  //return current node to reset links
  return curr;
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
Node* deleteMin(Node* curr){
  //if left link is null then delete current node and reset link
  if(curr->getLeft() == NULL){
    delete curr;
    return curr->getRight();
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
Node* deleteNode(Node* curr, int data){
  // if cant find node then return null
  if(curr == NULL) return NULL;
  // traverse tree
  if(curr->getData() < data) curr->setRight(deleteNode(curr->getRight(), data));
  else if(curr->getData() > data) curr->setLeft(deleteNode(curr->getLeft(), data));
  //if found node to delete
  else{
    //if right is null then reset link with left
    if(curr->getRight() == NULL) return curr->getLeft();
    //if left is null then reset link with right
    if(curr->getLeft() == NULL) return curr->getRight();

    //case if both children are not NULL
    //get current node
    //set curr to minimum node in right subtree
    Node* a = new Node(min(curr->getRight())->getData());
    curr->setData(a->getData());
    //set the right to right subtree after deleting the minimum
    curr->setRight(deleteMin(curr->getRight()));
   
  }
  return curr;
}

int main(){
  
  cout << "To read input from user type USER or FILE for file input" << endl;
  char input[10];
  //head pointer
  Node* head = NULL;
  cin >> input;
  //if is file input
  if(strcmp(input, "FILE") == 0){
    //open file
    ifstream myfile("num.txt");
    //read until end of file
    int num;
    while(myfile >> num){
      head = insert(head, num);
    }
    myfile.close();
  }
  
  while(true) {
    cout << "Enter INSERT, DELETE, PRINT, QUIT, or SEARCH" << endl;
    char command[10];
    cin >> command;
    //insert
    if(strcmp(command, "INSERT") == 0){
      cout << "Please enter a number" << endl;
      int data;
      cin >> data;
      head = insert(head, data);
      //delete
    } else if(strcmp(command, "DELETE") == 0){
      cout << "Please enter a number" << endl;
      int data;
      cin >> data;
      head = deleteNode(head, data);
      //print
    } else if(strcmp(command, "PRINT") == 0){
      int depth = 0;
      dfs(head, depth);
      //search
    } else if(strcmp(command, "SEARCH" ) == 0){
      cout << "Please enter a number" << endl;
      int data;
      cin >> data;
      if(get(head, data)) cout << data << " is in the tree" << endl;
      else  cout << data << " is NOT in the tree" << endl;
    } else{
      break; //quit
    }
    
  }
}
