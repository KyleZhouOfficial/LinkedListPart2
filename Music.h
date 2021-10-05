/*
Kyle Zhou
10/5/21
Definition of Music class
 */
#ifndef __MUSIC_H__
#define __MUSIC_H__
#include "Media.h"
#include <cstring>

using namespace std;
//extend parent class
class Music : public Media{
 private:
  //fields
  char artist[80];
  int duration;
  char publisher[80];
 public:
  //constructor and destructor
  Music(char titleVal[80], int yearVal, char artistVal[80], int durationVal, char publisherVal[80]);
  ~Music();
  //getters
  char* getArtist();
  int getDuration();
  char* getPublisher();
  virtual int getType();
};


#endif
