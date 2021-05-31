#include "wordMod.hpp"

WordMod::WordMod(const std::string CharSet,const std::string VowelSet){
    srand (time(NULL));
    charSetSize = CharSet.size();
    vowSetSize = VowelSet.size();
    CharacterSet = CharSet;
    VowelChars = VowelSet;
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
    std::vector<int> changedCharsMask;
    for( int currCharPos = 0; currCharPos < Word.length()-1; currCharPos++){
        int maskNum = rand() % 100 + 1;
        if(std::find(VowelChars.begin(), VowelChars.end(), Word[currCharPos]) != VowelChars.end()){
            changedCharsMask.push_back(0);
        }
        else if (maskNum <= PERCENT_CHANGE){
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

Word WordMod::CreateNewWord(MeaningHandle meaningHandle){
    // generate meaning
    std::string strmeaning = meaningHandle.GetMeaning(false, "null");
    int wordlength = rand() % 20 + 1;
    std::string strWord;
    for( int i = 0; i < wordlength; i++){
        char generatedChar = CharacterSet[rand() % charSetSize];
        strWord += generatedChar;
    }
    Word newword(strWord, strWord, strmeaning);
    return newword;
}

std::vector<Word> WordMod::DeleteRepeats(std::vector<Word> wordlist){
    for(int currword = 0; currword < wordlist.size(); currword++){
        wordlist.erase(std::remove(wordlist.begin(), wordlist.end(), wordlist[currword]), wordlist.end());
    }
    return wordlist;
}