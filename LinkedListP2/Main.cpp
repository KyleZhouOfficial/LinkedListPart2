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

void add(Node* &head, char first[80], char last[80], int idVal, int gpaVal){
  if(head == NULL){
    Student* temp = new Student(first, last, idVal, gpaVal);
    head = new Node(temp);
    return;
  }
  if(head->getNext() == NULL){
    Student* temp = new Student(first, last, idVal, gpaVal);
    Node* a = new Node(temp);
    head->setNext(a);
    return;
  }
  Node* temp = head->getNext();
  add(temp, first, last, idVal, gpaVal);
 
}

void print(Node* next, Node* head){
  if (next == head){
    cout << "List:" << endl;
  }if(next != NULL){
    cout << next->getStudent()->getFirst() << ", " << next->getStudent()->getLast()<< ", " << next->getStudent()->getId()  << ", " << fixed << setprecision(2) <<  next->getStudent()->getGpa() << endl;
    print(next->getNext(), head);
  }
}

void average(Node* next, Node* head, float& runningSum, int& totalNodes){
  if(next != NULL){
    runningSum += next->getStudent()->getGpa();
    totalNodes++;
    average(next->getNext(), head, runningSum, totalNodes);
  }
}

//delete
void del(Node* curr,Node* &head, int id, Node* prev){
  if(head == NULL) return;
  if(curr->getStudent()->getId() == id){
    if(prev == NULL){
      head = curr->getNext(); 
    } else{
      prev->setNext(curr->getNext());
    }
    delete curr;
    return;
  }
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
    char command[10];
    cin >> command;
    //if is add
    if(strcmp(command, "ADD") == 0){
      char first[80];
      char last[80];
      int id;
      float gpa;
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
    if(strcmp(command, "AVERAGE") == 0){
      float sum = 0;
      int nodes = 0;
      average(head, head, sum, nodes);
      cout << fixed << setprecision(2) << (float)(sum/nodes) << endl;
    }
   
  }
  return 0;
}
