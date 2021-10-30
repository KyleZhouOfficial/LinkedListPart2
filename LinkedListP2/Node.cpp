#include "Node.h"

#include <cstring>
#include <iostream>

using namespace std;

Node::Node(){

}

Node::Node(Student* s){
  student = new Student();
  student->setGpa(s->getGpa());
  student->setID(s->getId());
  student->setFirst(s->getFirst());
  student->setLast(s->getLast());
  next = NULL;
}

Node::~Node(){
  delete student;
  next = NULL;
}

Student* Node::getStudent(){
  return student;
}

Node* Node::getNext(){
  return next;
}

void Node::setNext(Node* node){
  next = node;
}
