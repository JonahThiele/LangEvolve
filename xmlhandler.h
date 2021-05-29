#pragma once
#include "pugixml-1.11/src/pugixml.hpp"
#include "Base_word.h"
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
   std::string TrimWhiteSpace(std::string);
   int GetGenerations();
   void LogWords(std::vector<Word>);
};