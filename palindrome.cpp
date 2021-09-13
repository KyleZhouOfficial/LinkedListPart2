#include <iostream>
#include <cstring>

using namespace std;

int main(){
  //variables
  char strInput[80];
  char strForward[80];
  char strBackward[80];
  //get input 
  cin.get(strInput, 80);
  cin.get();
  //remove spaces and punctuation and put it in strForward
  int cnt = 0;
  for(int i = 0; i < 80; i++){
    //if reached end of string break
    if(strInput[i] == '\0') break;
    //if is alphabetic letter then add to strForward
    if(isalpha(strInput[i])){
      strForward[cnt] = tolower(strInput[i]);
      cnt++;
    }
  }
  //add null character at end of string
  strForward[cnt] = '\0';
  
  //start from the back of forward string at add to beginning of backward string
  cnt = 0;
  for(int i = strlen(strForward)-1; i >= 0; i--){
      strBackward[cnt] = strForward[i];
      cnt++;
  }
  //add null character at end of backward string
  strBackward[cnt] = '\0';
 
  //if strings are same then is palindrome else no palindrome
  if(strcmp(strForward, strBackward) == 0){
    cout << "Palindrome" << endl;
  } else{
    cout << "Not Palindrome" << endl;
  }
  return 0;
}
