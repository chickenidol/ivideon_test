#ifndef COMMANDGETLEDSTATE_H
#define COMMANDGETLEDSTATE_H
#include "command.h"
#include <vector>
#include <iostream>
#include "tools.h"

class CommandGetLedState : public Command {
 
public:
  CommandGetLedState() : Command(){
    key = "get-led-state";
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
    if (diode->getState()){
      result.text = "on";
    }
    else {
      result.text = "off";
    }
    
    result.status = true;
    
    return result.status;
  }
};

#endif // COMMANDGETLEDSTATE_H
