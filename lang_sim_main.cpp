#include "Base_word.h"
#include "wordMod.hpp"
#include "xmlhandler.h"
#include <iostream>
#include "Constants.h"
#include <vector>
#include <memory>

std::vector<std::shared_ptr<Word>> RunGeneration(std::vector<std::shared_ptr<Word>> Wordlist, std::string characterSet, std::string vowelSet, MeaningHandle* mhandle){
	std::vector<std::shared_ptr<Word>> newwordlist;
	std::unique_ptr<WordMod> Modhandleptr(new WordMod(characterSet, vowelSet));
	srand (time(NULL));
	for(int Words = 0; Words < Wordlist.size() - 1; Words++){
		int changed = rand() % 100 + 1;
		if(changed <= PERCENT_CHANGE){
			std::vector<int> WordMask = Modhandleptr->CreateChangedMask(Wordlist[Words]->get_word());
		    std::string newWordstr = Modhandleptr->ApplyCharMask(Wordlist[Words]->get_word(), WordMask);
			int meaningchanged = rand() % 100 + 1;
			if(meaningchanged <= MEANING_CHANGE_DEFAULT){
				//set it hard coded to false 
				mhandle->GetMeaning(false,newWordstr);
			}
		    // create a different way to 
		    std::shared_ptr<Word> newwordptr(new Word(newWordstr, Wordlist[Words]->get_word(), Wordlist[Words]->get_meaning()));
		    newwordlist.push_back(newwordptr);

		}
	}
	std::vector<std::shared_ptr<Word>> purgedwordlist = Modhandleptr->DeleteRepeats(newwordlist);
	std::cout << "size of newword list:" << newwordlist.size() << std::endl;
	return purgedwordlist;
}

std::vector<std::shared_ptr<Word>> Run_sim(int generations, std::vector<std::shared_ptr<Word>> originDict, std::string characterSet, std::string vowelSet, MeaningHandle* mhandle){
	std::vector<std::shared_ptr<Word>> WordList;
	for(int WordIndex = 0; WordIndex < originDict.size() - 1; WordIndex++){
		WordList.push_back(originDict[WordIndex]);
	}
	for(int CurrGen = 0; CurrGen < generations; CurrGen++){
		std::vector<std::shared_ptr<Word>> NewWordList = RunGeneration(WordList, characterSet, vowelSet, mhandle);
		for(int WordIndex = 0; WordIndex < NewWordList.size() - 1; WordIndex++){
			WordList.push_back(NewWordList[WordIndex]);
		}
		// debugging word list
		for(int i = 0; i < WordList.size() - 1; i++){
		}
	}
	return WordList;
}

void log_sim(Xmlhandler * handle, std::vector<std::shared_ptr<Word>> WordList){
	// log all of the new words into an xml file
	handle->LogWords(WordList);
}

int main(int argc, char *argv[]){
	Xmlhandler * handleptr = new Xmlhandler(argv[1]);
	// second arg is default dictionary of terms
	MeaningHandle * Mhandleptr = new MeaningHandle(argv[2]);
	int generations = handleptr->GetGenerations();
	std::vector<std::shared_ptr<Word>> originDict = handleptr->GetWords();
	std::string characterSet = handleptr->GetCharSet();
	std::string vowelSet = handleptr->GetVowSet();
	std::vector<std::shared_ptr<Word>> GeneratedWords = Run_sim(generations, originDict, characterSet, vowelSet, Mhandleptr);
	log_sim(handleptr, GeneratedWords);
	return 0;
}
