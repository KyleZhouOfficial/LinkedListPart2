/*
Kyle Zhou
This project allows you to add delete and print a student database using a hashtable
Use ADD to add PRINT to print DELETE to delete GEN to generate students and QUIT to quit
list.txt holds first names
list1.txt holds last names
12/1/21
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include "Student.h"
#include <fstream>

using namespace std;

//hashfunction
int hashFunc(char firstName[80], char lastName[80], int id, float gpa, int sz){
  long long res = 0;
  //multiplies every character by its position
  for(int i = 0; i < strlen(firstName); i++){
    res += firstName[i] * (i+1);
  }
  for(int i = 0; i < strlen(lastName); i++){
    res += lastName[i] * (i+1);
  }

  //adds id and gpa multiplied by constant
  res += id * 3;
  res += gpa + 35;
  //mod array size
  return res % sz;
}

//add function
void add(Student* &head, char first[80], char last[80], int idVal, float gpaVal){
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
    //add new student to temp and continue along the linked list
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
  if(next != NULL){ //if next is not null
    //increment count of how many students are in current chain
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

//generates random students
void randomGen(int toAdd, char** first, char** last, Student** &studentList, int hashSize, int &id){
  srand(time(NULL));
  for(int i = 0; i < toAdd; i++){
    int number = rand();
    //mod so random number within 0-999
    number %= 1000;
    char* firstName = first[number];
    char* lastName = last[number];
    float gpa = rand() % 5;
    id++;
    //uses add function to add to studentList
    add(studentList[hashFunc(firstName, lastName, id, gpa, hashSize)], firstName, lastName, id, gpa);
  }
}


int main(){
  //holds the first names from file
  char** first;
  first = new char*[1000];
  //holds last names from file
  char** last;
  last = new char*[1000];
  
  //Code from https://www.cplusplus.com/doc/tutorial/files/
  //reads in from file
  ifstream myfile ("list.txt");
  for(int i = 0; i < 1000; i++){
    first[i] = new char[10];
    myfile >> first[i];
  }
  myfile.close();

  //reading in last names
  myfile.open("list1.txt");
   for(int i = 0; i < 1000; i++){
    last[i] = new char[10];
    myfile >> last[i];
  }
  myfile.close();

  //id variable for random student generation
  int id = 0;
  //holds current hashtable size
  int hashSize = 133;
  //hashtable
  Student** studentList;
  studentList = new Student*[hashSize];

  //Null out the hashtable
  for(int i = 0; i < hashSize; i++){
    studentList[i] = NULL;
  }
  
  //studentList
  //keep running program?
  bool keepRunning = true;
  while(keepRunning){
    cout << "Please Enter a Command" << endl;
    cout << "ADD, PRINT, QUIT, GEN, or DELETE" << endl;
    //recieve command
    char command[10];
    cin >> command;
    //if is generate
    if(strcmp(command, "GEN") == 0){
      cout << "How many students to add?";
      int num;
      cin >> num;
      //adds random student to studentList
      randomGen(num, first, last, studentList, hashSize, id);
    }
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
      //calls hash function to retrieve index and pass into add function
      add(studentList[hashFunc(first, last, id, gpa, hashSize)], first, last, id, gpa);

      //checking if need to resize
      for(int i = 0; i < hashSize; i++){
	int temp = 0;
	//checking how many collisions in current chain
	check(studentList[i], temp);
	//if more than three
	if(temp > 3){
	  //double hash table size
	  hashSize *= 2;
	  //create temporary hashtable and null it out
	  Student** temp;
	  temp = new Student*[hashSize];
	  for(int i = 0; i < hashSize; i++){
	    temp[i] = NULL;
	  }

	  //rehash what is in studentList into temporary
	  for(int i = 0; i < hashSize/2; i++){
	    rehash(studentList[i], temp, hashSize);
	  }

	  //free pointers in studentList
	  for(int i = 0; i < hashSize/2; i++){
	    delete [] studentList[i];
	  }
	  //set studentList to temp
	  studentList = temp;
	  //delete temp
	  delete [] temp;
	  //leave since we have rehashed
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

  delete studentList;
  
  return 0;
}
