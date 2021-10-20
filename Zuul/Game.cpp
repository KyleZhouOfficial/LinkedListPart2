#include "Room.h"
#include "Item.h"
/*
Kyle Zhou
The main class for the Zuul Game
10/20/21
 */
#include <map>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;
//prototypes
bool processCommand(char firstWord[80], char secondWord[80], Room* &currRoom);
void printHelp();
void go(char secondWord[80], Room* &currRoom);

//prints out instructions
void printHelp(){
  cout << "You are lost. You are alone. You wander around at the university"
       << endl;

  cout << "Collect all of the infinity stones in this order to become Thanos: " << endl;
  cout << "MindStone" << endl;
  cout << "PowerStone" << endl;
  cout << "SpaceStone" << endl;
  cout << "RealityStone" << endl;
  cout << "TimeStone" << endl;
  cout << "Your command words are: go, quit, help, inventory, get, drop" << endl;
}

//go command
void go(char secondWord[80], Room* &currRoom){
  //sets next room to the correct direction
  Room* nextRoom = currRoom->getExit(secondWord);
  //sets currRoom to the nextRoom
  currRoom = nextRoom;
  //prints out description
  cout << "You are " << currRoom->getDescrip() << endl;
  //prints out exits
  currRoom->getExitString();
}

//win condition check
bool isInOrder(vector<Item> &inventory){
  //if inventory is correct size and items are in the correct order
  if(inventory.size() == 5){
    if(!strcmp(inventory[0].getDescription(), "MindStone") &&
       !strcmp(inventory[1].getDescription(), "PowerStone") &&
       !strcmp(inventory[2].getDescription(), "SpaceStone") &&
       !strcmp(inventory[3].getDescription(), "RealityStone") &&
       !strcmp(inventory[4].getDescription(), "TimeStone")){
      return true;
    }
  }
  return false;
}

//pick up item
bool getItem(char secondWord[80], Room* currRoom, vector<Item> &inventory){  
  //setItem to the item in the room
  Item newItem = currRoom->getItem(secondWord);
  //add this item to the inventory
  inventory.push_back(newItem);
  //remove the item from the room
  currRoom->removeItem(secondWord);
  //print out status
  cout << "Picked up " << secondWord << endl;
  //if win condition is true print out message and return to end the game
  if(isInOrder(inventory)){
    cout << "You have become Thanos. You win!" << endl;
    return true;
  }
  return false;
}

//print inventory
void printInventory(vector<Item> &inventory){
  cout << "You are carrying:" << endl;
  //go through inventory and print out each item
  for(vector<Item>::iterator it = inventory.begin(); it != inventory.end(); it++){
    cout << it->getDescription() << " ";
  }
  cout << endl;
}

//drop item
void dropItem(char secondWord[80], Room* currRoom, vector<Item> &inventory){
  Item newItem;
  //iterate through inventory
  for(vector<Item>::iterator it = inventory.begin(); it != inventory.end(); it++){
    if(strcmp(it->getDescription(),secondWord) == 0){
      //set newItem to item in inventory
      newItem = (*it);
      //erase item from inventory
      inventory.erase(it);
      //add newItem to the room
      currRoom->setItem(newItem);
      cout << "Dropped: " << secondWord << endl;
      return;
    }
  }
}

//proccess the command
bool processCommand(char firstWord[80], char secondWord[80], Room* &currRoom, vector<Item> &inventory){
  //variable if player wants to quit
  bool wantToQuit = false;
  //if command is help
  if(strcmp(firstWord, "help") == 0){
    printHelp();
  } else if(strcmp(firstWord, "go") == 0){ // go command
    go(secondWord, currRoom);
  } else if(strcmp(firstWord, "quit") == 0){ // quit
    wantToQuit = true;
  } else if(strcmp(firstWord, "inventory") == 0){ //inventory
    printInventory(inventory);
  } else if(strcmp(firstWord, "get") == 0){//get item
    wantToQuit = getItem(secondWord, currRoom, inventory);
  } else if(strcmp(firstWord, "drop") == 0){//drop item
    dropItem(secondWord, currRoom, inventory);
  }
  return wantToQuit;
}

//main
int main(){
  //vector that stores rooms
  //create rooms and set descriptions
  vector<Room*> rooms;
  Room* outside = new Room("outside the main entrance of the university");
  rooms.push_back(outside);
  Room* theatre = new Room("in a lecture theatre");
  rooms.push_back(theatre);
  Room* pub = new Room("in the campus pub");
  rooms.push_back(pub);
  Room* lab = new Room("in a computing lab");
  rooms.push_back(lab);
  Room* office = new Room("in the computing admin office");
  rooms.push_back(office);
  Room* onetwenty = new Room("in the coolest place in the world");
  rooms.push_back(onetwenty);
  Room* gym = new Room("in the gym");
  rooms.push_back(gym);
  Room* library = new Room("in the library");
  rooms.push_back(library);
  Room* bathroom = new Room("in the bathroom");
  rooms.push_back(bathroom);
  Room* pool = new Room("in the pool");
  rooms.push_back(pool);
  Room* dorm = new Room("in your dorm");
  rooms.push_back(dorm);
  Room* park = new Room("in the university park");
  rooms.push_back(park);
  Room* studyhall = new Room("in the study hall");
  rooms.push_back(studyhall);
  Room* bandRoom = new Room("in the band room");
  rooms.push_back(bandRoom);
  Room* cafeteria = new Room("in the cafeteria");
  rooms.push_back(cafeteria);

  //set exits
  outside->setExit("east", theatre);
  outside->setExit("south", lab);
  outside->setExit("west", pub);
  outside->setExit("north", park);

  theatre->setExit("west", outside);
  theatre->setExit("north", bandRoom);

  library->setExit("west", lab);
  library->setExit("east", studyhall);

  studyhall->setExit("west", library);

  bandRoom->setExit("south", theatre);

  dorm->setExit("south", pub);
  dorm->setExit("west", bathroom);

  bathroom->setExit("east", dorm);

  park->setExit("west", cafeteria);
  park->setExit("north", gym);
  park->setExit("south", outside);

  cafeteria->setExit("east", park);

  gym->setExit("south", park);
  gym->setExit("east", pool);

  pub->setExit("east", outside);
  pub->setExit("north", dorm);
  pub->setExit("east", outside);

  lab->setExit("north", outside);
  lab->setExit("west", office);
  lab->setExit("east", library);
  lab->setExit("south", onetwenty);

  pool->setExit("west", gym);

  office->setExit("east", lab);

  onetwenty->setExit("north", lab);

  //current room pointer will be what room the user is currently in
  Room* currentRoom = outside;

  //add items to rooms
  Item a("MindStone");
  theatre->setItem(a);
  Item b("TimeStone");
  onetwenty->setItem(b);
  Item c("RealityStone");
  pub->setItem(c);
  Item d("PowerStone");
  cafeteria->setItem(d);
  Item e("SpaceStone");
  pool->setItem(e);

  //print out welcome
  cout << "Welcome to Zuul" << endl;
  cout << "Collect all of the infinity stones in this order to become Thanos: " << endl;
  cout << "MindStone" << endl;
  cout << "PowerStone" << endl;
  cout << "SpaceStone" << endl;
  cout << "RealityStone" << endl;
  cout << "TimeStone" << endl;
  cout << "Type 'help' if you need help" << endl;

  cout << "You are " << currentRoom->getDescrip();
  cout << endl;
  currentRoom->getExitString();
  //inventory will hold items 
  vector<Item> inventory;
  //keep playing variable
  bool finished = false;
  //while user still wants to play
  while(!finished){
    //first command and second command
    char command1[80];
    char command2[80];
    
    cout << "> ";
	    
    cin >> command1; //get first command
    //if the first command doesnt need a second command then add something random
    if(strcmp(command1, "help") == 0 || strcmp(command1, "inventory") == 0 ||
       strcmp(command1, "quit") == 0){
      strcpy(command2,"a");
    } else{
      //else input second command
      cin >> command2;
    }
    //proccess the command and update if user still wants to play
    finished = processCommand(command1, command2, currentRoom, inventory);

  }
  
  return 0;
}
