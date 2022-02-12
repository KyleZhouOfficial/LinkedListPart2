/*
By: Kyle Z
12/17/21
This is the implementation for the Node class
 */
#include "Node.h"
#include <iostream>
#include <cstring>
using namespace std;

//constructors and destructors
Node::Node(){
  left = NULL;
  right = NULL;
}

Node::Node(int val){
  data = val;
  left = NULL;
  right = NULL;
}

Node::~Node(){
  left = nullptr;
  right = nullptr;
}

//getters and setters
void Node::setData(int val){
  data = val;
}

void Node::setLeft(int val){
  left = new Node(val);
}

void Node::setRight(int val){
  right = new Node(val);
}

void Node::setRight(Node* val){
  right = val;
}

void Node::setLeft(Node* val){
  left = val;
}

int Node::getData(){
  return data;
}

Node* Node::getRight(){
  return right;
}

Node* Node::getLeft(){
  return left;
}
