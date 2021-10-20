/*
Kyle Zhou
Definition for Item class
10/20/21
 */

//header guards
#ifndef _ITEM_H_
#define _ITEM_H_

#include <cstring>

using namespace std;

class Item{
 private:
  //description of item
  char description[80];

 public:
  //constructor and getter
  Item();
  Item(char descrip[80]);
  char* getDescription();
};

#endif
