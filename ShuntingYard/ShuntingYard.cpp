#include <iostream>
#include "BSTNode.h"
#include <map>
#include <cmath>

using namespace std;


class StackNode{
public:
  StackNode* next;
  BSTNode* curr;
  StackNode(BSTNode* temp);
};

StackNode::StackNode(BSTNode* temp){
  curr = temp;
  next = NULL;
}



//stack functions
void push(BSTNode* topush, StackNode* &top){
  if(top == NULL){
    top = new StackNode(topush);
  } else{
    StackNode* ptr = new StackNode(topush);
    ptr->next = top;
    top = ptr;
  }
}


BSTNode* peek(BSTNode* top){
  if(top != NULL) return top;
  return NULL;
}

BSTNode* peek(StackNode* top){
  if(top != NULL) return top->curr;
  return NULL;
}

BSTNode* pop(StackNode* &top){
  if(top == NULL) return NULL;

  BSTNode* temp = top->curr;
  top = top->next;
  return temp;
}


//queue functions
void enqueue(BSTNode* toAdd, BSTNode* &top, BSTNode* &rear){
  if(rear == NULL){
    rear = toAdd;
    top = rear;
    return;
  }

  rear->setRight(toAdd);
  rear = toAdd;
}

void dequeue(BSTNode* &top, BSTNode* &rear){
  if(top == NULL){
    return;
  }

  BSTNode* temp = top;

  top = top->getRight();

  if(top == NULL){
    rear = NULL;
  }
  delete temp;
}

bool isOperator(char val){
  if(val == '*' || val == '/' || val == '+' || val == '-' || val == '^') return true;
  return false;
}

bool isDigit(char val){
  if(val >= '0' && val <= '9'){
    return true;
  }
  return false;
}



int apply(char a, char b, char op){
  a -= '0';
  b -= '0';
  if(op == '+'){
    return a + b;
  } else if(op == '-'){
    return a - b;
  } else if(op == '*'){
    return a * b;
  } else if(op == '/'){
    return a / b;
  } else {
    return (int)pow(a, b);
  }
}


void print(StackNode* top){
  while(top != NULL) {
    cout << (top->curr)->getData() << " ";
    top = top->next;
  }
  cout << endl;
}

void print(BSTNode* top){
  while(top != NULL) {
    cout << top->getData() << " ";
    top = top->getRight();
  }
  cout << endl;
}
  


int main(){

  map<char, int> prec;
  prec['^'] = 4;
  prec['*'] = 3;
  prec['/'] = 3;
  prec['+'] = 2;
  prec['-'] = 2;

  
  StackNode* stackTop = NULL;
  StackNode* valueStack = NULL;
  BSTNode* outTop = NULL;
  BSTNode* outRear = NULL;
  char temp;
  char arr[100];
  int ind = 0;

  cin >> arr;

  
  for(int i = 0; i < strlen(arr); i++){
    print(outTop);
    print(stackTop);
    
    
    temp = arr[i];
    if(isDigit(temp)){
      enqueue(new BSTNode(temp), outTop, outRear);
    }
     else if(temp == '('){
      push(new BSTNode(temp), stackTop);
    }    
    else if(temp == ')'){
      while(peek(stackTop) != NULL && peek(stackTop)->getData() != '('){
	 BSTNode* op = pop(stackTop);
	 enqueue(op, outTop, outRear);
	}
       pop(stackTop);
    }

    else if(isOperator(temp) && (peek(stackTop) == NULL || peek(stackTop)->getData() == '(')){
	push(new BSTNode(temp), stackTop);  
    }

   
    else if(isOperator(temp) && prec[temp] >= prec[peek(stackTop)->getData()] && temp == '^'){
       push(new BSTNode(temp), stackTop);
    }

    else if(isOperator(temp)){
      cout << temp << " " << peek(stackTop)->getData() << endl;
      while(peek(stackTop) != NULL && prec[temp] <= prec[(peek(stackTop)->getData())] && temp != '^'){
	cout << "here" << endl;
	BSTNode* op = pop(stackTop);
	enqueue(op, outTop, outRear);
      }
       push(new BSTNode(temp), stackTop);
    }

    
  }

   while(stackTop != NULL){
       BSTNode* op = pop(stackTop);
       enqueue(op, outTop, outRear);
    }
 

  BSTNode* front = peek(outTop);
  while(front != NULL){
    dequeue(outTop, outRear);
    cout << front->getData();
    front = peek(outTop);
   
  }
  cout << endl;
  


}
