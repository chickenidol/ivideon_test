#include "commandmanager.h"
#include <iostream>
#include <stdlib.h>

CommandManager::CommandManager(){}

void CommandManager::addCommand(Command * command){
  commands.push_back(command);
}

Command * CommandManager::parse(const std::string & commandText, int & pid){
  std::size_t found = commandText.find(';');
  std::string clearCommandText;

  if (found != std::string::npos){    
    pid = atoi(commandText.substr(0, found).c_str());
    clearCommandText = commandText.substr(found + 1, commandText.length());
  }
  
  if (pid && clearCommandText.length()){
    for (std::vector<Command *>::const_iterator i = commands.begin(); i != commands.end(); ++i){
      Command * command = *i;
      
      if (command->parse(clearCommandText)){
	return command;
      }
    }
  }
  
  return NULL;
}
