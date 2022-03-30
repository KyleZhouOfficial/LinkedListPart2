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
  bool isLeaf;

  Node(Node* p);
  Node(Node* p, Node* l, Node* r, int k, int c, bool le);
  ~Node();
};

#endif
