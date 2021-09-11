#include <iostream>

using namespace std;

int main(){
  //variable for if player wants to keep playing
  bool stillPlay = true;
  while(stillPlay){
    //set random seed
    srand(time(NULL));
    int number = rand();
    //mod so random number within 0-100
    number %= 101;
    int input = 0;
    int guessCnt = 0;
    //get the guess and increment number of guesses
    // do while guess is incorrect
    do{
      cin >> input;
      //tell player too high too low or correct
      if(input > number){
	cout << "Too High" << endl;
      } else if(input < number){
	cout << "Too Low" << endl;
      } else{
	cout << "Correct" << endl;
      }
      guessCnt++;
    }while(input != number);
    //when guess correct print out guess number
    cout << guessCnt << endl;
    cout << "Play Again?" << endl;
    char yesNo;
    cin >> yesNo;
    //get play again answer
    if(yesNo == 'y'){
      stillPlay = true;
    } else if(yesNo == 'n'){
      stillPlay = false;
    }
  }
  
  return 0;
}
