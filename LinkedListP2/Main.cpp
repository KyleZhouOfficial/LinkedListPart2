/*
Kyle Zhou
This project allows you to add delete and print a student database
10/20/21
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include "Node.h"
#include "Student.h"

using namespace std;

//add function
void add(Node* &head, char first[80], char last[80], int idVal, float gpaVal){
  //if the head is null then new node is now the head
  if(head == NULL){
    Student* temp = new Student(first, last, idVal, gpaVal);
    head = new Node(temp);
    return;
  }
  //if the next node is null then set the next node to the new
  if(head->getNext() == NULL){
    Student* temp = new Student(first, last, idVal, gpaVal);
    Node* a = new Node(temp);
    if(head->getStudent()->getId() > idVal){
      a->setNext(head);
      head = a;
    } else{
      head->setNext(a);
    }
    return;
  }
  //if the next nodes id is greater than the one to add then insert 
  if(head->getNext()->getStudent()->getId() > idVal){
    Student* temp = new Student(first, last, idVal, gpaVal);
    Node* a = new Node(temp);
    //insert new node in between the current and next node
    a->setNext(head->getNext());
    head->setNext(a);
    return;
  }
  //call add on next node
  Node* temp = head->getNext();
  add(temp, first, last, idVal, gpaVal);
 
}

//print function
void print(Node* next, Node* head){
  //when next is head then it is the beginning of list
  if (next == head){
    cout << "List:" << endl;
  }if(next != NULL){ //if the node is not NULL then print out its fields
    cout << next->getStudent()->getFirst() << ", " << next->getStudent()->getLast()<< ", " << next->getStudent()->getId()  << ", " << fixed << setprecision(2) <<  next->getStudent()->getGpa() << endl;
    //call on next node
    print(next->getNext(), head);
  }
}

//Average function passes two integers by reference for sum and total nodes
void average(Node* next, Node* head, float& runningSum, int& totalNodes){
  if(next != NULL){ //while the next is not NULL
    //ADD the gpa
    runningSum += next->getStudent()->getGpa();
    //increment the number of nodes
    totalNodes++;
    //call average on next node
    average(next->getNext(), head, runningSum, totalNodes);
  }
}

//delete
void del(Node* curr,Node* &head, int id, Node* prev){
  //if the head is null then there is nothing to delete
  if(head == NULL) return;
  //if the node had the id to delete
  if(curr->getStudent()->getId() == id){
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
  //studentList
  Node* head = NULL;
  //keep running program?
  bool keepRunning = true;
  while(keepRunning){
    cout << "Please Enter a Command" << endl;
    cout << "ADD, PRINT, QUIT, AVERAGE, or DELETE" << endl;
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
      add(head, first, last, id, gpa);
    }
    //if print
    if(strcmp(command, "PRINT") == 0){
      print(head, head);
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
      del(head,head,id, NULL);
    }
    //if average
    if(strcmp(command, "AVERAGE") == 0){
      float sum = 0;
      int nodes = 0;
      average(head, head, sum, nodes);
      //print average out to two decimals
      cout << fixed << setprecision(2) << (float)(sum/nodes) << endl;
    }
   
  }
  return 0;
}
