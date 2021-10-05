/*
Kyle Zhou
10/5/21
Definition for Videogames class
 */
//header guards
#ifndef __Videogames_H__
#define __Videogames_H__
#include <cstring>
#include "Media.h"

using namespace std;
//extend parent
class Videogames: public Media{
 private:
  //fields
  char publisher[80];
  int rating;

 public:
  //constructor and destructor
  Videogames(char* titleVal, int yearVal, int ratingVal, char* publisherVal);
  ~Videogames();
  //getters
  char* getPublisher();
  int getRating();
  virtual int getType();
};

#endif
