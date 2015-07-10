#ifndef COMMAND_H
#define COMMAND_H
#include "diode.h"
#include "commandresult.h"
#include <string>

/**
 * Базовый класс команды
 */
class Command {
protected:
  bool findKey(std::string commandText, std::string key){
    std::size_t found = commandText.find(key);
    
    if (found != std::string::npos && found == 0){
      return true;
    }
    
    return false;
  }
  
  std::string key;
  
public:
  Command(){}
  // проанализировать текст команды и определить соответствует ли он конкретной команде, если да - разобрать параметры
  virtual bool parse(std::string commandText) = 0;
  
  // очистка параметров
  virtual void clear() = 0;
  
  // выполнить команду на конкретном диоде
  virtual bool exec(Diode * diode, CommandResult & result) = 0;
  
  // для отладки
  std::string getKey(){
    return key;
  }
  
  virtual ~Command(){}
};

#endif // COMMAND_H
