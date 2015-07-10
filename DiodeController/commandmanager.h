#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H
#include "command.h"
#include <vector>

/**
 * Класс, управляющий набором команд
 */
class CommandManager {
  std::vector <Command * > commands;
public:
  CommandManager();
  
  void addCommand(Command * command);
  
  Command * parse(const std::string & commandText, int & pid);
};

#endif // COMMANDMANAGER_H
