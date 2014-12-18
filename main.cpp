#include "networkManager.h"
#include "levelManipulator.h"
#include <iostream>
#include <curl/curl.h>
#include <vector>
#include <termios.h>
#include <unistd.h>
#include <fstream>

std::string login()
{
  std::string password;
  termios tty;

  std::cout<<"password:";
  tcgetattr(STDIN_FILENO, &tty);
  /* we want to disable echo */
  tty.c_lflag &= ~ECHO;
  tcsetattr(STDIN_FILENO, TCSANOW, &tty);
  std::cin>> password;
  tcgetattr(STDIN_FILENO, &tty);
  /* we want to reenable echo */
  tty.c_lflag |= ECHO;
  tcsetattr(STDIN_FILENO, TCSANOW, &tty);
  return password;
  
}

int main(int argc, char *argv[])
{
  std::string level;
  std::fstream f;
  if(argc<=1){
    std::cout<<"Error:"<<std::endl;
    std::cout<<"username"<<" requiered"<<std::endl;
    return 0;
  }
  
  networkManager netstuff(argv[1],login());
  level = netstuff.retrieveLevel();
  //netstuff.assign_to_convention();
  levelManipulator manni(level);
  manni.retrieveLevel(level);
  
  return 0;
}

