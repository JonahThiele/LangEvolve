#pragma once
#include <string>
#define BASE_LENGTH 5

class Word {
  private:
   std::string word;
   std::string root;
   std::string meaning;
   int iteration;

  public:
   std::string get_word(){return word;}
   std::string get_root(){return root;}
   std::string get_meaning(){return meaning;}
   Word(std::string input_word, std::string input_root, std::string input_meaning){
	 word = input_word;
	 root = input_root;
	 meaning = input_meaning;
	 
   }
  
  
};