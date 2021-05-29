#include "wordMod.hpp"
#include <iostream>

WordMod::WordMod(const std::string CharSet,const std::string VowelSet){
    // copy over character set to class
    charSetSize = CharSet.size();
    vowSetSize = VowelSet.size();
    for(int currChar = 0; currChar < CharSet.size() - 1; currChar++){
        CharacterSet[currChar] = CharSet[currChar];
    }
    // copy over vowel set to class
    for(int currVowel = 0; currVowel < VowelSet.size() - 1; currVowel++){
        CharacterSet[currVowel] = VowelSet[currVowel];
    }
}

// debug func
void printVec(std::vector<int> Vec, std::string message){
    std::cout << message;
    for(int i = 0; i < Vec.size() - 1; i++){
        std::cout << Vec[i] << ",";
    }
    std::cout << std::endl;
}

std::vector<int> WordMod::CreateChangedMask(std::string Word){
    srand (time(NULL));
    std::vector<int> changedCharsMask;
    for( int currCharPos = 0; currCharPos < Word.length()-1; currCharPos++){
        int maskNum = rand() % 100 + 1;
        if (maskNum <= PERCENT_CHANGE){
            changedCharsMask.push_back(1);
        }
        else{
            changedCharsMask.push_back(0);
        }

    }
    printVec(changedCharsMask, "MASKVAL:");
    std::cout << Word << std::endl;
    return changedCharsMask;
}
std::string WordMod::ApplyCharMask(std::string Word, std::vector<int> mask){
    std::string NewWord = "";
    srand (time(NULL));
    for(int WordIndex = 0; WordIndex < Word.length()-1; WordIndex++){
        if(mask[WordIndex] == 1){
            int Charnum = rand() % charSetSize - 1;
            NewWord += CharacterSet[Charnum];
        }
        else{
            NewWord += Word[WordIndex];

        }
    }
    return NewWord;
}