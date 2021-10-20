/*
Kyle Zhou
Implementation for Item class
10/20/21
 */
#include "Item.h"
#include <cstring>

using namespace std;
//constructors
Item::Item(){

}

Item::Item(char descrip[80]){
  strcpy(description, descrip);
}

//getter
char* Item::getDescription(){
  return description;
}
