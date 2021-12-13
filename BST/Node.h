#ifndef _NODE_H_
#define _NODE_H_


using namespace std;


class Node{
 private:
  Node* left;
  Node* right;
  int data;
 public:
  Node();
  Node(int val);
  ~Node();
  void setData(int val);
  void setLeft(int val);
  void setRight(int val);
  int getData();
  Node* getRight();
  Node* getLeft();
};

#endif
