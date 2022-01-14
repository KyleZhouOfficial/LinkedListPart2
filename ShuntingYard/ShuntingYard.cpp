/*
By : Kyle Z
1/14/21
Impementation of Shunting yard algorithm and expression tree to print out an expression in
Prefix Infix and Postfix notation
Used algorithm from http://mathcenter.oxford.emory.edu/site/cs171/shuntingYardAlgorithm/
 */

#include <iostream>
#include "BSTNode.h"
#include <map>
#include <cmath>

using namespace std;

//class used for stack
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

//peek for queue
BSTNode* peek(BSTNode* top){
  if(top != NULL) return top;
  return NULL;
}

//peek for stack
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

//check for operator
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


//apply operator to two operands
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

//debugging pain
/*
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
*/

//different traversals
void inorder(BSTNode* x){
  if(x == NULL){
    return;
  } else{
    // go left print node and go right
    inorder(x->getLeft());
    cout << x->getData() << " ";
    inorder(x->getRight());
  }
}

void postorder(BSTNode* x){
  if(x == NULL){
    return;
  } else{
    //go left and right then current node
    postorder(x->getLeft());
    postorder(x->getRight());
    cout << x->getData() << " ";
  }
}

void preorder(BSTNode* x){
  if(x == NULL){
    return;
  } else{
    //print node then go left and right
    cout << x->getData() << " ";
    preorder(x->getLeft());
    preorder(x->getRight());
  }
}

int main(){
  //map used to check precedence in shunting yard algorithm
  map<char, int> prec;
  prec['^'] = 4;
  prec['*'] = 3;
  prec['/'] = 3;
  prec['+'] = 2;
  prec['-'] = 2;

  //stack
  StackNode* stackTop = NULL;
  StackNode* valueStack = NULL;
  //queue
  BSTNode* outTop = NULL;
  BSTNode* outRear = NULL;
  //variables
  char temp;
  char arr[100];
  int ind = 0;
  cout << "Please enter an expression in INFIX form" << endl;
							
  cin.getline(arr, 100, '\n');

  //shunting yard algorithm
  for(int i = 0; i < strlen(arr); i++){
    if(arr[i] == ' ') continue;
    //read in character
    temp = arr[i];
    //if is number then add to output queue
    if(isDigit(temp)){
      enqueue(new BSTNode(temp), outTop, outRear);
    }//if left parenthesis push to stack
     else if(temp == '('){
      push(new BSTNode(temp), stackTop);
     }//if right parenthesis    
    else if(temp == ')'){
      // top of stack is not left paren then keep popping to output
      while(peek(stackTop) != NULL && peek(stackTop)->getData() != '('){
	 BSTNode* op = pop(stackTop);
	 enqueue(op, outTop, outRear);
	}
       pop(stackTop);
    }
    //if(is operator and stack is empty or left parenthesis on top push
    else if(isOperator(temp) && (peek(stackTop) == NULL || peek(stackTop)->getData() == '(')){
	push(new BSTNode(temp), stackTop);  
    }

    //if is operator and has either higher or equal ask operator on top push onto stack
    else if(isOperator(temp) && prec[temp] >= prec[peek(stackTop)->getData()] && temp == '^'){
       push(new BSTNode(temp), stackTop);
    }
    //if operator and has lower or same precedence as operator on top and is left associative continue to pop until not true then push
    else if(isOperator(temp)){
      while(peek(stackTop) != NULL && prec[temp] <= prec[(peek(stackTop)->getData())] && temp != '^'){
	BSTNode* op = pop(stackTop);
	enqueue(op, outTop, outRear);
      }
       push(new BSTNode(temp), stackTop);
    }

    
  }
  //add rest of operators into queue
   while(stackTop != NULL){
       BSTNode* op = pop(stackTop);
       enqueue(op, outTop, outRear);
    }
 
   //beginning of expression tree
  StackNode* expressionT = NULL;
  BSTNode* front = peek(outTop);
  //while items still in stack
  while(front != NULL){
    //if operator
    if(front->getData() == '+' || front->getData() == '-' || front->getData() == '/' ||
       front->getData() == '*' || front->getData() == '^'){
      //apply to two operands and push back into stack
      BSTNode* temp = new BSTNode(front->getData());
      BSTNode* a = pop(expressionT);
      BSTNode* b = pop(expressionT);
      temp->setRight(a);
      temp->setLeft(b);
      push(temp, expressionT);
    } else{ //if operand then just push onto stack
      BSTNode* temp = new BSTNode(front->getData());
       push(temp, expressionT);
    }
    //dequeue and print
    dequeue(outTop, outRear);
    cout << front->getData();
    front = peek(outTop);
  }
  cout << endl;
  //ask users for what to output
  char input[10];
  while(true){
    cout << "Enter PREFIX, INFIX, POSTFIX, or QUIT" << endl;
    cin >> input;
    //prefix infix and postfix
    if(!strcmp(input, "PREFIX")){
      preorder(expressionT->curr);
    } else if(!strcmp(input, "INFIX")){
      inorder(expressionT->curr);
    } else if(!strcmp(input, "POSTFIX")){
      postorder(expressionT->curr);
    } else if(!strcmp(input, "QUIT")){
      break;
    }
    cout << endl;
  }
  

  


}
