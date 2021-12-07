/*
Kyle Zhou
This program creates a binary heap using an array and can read input from 
a USER or FILE (num.txt). The print function uses a dfs to print out the 
binary heap sideways. 
12/7/21
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <array>
#include <cmath>

using namespace std;

//prototypes
void swim (int k, int heap[105]);
void insert(int heap[105], int &N, int x);
void sink(int N,int k, int heap[105]);

//sink function if parent becomes less than child
void sink(int N,int k, int heap[105]){
  //while not at end
  while(2*k <= N){
    //get child
    int j = 2 * k;
    //find which child is greater
    if(j < N && heap[j] < heap[j+1])j++;
    //if parent is greater than child then stop
    if(heap[k] > heap[j]) break;
    //swap the parent and child
    swap(heap[k], heap[j]);
    //continue checking child
    k = j;
  }
}

//when child becomes greater than parent
void swim (int k, int heap[105]){
  //while it is not the root and the parent is less than child
  while(k > 1 && heap[k/2] < heap[k]){
    //swap parent and child and continue
    swap(heap[k], heap[k/2]);
    k = k/2;
  }
}

//insert function
void insert(int heap[105], int &N, int x){
  //add new number to latest index
  heap[++N] = x;
  //move the child up to fix the tree
  swim(N, heap);
}

//remove
void remove(int heap[105], int &N, char output[200000], int &spot){
  //find max of binary heap 
  int max = heap[1];
  //swap the top and bottom of the tree and decrease total number of nodes
  swap(heap[1], heap[N--]);
  //sink the newly swapped element to restore balance
  sink(N, 1, heap);
  //set the largest elemnt to 0
  heap[N+1] = 0;
  char space[1];
  space[0] = ' ';
  //char array concatenation found at: https://linuxhint.com/string-concatenation-in-c/
  //add the max number to the output string
  strcat(output, to_string(max).c_str());
  strcat(output, space);
}

//print function
void print(int heap[105], int curr, bool visited[105], int N){
  //if visited the current node or out of bounds return
  if(visited[curr] || curr > N) return;
 
  visited[curr] = true;
  //call function on left node
  print(heap, curr * 2, visited, N);
  //find what level the node is on 
  int spaces = log2(curr);
  //print out the corresponding spaces
  for(int i = 0; i < 2*spaces; i++) cout << " ";
  cout << heap[curr] << endl;
  //call function on right node
  print(heap, curr * 2 + 1, visited, N);
}

int main(){
  //variables
  int heap[105];
  char output[200000];
  bool visited[105];
  memset(visited, false, sizeof(visited));
  int spot = 0;
  int N = 0;

  //ask user for input type
  cout << "Enter USER for user input or FILE for file input?" << endl;
  char command[10];
  cin >> command;
  if(strcmp(command, "FILE") == 0){
    //open file
    ifstream myfile("num.txt");
    //read until end of file
    int num;
    while(myfile >> num){
      insert(heap, N, num);
    }
    myfile.close();
  } else if(strcmp(command, "USER") == 0){
    cout << "Enter STOP to stop input" << endl;
    char number[10];
    //read 100 numbers or until stop
    for(int i = 0; i < 100; i++){
      cin >> number;
	if(strcmp(number, "STOP")==0){ 
	  break;
	}
	int temp = stoi(number);
	insert(heap, N, temp); 
      }
  }

  cout << "Tree Graph" << endl;
   memset(visited, false, sizeof(visited));
   //print out tree graph
   print(heap, 1, visited, N);
   cout << endl;
   cout << "Removal of Numbers" << endl;
   //remove numbers one by one and print the output
   int toPrint = N;
   for(int i = 0; i < toPrint; i++){
     remove(heap, N, output, spot);
     cout << output << endl;
   }
  return 0;
}
