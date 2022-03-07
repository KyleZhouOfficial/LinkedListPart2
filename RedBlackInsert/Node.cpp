#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(Node* p){
  parent = p;
  left = NULL;
  right = NULL;
  isLeaf = true;
  key = 0;
  color = 0;
}

Node::Node(Node* p, Node* l, Node* r, int k , int c, bool le){
  parent = p;
  left = l;
  right = r;
  key = k;
  color = c;
  isLeaf = le;
}

Node::~Node(){
  parent = NULL;
  left = NULL;
  right = NULL;
}
