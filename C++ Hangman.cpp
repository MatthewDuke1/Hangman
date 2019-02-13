// hangman.cpp
// Hangman game illustrates string library functions, 
// character arrays, arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// Prototype. we'll define this below.
int processGuess(char* word, const char* targetWord, char guess);

// Define an array of strings (since a string is just a char array)
//  and since string are just char *'s, we really want an array of char *'s
const char* wordBank[] = {"computer", "president", "trojan", "program",
                          "coffee", "library", "football", "popcorn", 
                          "science", "engineer"};

const int numWords = 10;

int main()
{
  srand(time(0));
  char guess;
  int numTurns = 10;

  // Pick a random word from the wordBank
  const char* targetWord = wordBank[rand() % numWords];

  // More initialization code as needed
  char word[80];  



// use strcmp and strlen to compare the strings
for (int i = 0; i < strlen(targetWord);i ++){
  word [i] = '*';          // intialize the array to char star's 
}

word [strlen(targetWord)] = '\0';
//----------------------------------------------------------------------------
//second section -Text based area/ logic

  while ( numTurns > 0 ) {    // for loop counts down numTurns 

    

    cout << "Current word: " << word << endl;
    cout << numTurns << " " <<"remain...Enter a letter to guess"; // use for loop to count down numTurns
    cin >> guess;

    numTurns--;
    
    if (processGuess (word, targetWord, guess)> 0) {
        numTurns++;
    }// successful guess do not count for a turn 

    if (strcmp(targetWord, word) == 0) {
      cout << "The word was: " << targetWord << " " <<"You win!" << endl;
        break;
    } //word has been guessed 

    else if (numTurns == 0){
      cout << "Too many turns...You lose!" << endl;
    }


  }
       
}

  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed
  // Print out end of game status

int processGuess(char* word, const char* targetWord, char guess) // our strcmp 
{

int counter = 0;

for (int i = 0; i < strlen(targetWord) ; i++){

    if (guess == targetWord[i]){
        word[i] = targetWord[i];
        counter++; // the char that is guessed
    }

}
//or 
return counter;
}

