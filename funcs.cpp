#include <iostream>
#include "funcs.h"

// add functions here
void test_ascii(std::string word){
    for(int i = 0; i < word.size(); i++){
        std::cout << word[i] << " " << (int)word[i] << std::endl;
    }
}

