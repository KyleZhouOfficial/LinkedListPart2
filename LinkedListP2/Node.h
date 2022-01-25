#include "Student.h"

#ifndef NODE_H
#define NODE_H

class Node {
 public:
  //these two are too simple, literally just give you the pointers to the corresponding values btw get certain is 0-indexing
  Student* getStudent();
  Node* getNext();
  Node* getLast();
  Node* getCertain(int pos);
  //appends a Node to end of linked list
  void setNext(Node* n);
  //use this before destroying a Node if you don't want to destroy everything after the Node
  void removeNext();
  //initilizes Nodes with corresponding values
  Node();
  Node(Student* v);
  Node(Node* n);
  Node(Student* v, Node* n);
  //destroys value
  ~Node();
 private:
  Student* val;
  Node* next;
};

#endif
