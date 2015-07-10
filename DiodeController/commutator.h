#ifndef COMMUTATOR_H
#define COMMUTATOR_H
#include "commandresult.h"
#include <string>
#include <unistd.h>

#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h> 

#include <sys/types.h>
#include <sys/stat.h>
#include "define.h"
#include "tools.h"


/**
 * Класс организующий вопросы коммуникации
 */
class Commutator {
  int fifoRead, fifoWrite;
  
public:
  Commutator();
  
  std::string getCommand();
  
  int sendAnswer(int PID, const CommandResult &);
};

#endif // COMMUTATOR_H
