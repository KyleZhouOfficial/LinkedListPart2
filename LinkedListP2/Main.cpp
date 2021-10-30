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
  Node* current = head;
  if(current == NULL){
    Student* temp = new Student(first, last, idVal, gpaVal);
    head = new Node(temp);
  } else{
    while(current->getNext() != NULL){
      current = current->getNext();
    }
    current->setNext(new Node(new Student(first, last, idVal, gpaVal)));
  }
}

void print(Node* next, Node* head){
  if (next == head){
    cout << "list:";
  }if(next != NULL){
    cout << next->getStudent()->getFirst() << " ";
    print(next->getNext(), head);
  }
}

//delete
void del(Node* &head, int id){
  Node* current = head;
  if(current == NULL){
    return;
  } else{
    Node* prev = NULL;
    while(current->getNext() != NULL && current->getStudent()->getId() != id){
      prev = current;
      current = current->getNext();
    }
    if(prev == NULL){
      
    } else{

    }
  }
  
}


int main(){
  //studentList
  Node* head = NULL;
  //keep running program?
  bool keepRunning = true;
  while(keepRunning){
    cout << "Please Enter a Command" << endl;
    char command[10];
    cin >> command;
    //if is add
    if(command[0] == 'A'|| command[0] == 'a'){
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
    if(command[0] == 'P'||command[0] == 'p'){
      print(head, head);
    }
    //if quit
    if(command[0] == 'Q' || command[0] == 'q'){
      keepRunning = false;
    }
    //if delete
    if(command[0] == 'D' || command[0] == 'd'){
      del(studentList);
    }			       
   
  }
  return 0;
}
