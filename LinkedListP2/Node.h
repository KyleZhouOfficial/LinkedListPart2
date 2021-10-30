/*
Kyle Zhou
10/26/21
Definition for Node Class
 */

//header guards
#ifndef _NODE_H_
#define _NODE_H_

#include "Student.h"
#include <cstring>

using namespace std;

class Node{
 private:
  //student and next Node pointer
  Student* student;
  Node* next;
 public:
  //constructors and destructor
  Node();
  Node(Student* s);
  ~Node();
  //getters and setters
  Node* getNext();
  Student* getStudent();
  void setNext(Node* node);
};
#endif
