#pragma once
#include <stdlib.h>  
#include <time.h>    
#include <string.h>
#include "Constants.h"
#include <string>
#include <vector>
#include <algorithm>
#include "Base_word.h"
#include "meaninghandler.hpp"
#include <iostream>

class WordMod {
    private:
     std::string CharacterSet;
     std::string VowelChars;
     int percentCharMutate = PERCENT_CHANGE;
     int charSetSize;
     int vowSetSize;
      
    public:
    WordMod(const std::string CharSet,const std::string VowelSet);
    std::vector<int> CreateChangedMask(std::string);
    std::string ApplyCharMask(std::string, std::vector<int>);
    //create new word
    Word CreateNewWord(MeaningHandle);
    // apply new meanings

    // purge repeat words
    std::vector<Word> DeleteRepeats(std::vector<Word>);

};