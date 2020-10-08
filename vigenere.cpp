#include <iostream>
#include <cctype>
#include <string>
#include "vigenere.h"
#include "caesar.h"

std::string encryptVigenere(std::string plaintext, std::string keyword){

    std::string cipher;
    int size = plaintext.size();
    int shift;
    int index = 0;

    for(int i = 0; i < size; i++){
        shift = (int)(keyword [index % keyword.size()] - 97);
        if(!isalpha(plaintext[i])){
            index--;
        }
        cipher += shiftChar(plaintext[i], shift);
        index++;
    }
  return cipher;
}