/*
Name: Kyle Zhou
Date: 10/5/21
This is the main class which allows you to ADD SUBTRACT and DELETE Videogames, Music and Movies
 */
#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include "Music.h"
#include "Movies.h"
#include "Videogames.h"
#include "Media.h"

using namespace std;

void ADD(vector<Media*> &list);
void SEARCH(vector<Media*> list);

//Adding media
void ADD(vector<Media*> &list){
  //prompt user
  cout << "Would you like to add a Music, Videogame, or Movie?" << endl;
  char type[80];
  cin >> type;
  //ask for title and year
  char tit[80];
  cout << "Please enter the title" << endl;
  cin >> tit;
  int year;
  cout << "Please enter the year" << endl;
  cin >> year;
  //if adding Movie
  if(strcmp(type, "Movie")==0){
    //get input
    cout << "Please enter the director" << endl;
    char dir[80];
    cin >> dir;
    int duration;
    cout << "Please enter the duration" << endl;				
    cin >> duration;
    int rating;
    cout << "Please enter the rating" << endl;
    cin >> rating;
    //add the movie to the vector
    Media *toAdd = new Movies(tit, year, dir, duration, rating);
    (list).push_back(toAdd);
  } if(strcmp(type, "Videogame") == 0){
    char publisher[80];
    int rating;
    cout << "Please enter publisher" << endl;
    cin >> publisher;
    cout << "Please enter rating" << endl;
    cin >> rating;
    Media *toAdd = new Videogames(tit, year, rating, publisher);
    list.push_back(toAdd);
  } if(strcmp(type, "Music") == 0){
    char artist[80];
    char publisher[80];
    int duration;
    cout << "Please enter artist" << endl;
    cin >> artist;
    cout << "Please enter publisher" << endl;
    cin >> publisher;
    cout << "Please enter duration" << endl;
    cin >> duration;
    Media toAdd = Music(tit, year, artist, duration, publisher);
  }
}

//Search for media in list
void SEARCH(vector<Media*> list){
  //prompt user
  cout << "Please enter YEAR to search by year or TITLE to search by title" << endl;
  char in[80];
  cin >> in;
  if(strcmp(in, "YEAR") == 0){
    cout << "Enter year: " << endl;
    int yearVal;
    cin >> yearVal;
    //iterate through list
   for (vector<Media*>::iterator it = list.begin(); it != list.end(); it++){
     //if year is same
     if((*it)->getYear() == yearVal){
       //if is Movie then print out fields
       if((*it)->getType() == 1){
	 cout << (*it)->getTitle() << " " << (*it)->getYear() << " " << " " << ((Movies*)(*it))->getDirector() << " " << ((Movies*)(*it))->getDuration() << " " << ((Movies*)(*it))->getRating() << endl;
       } else if((*it)->getType() == 2){ //if is Videogames
	 cout << ((Videogames*)(*it))->getTitle() << " " << ((Videogames*)(*it))->getYear() <<
	   " " << ((Videogames*)(*it))->getPublisher() << " " << ((Videogames*)(*it))->getRating() << endl;
       } else if((*it)->getType() == 3){ // if is Music
	 cout << ((Music*)(*it))->getTitle() << " " << ((Music*)(*it))->getYear() <<
	   " " << ((Music*)(*it))->getArtist() << " " << ((Music*)(*it))->getDuration()<< " " << ((Music*)(*it))->getPublisher() << endl;
       }
     }
   }
  } else if(strcmp(in, "TITLE") == 0){ //check by title
    char title[80];
    cout << "Enter title: " << endl;
    cin >> title;
    //iterate
   for (vector<Media*>::iterator it = list.begin(); it!= list.end(); it++){
     if((*it)->getTitle() == title){ //if title is same
       if((*it)->getType() == 1){ //if is Movie
	 cout << ((Movies*)(*it))->getTitle() << " " << ((Movies*)(*it))->getYear() << " "
	      << " " << ((Movies*)(*it))->getDirector() << " " << ((Movies*)(*it))->getDuration() << " " << ((Movies*)(*it))->getRating() << endl;
       } else if((*it)->getType() == 2){ //if is Videogame
	 cout << ((Videogames*)(*it))->getTitle() << " " << ((Videogames*)(*it))->getYear() <<
	   " " << ((Videogames*)(*it))->getPublisher() << " " << ((Videogames*)(*it))->getRating() << endl;
       } else if((*it)->getType() == 3){// if is Music
	 cout << ((Music*)(*it))->getTitle() << " " << ((Music*)(*it))->getYear() <<
	   " " << ((Music*)(*it))->getArtist() << " " << ((Music*)(*it))->getDuration()<< " " << ((Music*)(*it))->getPublisher() << endl;
       }
     }
   }
  }
}

//Delete media in list
void DELETE(vector<Media*> &list){
  cout << "Please enter YEAR to delete by year or TITLE to delete by title" << endl;
  char in[80];
  cin >> in;
  if(strcmp(in, "YEAR") == 0){ //delete by title
    cout << "Enter year: " << endl;
    int yearVal;
    cin >> yearVal;
    //iterate
   for (vector<Media*>::iterator it = list.begin(); it != list.end(); it++){
     if((*it)->getYear() == yearVal){ //if year is same
       if((*it)->getType() == 1){ // if is Movie
	 cout <<"Delete this Movie? (y/n) " <<  (*it)->getTitle() << " " << (*it)->getYear() << " " << " " << ((Movies*)(*it))->getDirector() << " " << ((Movies*)(*it))->getDuration() << " " << ((Movies*)(*it))->getRating() << endl;
	 char isYes[10];
	 cin >> isYes;
	 //confirm to delete
	 if(strcmp(isYes, "y")==0){
	   delete *it;
	   it = list.erase(it);
	   break;
	 }
       } else if((*it)->getType() == 2){ //if is Videogame
	 cout << "Delete this Videogame? (y/n) " << ((Videogames*)(*it))->getTitle() << " " << ((Videogames*)(*it))->getYear() <<
	   " " << ((Videogames*)(*it))->getPublisher() << " " << ((Videogames*)(*it))->getRating() << endl;
	 char isYes[10];
	 cin >> isYes;
	 cout << isYes << endl;
	 if(strcmp(isYes, "y") == 0){
	   delete *it;
	   it = list.erase(it);
	   break;
	 }
       } else if((*it)->getType() == 3){ //if is Music
	 cout <<"Delete this Song? (y/n) " <<  ((Music*)(*it))->getTitle() << " " << ((Music*)(*it))->getYear() <<
	   " " << ((Music*)(*it))->getArtist() << " " << ((Music*)(*it))->getDuration()<< " " << ((Music*)(*it))->getPublisher() << endl;
	 char isYes[10];
	 cin >> isYes;
	 cout << isYes << endl;
	 if(strcmp(isYes, "y")==0){
	   delete *it;
	   it = list.erase(it);
	   break;
	 }
       }
     }
   }
  } else if(strcmp(in, "TITLE") == 0){
    char title[80];
    cout << "Enter title: " << endl;
    cin >> title;
   for (vector<Media*>::iterator it = list.begin(); it!= list.end(); it++){
     if((*it)->getTitle() == title){
       if((*it)->getType() == 1){
	 cout <<"Delete this Movie? (y/n)" << ((Movies*)(*it))->getTitle() << " " << ((Movies*)(*it))->getYear() << " "
	      << " " << ((Movies*)(*it))->getDirector() << " " << ((Movies*)(*it))->getDuration() << " " << ((Movies*)(*it))->getRating() << endl;
	 char isYes[10];
	 cin >> isYes;
	 cout << isYes << endl;
	 if(strcmp(isYes, "y")==0){
	   delete *it;
	   it = list.erase(it);
	   break;
	 }
       } else if((*it)->getType() == 2){
	 cout <<"Delete this Videogame? (y/n)" << ((Videogames*)(*it))->getTitle() << " " << ((Videogames*)(*it))->getYear() <<
	   " " << ((Videogames*)(*it))->getPublisher() << " " << ((Videogames*)(*it))->getRating() << endl;
	 char isYes[10];
	 cin >> isYes;
	 cout << isYes << endl;
	 if(strcmp(isYes, "y")==0){
	   delete *it;
	   it = list.erase(it);
	   break;
	 }
       } else if((*it)->getType() == 3){
	 cout << "Delete this Song? (y/n) " << ((Music*)(*it))->getTitle() << " " << ((Music*)(*it))->getYear() <<
	   " " << ((Music*)(*it))->getArtist() << " " << ((Music*)(*it))->getDuration()<< " " << ((Music*)(*it))->getPublisher() << endl;
	 char isYes[10];
	 cin >> isYes;
	 cout << isYes << endl;
	 if(strcmp(isYes, "y")==0){
	   delete *it;
	   it = list.erase(it);
	   break;
	 }
       }
     }
   }
  }
}



int main(){
  //list of Media
  vector<Media*> mediaList;
  bool stillGoing = true;
  //keep going until quit
  while(stillGoing){
    //prompt user
    cout << "SEARCH, DELETE, ADD, or, QUIT" << endl;
    char input[80];
    //get input
    cin >> input;
    //call functions
    if(input[0] == 'A'){
      ADD(mediaList);
    } else if(input[0] == 'S'){
      SEARCH(mediaList);
    } else if(input[0] == 'D'){
      DELETE(mediaList);
    } else if(input[0] == 'Q'){
      stillGoing = false;
    }
	
    
  }

  return 0;
}
