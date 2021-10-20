/*
Kyle Zhou
Definition for Room class
10/20/21
 */
//header guard
#ifndef _ROOM_H_
#define _ROOM_H_
#include <cstring>
#include <map>
#include <vector>
#include "Item.h"

using namespace std;

class Room{
 private:
  //map for exits
  map<char*, Room*> exits;
  //vector for items
  vector<Item> items;
  //description of the room
  char description[80];
  
 public:
  //constructors and destructor
  Room();
  Room(char descrip[80]);
  ~Room();
  //other functions
  Room* getExit(char direc[80]);
  void setExit(char exit[80], Room* next);
  char* getDescrip();
  void getExitString();
  Item getItem(char itemName[80]);
  void removeItem(char itemName[80]);
  void setItem(Item newItem);
  void getRoomItems();
};





#endif
