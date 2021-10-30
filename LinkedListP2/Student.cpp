#include "Student.h"
#include <cstring>
#include <iostream>

using namespace std;

Student::Student(){
  
}

Student::Student(char first[80], char last[80], int idVal, float gpaVal){

  strcpy(firstName, first);
  strcpy(lastName, last);
  id = idVal;
  gpa = gpaVal;
}

Student::~Student(){

}

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
