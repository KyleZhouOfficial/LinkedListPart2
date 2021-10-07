/*
Kyle Zhou
10/5/21
Implementation for Videogames class
 */
#include "Videogames.h"
#include <cstring>


using namespace std;

//constructor
Videogames::Videogames(char titleVal[80], int yearVal, int ratingVal, char publisherVal[80]):
  Media(titleVal, yearVal), rating(ratingVal){
  strcpy(publisher, publisherVal);
}
//getters
int Videogames::getType(){
  return 2;
}
//destructor
Videogames::~Videogames(){

}

char* Videogames::getPublisher(){
  return publisher;
}

int Videogames::getRating(){
  return rating;
}
