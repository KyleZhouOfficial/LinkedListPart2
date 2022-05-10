#include <iostream>
#include <map>
#include <cstring>
#include <unordered_map>

using namespace std;

bool unvis(bool* arr, int cnt){
  for(int i = 0; i < cnt; i++){
    if(arr[i] == false) return true;
  }
  return false;
}

int findlabel(char* n, char nodes[21][21], int vert){
  for(int i = 0; i < vert; i++){
    if(strcmp(nodes[i], n) == 0){
      return i;
      
    }
  }
  return 0;
}

int main(){
  bool arr[21][21];
  int weights[21][21];
  unordered_map<char*, int> names;
  char nodes[21][21];

  memset(arr, 0, sizeof(arr));
  memset(weights, 0, sizeof(weights));
  
  

  char input[20];
  int vertexNum = 0;
  while(true){
    cout << "Enter addvertex, addedge, remvertex, remedge, shortpath" << endl;
    cin >> input;

    if(strcmp(input, "addvertex") == 0){
      cout << "Enter label" << endl;
      char temp[20];
      cin >> nodes[vertexNum];
     
       for(int i = 0; i < vertexNum; i++){
	 cout << nodes[i] << strlen(nodes[i]) << endl;
      }
      vertexNum = vertexNum+1;
     
    } else if(strcmp(input, "addedge") == 0){
      for(int i = 0; i < vertexNum; i++){
	cout << nodes[i] << endl;
      }
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
      arr[findlabel(t, nodes, vertexNum)][findlabel(t1, nodes, vertexNum)] = true;
      weights[findlabel(t, nodes, vertexNum)][findlabel(t1, nodes, vertexNum)] = w;
    } else if(strcmp(input, "remvertex") == 0){
      

    } else if(strcmp(input, "print") == 0){

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
      cout << "Enter Start Node" << endl;
      char temp[20];
      cin >> temp;
      cout << "Enter End Node" << endl;
      char temp1[20];
      cin >> temp1;

      bool visited[vertexNum];
       int dist[vertexNum];
       int prev[vertexNum];
       
      for(int i = 0; i < vertexNum; i++){
	visited[i] = false;
	dist[i] = 100000;
      }

      dist[findlabel(temp, nodes, vertexNum)] = 0;

      int curr = findlabel(temp, nodes, vertexNum);
      dist[curr] = 0;
 
      while(unvis(visited, vertexNum)){

	for(int i = 0; i < vertexNum; i++){
	  if(!visited[i] && arr[curr][i]){
	    int a = weights[curr][i];
	    a += dist[curr];
	    if(a < dist[i]){
	      dist[i] = a;
	      prev[i] = curr;
	    }
	  }
	}
	visited[curr] = true;       
      

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
      cout << dist[findlabel(temp1, nodes, vertexNum)] << endl;

    }

  }

}
