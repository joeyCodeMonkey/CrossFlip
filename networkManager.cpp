#include "networkManager.h"

networkManager::networkManager(std::string name, std::string password){
  this->name = name;
  this->password = password;
}

std::string networkManager::retrieveLevel(){
  
  FILE *f;
  std::string targetURL_base = "http://www.hacker.org/runaway/index.php?name=";
  targetURL_base = targetURL_base.append(this->name).append("&password=").append(this->password);  
  CURL *curl;
  curl = curl_easy_init();
  
  if(curl) {
	f = fopen("currentlevel","wb");
    curl_easy_setopt(curl, CURLOPT_URL, targetURL_base.c_str());
    /* example.com is redirected, so we tell libcurl to follow redirection */ 
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
	/* Perform the request, res will get the return code */ 
	curl_easy_perform(curl);
    fclose(f);
  }
  curl_easy_cleanup(curl); 
  
  std::ifstream ifs("currentlevel");
  std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
  
  return content; 
}

//std::string networkManager::level_to_String()
void networkManager::assign_to_convention()
{
  std::ifstream ifs("currentlevel");
  std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
  std::cout<<content<<std::endl;
}
/*
networkManager::setSolution(std::string solution){

}*/
