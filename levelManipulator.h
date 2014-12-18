#ifndef LEVELMANIPULATOR_H
#define LEVELMANIPULATOR_H

#include <iostream>
#include <regex>
#include <string>
#include <vector>

class levelManipulator{
	
public:
	levelManipulator(std::string html);

	std::string retrieveLevel(std::string html);
	
private:
	std::vector<std::vector<int> > level;
	std::string html;
};

#endif
