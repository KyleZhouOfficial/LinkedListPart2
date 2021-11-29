/*
Kyle Zhou
This project allows you to add delete and print a student database
10/20/21
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include "Student.h"

using namespace std;

int hashFunc(char firstName[80], char lastName[80], int id, float gpa, int sz){
  long long res = 0;
  for(int i = 0; i < strlen(firstName); i++){
    res += firstName[i] * (i+1);
  }
  for(int i = 0; i < strlen(lastName); i++){
    res += lastName[i] * (i+1);
  }
  res += id * 3;
  res += gpa + 35;

  return res % sz;
}

//add function
void add(Student* &head, char first[80], char last[80], int idVal, int gpaVal){
  //if the head is null then new node is now the head
  if(head == NULL){
    head = new Student(first, last, idVal, gpaVal);
    return;
  }
  //if the next node is null then set the next node to the new
  if(head->getNext() == NULL){
    head->setNext(new Student(first, last, idVal, gpaVal));
    return;
  }
  //call add on next node
  Student* temp = head->getNext();
  add(temp, first, last, idVal, gpaVal);
 
}

//rehash function
void rehash(Student* head, Student** &temp, int sz){
  if(head != NULL){
    add(temp[hashFunc(head->getFirst(), head->getLast(), head->getId(), head->getGpa(), sz)], head->getFirst(), head->getLast(), head->getId(), head->getGpa()); 
    rehash(head->getNext(), temp, sz);
  }
}


//print function
void print(Student* next, Student* head){
  //when next is head then it is the beginning of list
  if(next != NULL){ //if the node is not NULL then print out its fields
    cout << next->getFirst() << ", " << next->getLast()<< ", " << next->getId()  << ", " << fixed << setprecision(2) <<  next->getGpa() << endl;
    //call on next node
    print(next->getNext(), head);
  }
}

//check how many collisions
int check(Student* next, int& count){
  //when next is head then it is the beginning of list
  if(next != NULL){ //if the node is not NULL then print out its fields
    count++;
    check(next->getNext(), count);
  }
}


//delete
void del(Student* curr,Student* &head, int id, Student* prev){
  //if the head is null then there is nothing to delete
  if(head == NULL) return;
  //if the node had the id to delete
  if(curr->getId() == id){
    if(prev == NULL){ //if curr node is the beginning
      //make the next node the head node
      head = curr->getNext(); 
    } else{ //connect the previous node to the next node
      prev->setNext(curr->getNext());
    }
    //delete the current node
    delete curr;
    return;
  }
  //while the next node is not NULL call delete on next node
  if(curr->getNext() != NULL){
    del(curr->getNext(), head, id, curr);
  }
}


int main(){
  int hashSize = 133;
  Student** studentList;
  studentList = new Student*[hashSize];

  for(int i = 0; i < hashSize; i++){
    studentList[i] = NULL;
  }
  //studentList
  //keep running program?
  bool keepRunning = true;
  while(keepRunning){
    cout << "Please Enter a Command" << endl;
    cout << "ADD, PRINT, QUIT, or DELETE" << endl;
    //recieve command
    char command[10];
    cin >> command;
    //if is add
    if(strcmp(command, "ADD") == 0){
      char first[80];
      char last[80];
      int id;
      float gpa;
      //input fields for new student
      cout << "Enter first name: " << endl;
      cin >> first;
      cout << "Enter last name: " << endl;
      cin >> last;
      cout << "Enter id: " << endl;
      cin >> id;
      cout << "Enter gpa: " << endl;
      cin >> gpa;
      add(studentList[hashFunc(first, last, id, gpa, hashSize)], first, last, id, gpa);

      for(int i = 0; i < hashSize; i++){
	int temp = 0;
	check(studentList[i], temp);
	if(temp > 1){
	  cout << "here" << endl;
	  hashSize *= 2;
	  Student** temp;
	  temp = new Student*[hashSize];
	  for(int i = 0; i < hashSize; i++){
	    temp[i] = NULL;
	  }

	  for(int i = 0; i < hashSize/2; i++){
	    rehash(studentList[i], temp, hashSize);
	  }

	  for(int i = 0; i < hashSize/2; i++){
	    delete studentList[i];
	  }

	  studentList = temp;

	  delete [] temp;
	  cout << hashSize << endl;
	  break;
	}
      }
     
    }
    //if print
    if(strcmp(command, "PRINT") == 0){
      for(int i = 0; i < hashSize; i++){
	print(studentList[i], studentList[i]);
      }
      cout << endl;
    }
    //if quit
    if(strcmp(command, "QUIT") == 0){
      keepRunning = false;
    }
    //if delete
    if(strcmp(command, "DELETE") == 0){
      int id;
      cout << "Enter id to delete: " << endl;
      cin >> id;
      for(int i = 0; i < hashSize; i++){
	del(studentList[i],studentList[i],id, NULL);
      }
    }
   
  }

  for(int i =0; i < hashSize; i++){
    delete studentList[i];
  }
  delete [] studentList;
  
  return 0;
}
