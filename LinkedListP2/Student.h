/*
Kyle Zhou
10/26/21
Definition for student class
 */

//header guards
#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <cstring>

using namespace std;

class Student{

 private:
  //fields
  char firstName[80];
  char lastName[80];
  int id;
  float gpa;

 public:
  //constructors and destructors
  Student();
  Student(char first[80], char last[80], int idVal, float gpaVal);
  ~Student();
  //getters and setters
  char* getFirst();
  char* getLast();
  int getId();
  float getGpa();
  void setGpa(float val);
  void setID(int val);
  void setFirst(char val[80]);
  void setLast(char val[80]);
};

#endif
