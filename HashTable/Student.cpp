/*
Kyle Zhou
Implementation for Student class
11/3/21
 */
#include "Student.h"
#include <cstring>
#include <iostream>

using namespace std;

//constructors
Student::Student(){
  
}

Student::Student(char first[80], char last[80], int idVal, float gpaVal, Student* s){
  s = NULL;
  strcpy(firstName, first);
  strcpy(lastName, last);
  id = idVal;
  gpa = gpaVal;
}

//destructor
Student::~Student(){
  next = NULL;
}

Student* Student::getNext(Student* s){
  return next;
}

void Student::setNext(Student* s){
  next = s;
}

//getters
char* Student::getFirst(){
  return firstName;
}

char* Student::getLast(){
  return lastName;
}

int Student::getId(){
  return id;
}

float Student::getGpa(){
  return gpa;
}

//setters
void Student::setGpa(float val){
  gpa = val;
}

void Student::setID(int val){
  id = val;
}

void Student::setFirst(char val[80]){
  strcpy(firstName, val);
}

void Student::setLast(char val[80]){
  strcpy(lastName, val);
}
