/*
Kyle Zhou
10/5/21
Implementation for Media class
 */
#include "Media.h"
//constructor
Media::Media(char* titleVal, int yearVal): year(yearVal){
  strcpy(title, titleVal);
}
//getting a type
int Media::getType(){
  return 0;
}

//getters
char* Media::getTitle(){
  return title;
}

int Media::getYear(){
  return year;
}
//destructor
Media::~Media(){

}
