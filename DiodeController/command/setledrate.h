#ifndef COMMANDSETLEDRATE_H
#define COMMANDSETLEDRATE_H
#include "command.h"
#include <vector>
#include <iostream>
#include "tools.h"

class CommandSetLedRate : public Command {
  int rate;
  
public:
  CommandSetLedRate() : Command(){
    key = "set-led-rate";
    clear();
  }
  
  bool parse(std::string commandText){
    if (!findKey(commandText, key)){
      return false;
    }
    
    std::vector<std::string> split;  
    explode(commandText, ' ', split);
    
    if (split.size() < 2){ 
      return false;
    }
      
    rate = atoi(split[1].c_str());
    return true;
  }
  
  void clear(){
    rate = -1;
  }
  
  bool exec(Diode * diode, CommandResult & result){
    if (rate >= 0) {
      diode->setRate(rate);
      result.status = true;
    }
    else {
      result.status = false;
    }

    return result.status;
  }
};

#endif // COMMANDSETLEDRATE_H
