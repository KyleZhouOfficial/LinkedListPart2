/*
Kyle Zhou
10/5/21
Implementation for Movies class
 */
#include "Movies.h"
#include <cstring>

using namespace std;

//constructor
Movies::Movies(char titleVal[80], int yearVal, char directorVal[80], int durationVal, int ratingVal): Media(titleVal, yearVal), duration(durationVal), rating(ratingVal){
    strcpy(director, directorVal);
}

//destructor
Movies::~Movies(){

}
//getters
 int Movies::getType(){
  return 1;
}

char* Movies::getDirector(){
  return director;
}

int Movies::getDuration(){
  return duration;
}

int Movies::getRating(){
  return rating;
}
