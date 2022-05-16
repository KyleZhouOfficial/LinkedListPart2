/*
  By: Kyle Zhou
  5/10/22
  Graph creator that uses Dijkstra's algorithm to allow users to find the shortest path between two vertices. Allows to add nodes, remove nodes, add remove edges.
  Source: https://www.youtube.com/watch?v=pVfj6mxhdMw&ab_channel=ComputerScience
*/

#include <iostream>
#include <map>
#include <cstring>
#include <unordered_map>

using namespace std;

//checks if all vertices are visited
bool unvis(bool* arr, int cnt){
  for(int i = 0; i < cnt; i++){
    if(arr[i] == false) return true;
  }
  return false;
}

//finds the index for a label given the string
int findlabel(char* n, char nodes[21][21], int vert){
  for(int i = 0; i < vert; i++){
    if(strcmp(nodes[i], n) == 0){
      return i;
      
    }
  }
  return 0;
}

//check if two nodes are connected
bool dfs(int curr, int e, bool* dfsvis, bool arr[21][21], int vertexNum){
  if(curr == e) return true;
  if(dfsvis[curr]) return false;
  dfsvis[curr] = true;

  for(int i = 0; i < vertexNum; i++){
    if(!dfsvis[i] && arr[curr][i]){
      dfs(i, e, dfsvis, arr, vertexNum);
    }
  }
  
  return false;
}


int main(){
  //adjacency grid
  bool arr[21][21];
  //weights
  int weights[21][21];
  unordered_map<char*, int> names;
  char nodes[21][21];

  memset(arr, 0, sizeof(arr));
  memset(weights, 0, sizeof(weights));
  
  

  char input[20];
  int vertexNum = 0;
  while(true){
    cout << "Enter addvertex, addedge, remvertex, remedge, shortpath, or quit" << endl;
    cin >> input;
    
    if(strcmp(input, "addvertex") == 0){
      //gets label and puts into nodes array
      cout << "Enter label" << endl;
      char temp[20];
      cin >> nodes[vertexNum];
     
      vertexNum = vertexNum+1;
     
    } else if(strcmp(input, "addedge") == 0){
      char t[20];
      char t1[20];
      int w = 0;
      cout << "Enter FIRST name" << endl;
      cin >> t;
      cout << "Enter SECOND name" << endl;
      cin >> t1;
      cout << "Enter WEIGHT" << endl;
      cin >> w;
      cout << "here" << endl;
      //sets connection to true and sets weight
      arr[findlabel(t, nodes, vertexNum)][findlabel(t1, nodes, vertexNum)] = true;
      weights[findlabel(t, nodes, vertexNum)][findlabel(t1, nodes, vertexNum)] = w;
    } else if(strcmp(input, "remvertex") == 0){
      char t[20];
      cout << "Enter Vertex To Delete" << endl;
      cin >> t;
      //find index
      int curr = findlabel(t, nodes, vertexNum);

      //set connections to false and weights
      for(int i = 0; i < vertexNum; i++){
	arr[curr][i] = false;
	weights[curr][i] = 0;
      }

      //sets other nodes connection to removed node to false
      for(int i = 0; i < vertexNum; i++){
	arr[i][curr] = false;
	weights[i][curr] = 0;
      }

    } else if(strcmp(input, "remedge")  == 0){
      char t[20];
      char t1[20];
      cout << "Enter FIRST name" << endl;
      cin >> t;
      cout << "Enter SECOND name" << endl;
      cin >> t1;
      //set connections to false and zero out weight
      arr[findlabel(t, nodes, vertexNum)][findlabel(t1, nodes, vertexNum)] = false;
      weights[findlabel(t, nodes, vertexNum)][findlabel(t1, nodes, vertexNum)] = 0;

    } else if(strcmp(input, "print") == 0){ //debugging purposes
      
      for(int i = 0; i < vertexNum; i++){
	for(int j = 0; j < vertexNum; j++){
	  cout << arr[i][j] << " ";
	}
	cout << endl;
      }

      for(int i = 0; i < vertexNum; i++){
	for(int j = 0; j < vertexNum; j++){
	  cout << weights[i][j] << " ";
	}
	cout << endl;
      }
    } else if(strcmp(input, "shortpath") == 0){
      //get start and end
      cout << "Enter Start Node" << endl;
      char temp[20];
      cin >> temp;
      cout << "Enter End Node" << endl;
      char temp1[20];
      cin >> temp1;

      bool visited[vertexNum];
      int dist[vertexNum];
      int prev[vertexNum];
      bool dfsvis[vertexNum];
      //zero out arrays
      for(int i = 0; i < vertexNum; i++){
	dfsvis[i] = false;
	visited[i] = false;
	dist[i] = 100000;
      }

      int s = findlabel(temp, nodes, vertexNum);
      int e = findlabel(temp1, nodes, vertexNum);
      if(!dfs(s, e, dfsvis, arr, vertexNum)){ //check if connected
	cout << "Not Connected" << endl;
      } else{
	//set start distance to zero
	dist[findlabel(temp, nodes, vertexNum)] = 0;

	int curr = findlabel(temp, nodes, vertexNum);
	dist[curr] = 0;
 
	while(unvis(visited, vertexNum)){
	  //update distances for all adjacent nodes
	  for(int i = 0; i < vertexNum; i++){
	    if(!visited[i] && arr[curr][i]){ //if not visited and is connected
	      int a = weights[curr][i];
	      a += dist[curr];
	      if(a < dist[i]){ //if is shortest distance
		dist[i] = a;
		prev[i] = curr;//set previous node for later use
	      }
	    }
	  }
	  visited[curr] = true; //set curr to visited     
      
	  //find the closest neighbor and set current
	  int m = 1000000;
	  int t = 0;
	  for(int i = 0; i < vertexNum; i++){
	    if(dist[i] < m && arr[curr][i] && !visited[i]){
	      m = dist[i];
	      t = i;
	    }
	  }
	  curr = t;
	}
	//print out path and total path value
	int x = findlabel(temp1, nodes, vertexNum);
	cout << "PATH: ";
	while(x != findlabel(temp, nodes, vertexNum)){
	  cout << nodes[x] << " ";
	  x = prev[x];
	}
	cout << nodes[x] << endl;
	cout << "PATH LENGTH: " << dist[findlabel(temp1, nodes, vertexNum)] << endl;
      }
    } else if(strcmp(input, "quit") == 0){
      break;
    }

  }

}
