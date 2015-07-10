#include "tools.h"

std::string trimLeft(const std::string & input){
  std::string exit = input;
  int pos = 0;
  
  for (std::string::const_iterator i = exit.begin(); i != exit.end(); ++i){
    if (*i == ' ' || *i == '\n')
      pos++;
    else
      break;
  }
  
  if (pos)
    exit = exit.substr(pos, exit.size());
  
  return exit;
}

std::string trimRight(const std::string & input){
  std::string exit = input;
  
  int pos = 0;
  if (exit.size()){
    std::string::const_iterator i = exit.end();
    
    do {
      --i;
      
      if (*i == ' ' || *i == '\n')
	pos++;
      else
	break;
      
    } while (i != exit.begin());
    
    if (pos)
      exit = exit.substr(0, exit.size() - pos);
  }
  
  return exit;
}
  
std::string trim(const std::string & input){
  return trimRight(trimLeft(input));
}

void explode(const std::string & input, char sep, std::vector<std::string> & output) {
  std::istringstream inputstrm(input);

  std::string temp_storage;
  while (std::getline(inputstrm, temp_storage, sep))
      output.push_back(temp_storage);
}


void clr_fl(int fd, int flags){
  int val;

  if ((val = fcntl(fd, F_GETFL, 0)) < 0)
    debug_printf(3, "fcntl F_GETFL error");    

  val &= ~flags;

  if (fcntl(fd, F_SETFL, val) < 0)
    debug_printf(3, "fcntl F_SETFL error");
}



void debug_printf(int i, const char * format, ...)
{
  if (i <= LOG_LEVEL) {
    va_list argptr;
    va_start(argptr, format);
    vfprintf(stderr, format, argptr);
    va_end(argptr);
  }
}