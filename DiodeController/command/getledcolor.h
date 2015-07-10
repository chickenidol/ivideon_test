#ifndef COMMANDGETLEDCOLOR_H
#define COMMANDGETLEDCOLOR_H
#include "command.h"
#include <vector>
#include <iostream>
#include "tools.h"

class CommandGetLedColor : public Command {
 
public:
  CommandGetLedColor() : Command(){
    key = "get-led-color";
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
    if (diode->getColor() == Diode::blue){
      result.text = "blue";
      result.status = true;
    }
    else if (diode->getColor() == Diode::green){
      result.text = "green";
      result.status = true;
    }
    else if (diode->getColor() == Diode::red){
      result.text = "red";
      result.status = true;
    }
    else {
      result.status = false;
    }
    
    return result.status;
  }
};

#endif // COMMANDGETLEDCOLOR_H
