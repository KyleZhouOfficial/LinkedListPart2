/*
Kyle Zhou
10/5/21
definition for Movies class
 */
//header guards
#ifndef __MOVIES_H__
#define __MOVIES_H__
#include "Media.h"
#include <cstring>

using namespace std;

//extends Media class
class Movies: public Media{
 private:
  //fields
  char director[80];
  int duration;
  int rating;
 public:
  //constructor destructor
  Movies(char titleVal[80], int yearVal, char directorVal[80], int durationVal, int ratingVal);
  ~Movies();
  //getters
  char* getDirector();
  int getDuration();
  int getRating();
  virtual int getType();
};






#endif 
