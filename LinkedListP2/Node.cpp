#include "Student.h"
#include "Node.h"
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

Student* Node::getStudent() {
  return val;
}

Node* Node::getNext() {
  return next;
}

Node* Node::getLast() {
  if (next==NULL) {
      return this;
    }
  return next->getLast();
}

Node* Node::getCertain(int pos) {
  if ((pos==0)||(next==NULL)) {
    return this;
  }
  return next->getCertain(pos-1);
}

void Node::setNext(Node* n) {
  next = n;
}

void Node::removeNext() {
  next = NULL;
}

Node::Node() {
  next = NULL;
}

Node::Node(Student* v) {
  val = v;
  next = NULL;
}

Node::Node(Node* n) {
  next = n;
}

Node::Node(Student* v, Node* n) {
  val = v;
  next = n;
}

Node::~Node() {
  delete val;
}
