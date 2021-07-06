#include "xmlhandler.h"

Xmlhandler::Xmlhandler(char* filename){
    tree = loadDoc.load_file(filename);
}

int Xmlhandler::GetGenerations(){
    int generations = loadDoc.child("Generations").text().as_int();
    return generations;
}

const std::string Xmlhandler::GetCharSet(){
    std::string charSet = loadDoc.child("CharacterSet").text().as_string();
    if(charSet == "DEFAULT"){
        std::string vowSet = "abcdefghijklmnopqrstuvwxyz";
    }
    const std::string CcharSet = charSet;
    return CcharSet;
}

const std::string Xmlhandler::GetVowSet(){
    std::string vowSet = loadDoc.child("VowelSet").text().as_string();
    if(vowSet == "DEFAULT"){
        std::string vowSet = "aeou";
    }
    const std::string CvowSet = vowSet;
    return CvowSet;
}


std::vector<std::shared_ptr<Word>> Xmlhandler::GetWords(){
    std::vector<std::shared_ptr<Word>> origin_dict;
    pugi::xml_node wordList = loadDoc.child("Word_List");
    for (pugi::xml_node xmlWord = loadDoc.child("Word_List").child("Word"); xmlWord; xmlWord = xmlWord.next_sibling("Word")){
        std::string strword = TrimWhiteSpace(xmlWord.text().as_string());
        pugi::xml_node xmlMeaning = xmlWord.child("Meaning");
        std::string strmeaning = xmlMeaning.text().as_string();
        pugi::xml_node xmlType = xmlWord.child("Type");
        std::string strtype = xmlType.text().as_string();
        std::shared_ptr<Word> newwordptr(new Word(strword, strword, strmeaning));
        origin_dict.push_back(newwordptr);

    }
    return origin_dict;
}

 void Xmlhandler::LogWords(std::vector<std::shared_ptr<Word>> Words){
      pugi::xml_document outdoc;
      auto declarationNode = outdoc.append_child(pugi::node_declaration);
      declarationNode.append_attribute("version")    = "1.0";
      declarationNode.append_attribute("encoding")   = "UTF-8";
      auto root = outdoc.append_child("OutPut_Words");
      for(int WordIndex = 0; WordIndex < Words.size(); WordIndex++){
          auto outword = root.append_child("Word");
          auto outword_val = outword.text().set(Words[WordIndex]->get_word().c_str());
          auto outmeaning = outword.append_child("Meaning");
          auto outmeaning_val = outmeaning.text().set(Words[WordIndex]->get_meaning().c_str());
      }
      bool saveSucceeded = outdoc.save_file("out.xml");

}

std::string Xmlhandler::TrimWhiteSpace(std::string Word){
    std::vector<char> whitespace {' ','\n','\t','\v','\b','\r','\f','\a', '\0'};
    for(int currchar = 0; currchar < Word.size() - 1; currchar++){
        if(std::find(whitespace.begin(), whitespace.end(), Word[currchar]) != whitespace.end()){
            Word.erase(Word.begin() + currchar);
            currchar--;
        }
    }
    return Word;
}

/*Word Xmlhandler::Getinheritance(std::string type, std::string root, std::string strword, std::string meaning, std::vector<Word> originDict){
    if(type == "Noun"){
       Noun newword()

    }
    else if(type == "Adjective"){

    }
    else if(type == "Verb"){

    }
    else if(type == "Adverb"){

    }
    else if(type == "Conjunction"){

    }
}*/