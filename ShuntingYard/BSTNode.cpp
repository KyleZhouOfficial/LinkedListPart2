/*
By: Kyle Z
1/14/21
Implementation for expression tree node
 */
#include "BSTNode.h"
#include <iostream>
using namespace std;

//constructors and destructors
BSTNode::BSTNode(){
  left = NULL;
  right = NULL;
}

BSTNode::BSTNode(char val){
  data = val;
  left = NULL;
  right = NULL;
}

BSTNode::~BSTNode(){
  left = nullptr;
  right = nullptr;
}

//getters and setters
void BSTNode::setData(char val){
  data = val;
}

void BSTNode::setLeft(char val){
  left = new BSTNode(val);
}

void BSTNode::setRight(char val){
  right = new BSTNode(val);
}

void BSTNode::setRight(BSTNode* val){
  right = val;
}

void BSTNode::setLeft(BSTNode* val){
  left = val;
}

char BSTNode::getData(){
  return data;
}

BSTNode* BSTNode::getRight(){
  return right;
}

BSTNode* BSTNode::getLeft(){
  return left;
}
