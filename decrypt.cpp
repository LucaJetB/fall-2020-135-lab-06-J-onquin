#include <iostream>
#include <cctype>
#include <string>
#include "vigenere.h"
#include "caesar.h"
#include "decrypt.h"

std::string decryptCaesar(std::string word, int shift){
    std::string decrypt = "";
    // initializes variable to store unicode
    char letter;
    for (int i = 0; i < word.length(); i++) {
      // Shifts one letter at a time
      if(word[i] == ' '){
        letter += ' ';
        decrypt += word[i];
      }
      else if(word[i] < 65){
          letter += word[i];
          decrypt += word[i];
      }
      else{
          letter = word[i];
      }

      // if letter lies between a and z
      if (letter >= 'a' && letter <= 'z') {
        // shifts letter
        letter = (char) (letter - shift);
        //checks to see if it passes z
        if(letter < 'a'){
          letter = (char)(letter - 'a' + 'z' + 1);
        }
        decrypt = decrypt + letter;
      }

      // if letter lies between 'A'and 'Z'
      else if (letter >= 'A' && letter <= 'Z') {
        // shifts letter
        letter = (char) (letter - shift);
        //checks to see if letter passes 'Z'
        if(letter < 'A'){
          letter = (char)(letter - 'A' + 'Z' + 1);
        }
        decrypt = decrypt + letter;
      }
    }
    return decrypt;
  }

std::string decryptVigenere(std::string encryption, std::string keyword){

	std::string plaintext;
	int size = encryption.size();
	int shift;
	int index = 0;

	for(int i = 0; i < size; i++){
		shift = (int)(keyword[index % keyword.size()] - 97);
	    if(!isalpha(encryption[i])){
	      index--;
	    }
	    plaintext += shiftChar(encryption[i], 26 - shift);
	    index++;
	}
	return plaintext;
}