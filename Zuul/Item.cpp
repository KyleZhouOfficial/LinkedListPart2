#include "Item.h"
#include <cstring>

using namespace std;

Item::Item(char descrip[80]){
  strcpy(description, descrip);
}

char* Item::getDescription(){
  return description;
}
