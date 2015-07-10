#ifndef COMMANDGETLEDRATE_H
#define COMMANDGETLEDRATE_H
#include "command.h"
#include <vector>
#include <iostream>
#include "tools.h"

class CommandGetLedRate : public Command {
  
public:
  CommandGetLedRate() : Command(){
    key = "get-led-rate";
    clear();
  }
  
  bool parse(std::string commandText){
    if (findKey(commandText, key)){
      return true;
    }
    
    return false;
  }
  
  void clear(){}
  
  bool exec(Diode * diode, CommandResult & result){
    char buf[512];
    snprintf(buf, 512, "%d", diode->getRate());
    
    result.text = buf;
    result.status = true;
    
    return result.status;
  }
};

#endif // COMMANDGETLEDRATE_H
