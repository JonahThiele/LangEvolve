#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>  
#include <time.h>
#include <windows.h>
class MeaningHandle{
    private:
     std::vector<std::string> meaninglist;
     std::vector<std::string> nearmeaninglist;

    public:
     MeaningHandle(std::string);
     std::string GetMeaning(bool, std::string);
     std::string GetRandomMeaning();
     std::string GetNearMeaning(std::string);
};