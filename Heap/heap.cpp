#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <array>
#include <cmath>

using namespace std;

void swim (int k, int heap[105]);
void insert(int heap[105], int &N, int x);
void sink(int N,int k, int heap[105]);

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

void swim (int k, int heap[105]){
  //while it is not the root and the parent is less than child
  while(k > 1 && heap[k/2] < heap[k]){
    //swap parent and child and continue
    swap(heap[k], heap[k/2]);
    k = k/2;
  }
}

void insert(int heap[105], int &N, int x){
  heap[++N] = x;
  swim(N, heap);
}

void remove(int heap[105], int &N, char output[200000], int &spot){
  int max = heap[1];
  swap(heap[1], heap[N--]);
  sink(N, 1, heap);
  heap[N+1] = 0;

  int digits = 0;
  int temp = max;
  while(temp){
    digits++;
    temp /= 10;
  }
  for(int i = 0; i < digits; i++){
    output[spot++] = max / pow(10, digits);
  }
}

void print(int heap[105], int curr, bool visited[105]){
  if(visited[curr] || curr > N) return;
  visited[curr] = true;

  print(heap, curr * 2, visited);
  print(heap, curr * 2 + 1, visited
}

int main(){
  int heap[105];
  char output[200000];
  bool visited[105];
  memset(visited, false, sizeof(visited);
  int spot = 0;
  int N = 0;
  cout << "Enter USER for user input or FILE for file input?" << endl;
  char command[10];
  cin >> command;
  if(strcmp(command, "FILE") == 0){
    ifstream myfile("num.txt");
    


    myfile.close();
  } else if(strcmp(command, "USER") == 0){
    
  }

  
  return 0;
}
