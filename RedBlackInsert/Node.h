#ifndef _NODE_H_
#define _NODE_H_

using namespace std;

class Node{
 public:
  Node* parent;
  Node* left;
  Node* right;
  int key;
  int color;

  Node();
  ~Node();
}
