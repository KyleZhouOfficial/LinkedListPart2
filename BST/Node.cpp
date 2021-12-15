#include "Node.h"
#include <iostream>
using namespace std;

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
