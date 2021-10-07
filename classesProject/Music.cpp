/*
Kyle Zhou
10/5/21
Implementation of Music class
 */
#include "Music.h"
#include <cstring>

using namespace std;

//constructor
Music::Music(char titleVal[80], int yearVal, char artistVal[80], int durationVal, char publisherVal[80]): Media(titleVal, yearVal), duration(durationVal){
    strcpy(publisher,publisherVal);
    strcpy(artist,artistVal);
}

//getters
int Music::getType(){
  return 3;
}
//destructor
Music::~Music(){

}

char* Music::getArtist(){
  return artist;
}

int Music::getDuration(){
  return duration;
}

char* Music::getPublisher(){
  return publisher;
}
