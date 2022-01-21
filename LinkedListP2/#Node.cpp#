#include "Node.h"
#include "Student.h"

Node::Node(Student* student) {
    _student = student;
    next = NULL;
}

Node::~Node() {
    delete _student;
    next = NULL;
}

Student* Node::getStudent() {
    return _student;
}

void Node::setNext(Node* newnext) {
    next = newnext;
}

Node* Node::getNext() {
    return next;
}
