/*
By: Kyle Zhou
12/17/21
This program declares the node class
 */
#ifndef _NODE_H_
#define _NODE_H_


using namespace std;


class Node{
  //left and right nodes
 private:
  Node* left;
  Node* right;
  //data value
  int data;
 public:
  //constuctors and destructors
  Node();
  Node(int val);
  ~Node();
  //setters and getters
  void setData(int val);
  void setLeft(int val);
  void setRight(int val);
  void setRight(Node* val);
  void setLeft(Node* val);
  int getData();
  Node* getRight();
  Node* getLeft();
};

#endif
