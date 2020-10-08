#include <iostream>
#include <string>
#include <cctype>
#include "caesar.h"

//had this already done in high school, kinda scuffed, was in java
//encoding your message
  std::string encryptCaesar(std::string word, int shift) {
    std::string encrypt = "";
    // initializes variable to store unicode
    char letter;
    for (int i = 0; i < word.length(); i++) {
      // Shift one letter at a time
      if(word[i] == ' '){
        letter += ' ';
        encrypt += word[i];
      }
      else if(word[i] < 65){
          letter += word[i];
          encrypt += word[i];
      }
      else{
          letter = word[i];
      }

      // if letter lies between a and z
      if (letter >= 'a' && letter <= 'z') {
        // shifts letter
        letter = (char) (letter + shift);
        //checks to see if it passes z
        if(letter > 'z'){
          letter = (char)(letter + 'a' - 'z' - 1);
        }
        encrypt = encrypt + letter;
      }

      // if letter lies between 'A'and 'Z'
      else if (letter >= 'A' && letter <= 'Z') {
        // shifts letter
        letter = (char) (letter + shift);
        //checks to see if letter passes 'Z'
        if(letter > 'Z'){
          letter = (char)(letter + 'A' - 'Z' - 1);
        }
        encrypt = encrypt + letter;
      }
    }
    return encrypt;
  }

  //my caesar's cipher doesn't use this method but vigenere does
  char shiftChar(char c, int rshift){

    if(isupper(c)){
      c = ((int)c + 26 + rshift - 65) % 26 + 65;
    } 

    //if lower case letters
    else if (islower(c)){
      c = ((int)c + 26 + rshift - 97) % 26 + 97;  
    }
      return c;
  }
  
