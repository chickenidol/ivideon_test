#ifndef COMMANDRESULT_H
#define COMMANDRESULT_H
#include <string>

/**
 * результат выполнения команды на конкретном диоде
 */
class CommandResult {
public:
  CommandResult();
  
  std::string text;
  bool status;
};

#endif // COMMANDRESULT_H
