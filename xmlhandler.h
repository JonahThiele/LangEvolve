#pragma once
#include "pugixml-1.11/src/pugixml.hpp"
#include "Base_word.h"
//#include "verb.h"
//#include "noun.h"
//#include "adjective.hpp"
//#include "adverb.hpp"
//#include "conjunction.hpp"
#include <vector>
#include <iostream>
#include <algorithm>


class Xmlhandler {
  private:
    int strtWordAmount;
    pugi::xml_document loadDoc;
    pugi::xml_document outDoc;
    pugi::xml_parse_result tree;

  public:
   Xmlhandler(char* filename);
   std::vector<Word> GetWords();
   int GetGenerations();
   const std::string GetCharSet();
   const std::string GetVowSet();
   std::string TrimWhiteSpace(std::string);
   void LogWords(std::vector<Word>);
   Word Getinheritance(std::string, std::string, std::string, std::string, std::vector<Word>);
};