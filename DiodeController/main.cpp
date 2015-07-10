#include <iostream>
#include <unistd.h>

#include "diode.h"
#include "commutator.h"
#include "commandmanager.h"

#include "command/setledstate.h"
#include "command/getledstate.h"

#include "command/setledcolor.h"
#include "command/getledcolor.h"

#include "command/setledrate.h"
#include "command/getledrate.h"

int main(int argc, char **argv) {
  Commutator commutator;
  CommandManager commandManager;
  
  CommandSetLedState comm1;
  CommandGetLedState comm2;
  
  CommandSetLedColor comm3;
  CommandGetLedColor comm4;
  
  CommandSetLedRate comm5;
  CommandGetLedRate comm6;
  
  commandManager.addCommand(&comm1);
  commandManager.addCommand(&comm2);
  
  commandManager.addCommand(&comm3);
  commandManager.addCommand(&comm4);
  
  commandManager.addCommand(&comm5);
  commandManager.addCommand(&comm6);
  
  Diode diode;
  
  debug_printf(5, "Diode controller started\n");
  
  while (1){
    // получим текст команды
    std::string commandText = commutator.getCommand();
    debug_printf(5, "A command came\n");
    CommandResult result;
    int pid = 0;
    
    if (commandText.length()){
      // найдем нужный класс команды 
      Command * command = commandManager.parse(commandText, pid);
      
      if (command != NULL){
	// выполним команду
	bool f = command->exec(& diode, result);
	
	if (f)
	  debug_printf(5, "Command %s executed successfully\n", command->getKey().c_str());
	else
	  debug_printf(5, "An error occured while executing the command %s\n", command->getKey().c_str());
	
	command->clear();
      }
      else {
	debug_printf(5, "Unknown command\n");
      }
    }
  
    if (pid){
      // проинформируем клиента о результате
      commutator.sendAnswer(pid, result);
    }
  }

  return 0;
}
