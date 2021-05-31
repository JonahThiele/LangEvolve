#include "meaninghandler.hpp"
// helper functions
void waitforPythonIO(int milli) {

   clock_t end_time;
   end_time = clock() + milli * CLOCKS_PER_SEC/1000;
   while (clock() < end_time) {

   }
}

MeaningHandle::MeaningHandle(std::string filename){
    srand(time(NULL));
    std::string word;
	std::ifstream infile;
	infile.open (filename);
    while (std::getline(infile, word)){
        std::istringstream iss(word);
        int a, b;
        if (!(iss >> a >> b)) { break; } 
        meaninglist.push_back(word);
    }
	infile.close();
}

std::string MeaningHandle::GetMeaning(bool nearmeaning, std::string word){
    if(nearmeaning){
        std::string meaning = GetNearMeaning(word);
        return meaning;
    }
    else{
        std::string meaning = GetRandomMeaning();
        return meaning;
    }
}

std::string MeaningHandle::GetRandomMeaning(){
    int randnum = rand() % meaninglist.size();
    return meaninglist[randnum];
}

std::string MeaningHandle::GetNearMeaning(std::string word){
    srand(time(NULL));
    std::string arguments = "python38 thesaurus.py " + word;
    const char * Carg = arguments.c_str();
    system(Carg);
    waitforPythonIO(1000);
    std::string storeWord;
	std::ifstream infile;
    // this is the deafualt name of the generated file
	infile.open ("thesaurus.txt");
    while (std::getline(infile, storeWord)){
        std::istringstream iss(word);
        int a, b;
        if (!(iss >> a >> b)) { break; } 
        nearmeaninglist.push_back(word);
    }
	infile.close();
    int randnum = rand() % nearmeaninglist.size();
    return nearmeaninglist[randnum];
}