#ifndef _ROOM_H_
#define _ROOM_H_
#include <cstring>
#include <map>
#include <vector>
#include "Item.h"

using namespace std;

class Room{
 private:
  map<char*, Room> exits;
  vector<Item> items;
  char description[80];
  
 public:
  Room(char descrip[80]);
  ~Room();
  void setExit(char exit[80], Room next);
  char* getDescrip();
  void getExitString();
  Item getItem(char itemName[80]);
  void removeItem(char itemName[80]);
  void setItem(Item newItem);
  void getRoomItems();
};





#endif
