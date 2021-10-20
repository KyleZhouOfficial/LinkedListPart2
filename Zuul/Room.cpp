/*
Kyle Zhou
10/20/21
Implementation for Room Class
 */
#include "Room.h"
#include <cstring>
#include <map>
#include <vector>
#include <iostream>
#include <iomanip>
#include "Item.h"

using namespace std;

//blank constructor
Room::Room(){
  
}

//constructor
Room::Room(char descrip[80]){
  strcpy(description, descrip);
}
//destructor
Room::~Room(){

}

//setting exit (char exit[80] is the direction) to a room pointer
void Room::setExit(char exit[80], Room* next){
  exits[exit] = next;
}

//gets exit given the direction
Room* Room::getExit(char direc[80]){
  //iterate through exits
  for(map<char*, Room*>::iterator it = exits.begin(); it != exits.end(); it++){
    //if the direction is the same return room pointer
    if(strcmp(it->first, direc) == 0){
      return it->second;
    }
  }
}
//gets description of the room
char* Room::getDescrip(){
  return description;
}
//description of the rooms exits and items
void Room::getExitString(){
  cout << "Exits:";
  //iterate through exits and print out directions
  for(map<char*, Room*>::iterator it = exits.begin(); it != exits.end(); it++){
    cout << " " << it->first;
  }
  cout << endl;
  //prints out room items
  cout << "Items in the room:" << endl;
  getRoomItems();
}

//gets item given its name
Item Room::getItem(char itemName[80]){
  for(vector<Item>::iterator it = items.begin(); it!= items.end(); it++){
    //goes through the vector of items for the room
    //if it is the item then return
    if(strcmp(it->getDescription(), itemName) == 0){
      return (*it);
    }
  }
}
//remove Item in room
void Room::removeItem(char itemName[80]){
  //go through items and delete the correct item
  for(vector<Item>::iterator it= items.begin(); it!= items.end(); it++){
    if(strcmp(itemName, it->getDescription()) == 0){
      items.erase(it);
      break;
    }
  }
}

//add item to vector
void Room::setItem(Item newItem){
  items.push_back(newItem);
}

//prints out the items in vector
void Room::getRoomItems(){
  for(vector<Item>::iterator it= items.begin(); it != items.end(); it++){
    cout << it->getDescription() << " ";
  }
  cout << endl;
}
