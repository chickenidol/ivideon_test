#ifndef COMMANDSETLEDSTATE_H
#define COMMANDSETLEDSTATE_H
#include "command.h"
#include <vector>
#include <iostream>
#include "tools.h"

class CommandSetLedState : public Command {
  int state;
  
public:
  CommandSetLedState() : Command(){
    key = "set-led-state";
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
    
    if (split[1] == "on"){
      state = 0;
    }
    else if (split[1] == "off"){
      state = 1;
    }
    else 
      return false;
    
    return true;
  }
  
  void clear(){
    state = -1;
  }
  
  bool exec(Diode * diode, CommandResult & result){
    if (state == -1){
      result.status = false;
      return false;
    }
    
    result.status = true;
    
    if (state == 0){
      diode->setState(true);      
    }
    else {
      diode->setState(false);      
    }
    
    return true;
  }
};

#endif // COMMANDSETLEDSTATE_H
