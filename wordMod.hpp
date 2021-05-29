#pragma once
#include <stdlib.h>  
#include <time.h>    
#include <string.h>
#include "Constants.h"
#include <string>
#include <vector>

class WordMod {
    private:
     char CharacterSet[CHAR_SET_SIZE];
     char VowelChars[MAX_VOWELS];
     int percentCharMutate = PERCENT_CHANGE;
     int charSetSize = CHAR_SET_SIZE;
      
    public:
    WordMod(const char charSet[],const char Vowels[]);
    std::vector<int> CreateChangedMask(std::string);
    std::string ApplyCharMask(std::string, std::vector<int>);
    // apply new meanings

};