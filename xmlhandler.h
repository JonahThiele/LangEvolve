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
#include <memory>


class Xmlhandler {
  private:
    int strtWordAmount;
    pugi::xml_document loadDoc;
    pugi::xml_document outDoc;
    pugi::xml_parse_result tree;

  public:
   Xmlhandler(char* filename);
   std::vector<std::shared_ptr<Word>> GetWords();
   int GetGenerations();
   const std::string GetCharSet();
   const std::string GetVowSet();
   std::string TrimWhiteSpace(std::string);
   void LogWords(std::vector<std::shared_ptr<Word>>);
   std::shared_ptr<Word> Getinheritance(std::string, std::string, std::string, std::string, std::vector<std::shared_ptr<Word>>);
};