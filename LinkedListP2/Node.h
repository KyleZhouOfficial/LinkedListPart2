/*
 * Node
 */
#ifndef NODE_h
#define NODE_h
#include <iostream>
#include "Student.h"
using namespace std;

class Node {

    public:
        Node(Student* student); //create an instance of a Node
        ~Node(); //destroy an instance of a Node
        Student* getStudent(); //get the student stored in the Node
        void setNext(Node* newnext); //set the next Node
        Node* getNext(); //get the next Node

    private:
        Student* _student; //student
        Node* next; //pointer to the next Node
};
#endif
