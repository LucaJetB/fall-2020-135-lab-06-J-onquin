#include <iostream>
#include <cmath>
#include "caesar.h"

//finds letter occurence
int frequency(std::string str, char letter){
    int count = 0;
    for(int i = 0; i < str.length(); i++){
        //counts however said letters are in the string
        if(str[i] == letter){
            count++;
        }
    }
    //std::cout << count << std::endl;
    return count;
}

//finds length of string
double length(std::string str){
    int length = 0;
    for(int i = 0; i < str.length(); i++){
        if(isalpha(str[i])){
            length++;
        }
    }
    //std::cout << length << std::endl;
    return length;
}

std::string decode(std::string str){
    //a-z all lowercase
    char letter[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    //converted to decimal because ill be working with decimals not percents with the above 2 functions
    double engFreq [26] = {0.082,0.015,0.028,0.043,0.13,0.022,0.02,0.061,0.07,0.0015,0.0077,0.04,0.024,0.067,0.075,0.019,0.00095,0.06,0.063,0.091,0.028,0.0098,0.024,0.0015,0.02,0.00074};
    //stores the frequency of every letter in the string
    double freq[26];
    //stores answer to distance formula
    double sum = 0;
    //stores "sum" calculations
    double distance[26];


    ////i was so confused for this part so I looked at
    //@ccheung's code and still am kekw
    for(int i = 0; i < 26; i++){
        freq[i] = frequency(str, letter[i])/26;//length(str);
        //std::cout << freq[i] <<std::endl;
    }
    
     for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            sum += sqrt(pow(freq[j], 2) + pow(engFreq[j], 2));
        }
            distance[i] = sum;
            sum = 0;
            str = encryptCaesar(str, 1);
            std::cout << str << std::endl;
     }

    //find the smallest distance in distance array
    double min = distance[0];
    int index = 0;
    std::cout << distance[0] << std::endl;
    for(int i = 1; i < 26; i++){
        if(distance[i] < min){
            min = distance[i];
            index = i;
        }
        //std::cout << index << std::endl;
        //std::cout << distance[i] << std::endl;
    }
    std::cout << "test" << std::endl;
    return encryptCaesar(str, index);
}