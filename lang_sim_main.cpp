#include "Base_word.h"
#include "wordMod.hpp"
#include "xmlhandler.h"
#include <iostream>
#include "Constants.h"
#include <vector>

std::vector<Word> RunGeneration(std::vector<Word> Wordlist, std::string characterSet, std::string vowelSet){
	std::vector<Word> newwordlist;
	WordMod Modhandle(characterSet, vowelSet);
	srand (time(NULL));
	for(int Words = 0; Words < Wordlist.size() - 1; Words++){
		int changed = rand() % 100 + 1;
		if(changed <= PERCENT_CHANGE){
			std::vector<int> WordMask = Modhandle.CreateChangedMask(Wordlist[Words].get_word());
		    std::string newWordstr = Modhandle.ApplyCharMask(Wordlist[Words].get_word(), WordMask);
		    // create a different way to 
		    Word newWord(newWordstr, Wordlist[Words].get_word(), Wordlist[Words].get_meaning());
		    newwordlist.push_back(newWord);

		}
	}
	std::cout << "size of newword list:" << newwordlist.size() << std::endl;
	return newwordlist;
}

std::vector<Word> Run_sim(int generations, std::vector<Word> originDict, std::string characterSet, std::string vowelSet){
	std::vector<Word> WordList;
	for(int WordIndex = 0; WordIndex < originDict.size() - 1; WordIndex++){
		WordList.push_back(originDict[WordIndex]);
	}
	for(int CurrGen = 0; CurrGen < generations; CurrGen++){
		std::vector<Word> NewWordList = RunGeneration(WordList, characterSet, vowelSet);
		for(int WordIndex = 0; WordIndex < NewWordList.size() - 1; WordIndex++){
			WordList.push_back(NewWordList[WordIndex]);
		}
		// debugging word list
		for(int i = 0; i < WordList.size() - 1; i++){
		}
	}
	return WordList;
}

void log_sim(Xmlhandler &handle, std::vector<Word> WordList){
	handle.LogWords(WordList);
	// log all of the new words into an xml file
}
int main(int argc, char *argv[]){
	Xmlhandler handle(argv[1]);
	int generations = handle.GetGenerations();
	std::vector<Word> originDict = handle.GetWords();
	std::string characterSet = handle.GetCharSet();
	std::string vowelSet = handle.GetVowSet();
	std::vector<Word> GeneratedWords = Run_sim(generations, originDict, characterSet, vowelSet);
	log_sim(handle, GeneratedWords);
	return 0;
}
