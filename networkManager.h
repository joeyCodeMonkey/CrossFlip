#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H
#include <iostream>
#include <curl/curl.h>
#include <string>
#include <vector>
#include <fstream>


class networkManager
{
public:
	networkManager(std::string user, std::string passwd);
	void assign_to_convention();
	std::string retrieveLevel();
	
private:
	static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
	static size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp);
	std::string name;
	std::string password;
	int level;

	std::vector<std::vector<int> > board;
};

#endif
