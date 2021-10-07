/*
Kyle Zhou
10/5/21
definition for Media class
 */
//header guards
#ifndef __MEDIA_H__
#define __MEDIA_H__

#include <cstring>

using namespace std;

class Media{
  //fields
 private:
  char title[80];
  int year;
  //functions
 public:
  //constructor and destructor
  Media(char titleVal[80], int yearVal);
  ~Media();
  //getters
  char* getTitle();
  int getYear();
  //get type
  virtual int getType();
};


#endif
