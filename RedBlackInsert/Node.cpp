#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(){
  
}

Node::Node(Node* p, Node* l, Node* r, int k , int c){
  parent = p;
  left = l;
  right = r;
  key = k;
  color = c;
}

Node::~Node(){
  parent = NULL;
  left = NULL;
  right = NULL;
}
