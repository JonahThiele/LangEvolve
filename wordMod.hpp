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
     int charSetSize;
     int vowSetSize;
      
    public:
    WordMod(const std::string CharSet,const std::string VowelSet);
    std::vector<int> CreateChangedMask(std::string);
    std::string ApplyCharMask(std::string, std::vector<int>);
    // apply new meanings

};