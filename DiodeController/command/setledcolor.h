#ifndef COMMANDSETLEDCOLOR_H
#define COMMANDSETLEDCOLOR_H
#include "command.h"
#include <vector>
#include <iostream>
#include "tools.h"

class CommandSetLedColor : public Command {
  Diode::color current_color;
  
public:
  CommandSetLedColor() : Command(){
    key = "set-led-color";
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
    
    if (split[1] == "red"){
      current_color = Diode::red;
    }
    else if (split[1] == "green"){
      current_color = Diode::green;
    }
    else if (split[1] == "blue"){
      current_color = Diode::blue;
    }
    else 
      return false;

    return true;
  }
  
  void clear(){
    current_color = Diode::undefined;
  }
  
  bool exec(Diode * diode, CommandResult & result){
    if (current_color != Diode::undefined) {
      diode->setColor(current_color);
      result.status = true;
    }
    else {
      result.status = false;
    }
    
    return result.status;
  }
};

#endif // COMMANDSETLEDCOLOR_H
