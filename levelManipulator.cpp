#include "levelManipulator.h"

levelManipulator::levelManipulator(std::string file){

  this->html = file;
  //std::cout<<this->html<<std::endl;	
  
}


std::string levelManipulator::retrieveLevel(std::string html)
{
  
  std::string s = html
  std::smatch m;
  std::regex e("\\b(board)([^ ]*)"); 
 // std::regex e ("\\b(sub)([^ ]*)");   // matches words beginning by "sub"

  std::cout << "Target sequence: " << s << std::endl;
  std::cout << "Regular expression: /\\b(sub)([^ ]*)/" << std::endl;
  std::cout << "The following matches and submatches were found:" << std::endl;

  while (std::regex_search (s,m,e)) {
    for (auto x:m) std::cout << x << " ";
    std::cout << std::endl;
    s = m.suffix().str();
  }
  return s;
}


