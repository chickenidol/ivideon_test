#include "commutator.h"
#include <iostream>
#include <cstdio>

Commutator::Commutator(){
  unlink(FIFO);
  
  if (mkfifo(FIFO, O_CREAT | S_IRWXU) < 0){
    debug_printf(1, "make fifo: %s error\n", FIFO);
  }
  
  if ((fifoRead = open(FIFO, O_RDONLY | O_NONBLOCK)) < 0){
    debug_printf(1, "open read fifo %s error\n", FIFO);
  }
  
  if ((fifoWrite = open(FIFO, O_WRONLY)) < 0){
    debug_printf(1, "open write fifo %s error\n", FIFO);
  }
  
  clr_fl(fifoRead, O_NONBLOCK);
}

std::string Commutator::getCommand(){
  int n = 0;
  char buf[512];
  buf[0] = '\0';
  
  if (fifoRead > 0){
    if((n = read(fifoRead, &buf, sizeof(buf))) == -1){
      debug_printf(1, "read fifo %s error\n", FIFO);
    }
    else {
      buf[n] = '\0';
    }
  }
  
  return trim(buf);
}

int Commutator::sendAnswer(int pid, const CommandResult & result){
  std::string answer;
  
  if (result.status){
    answer = "OK";
  }
  else {
    answer = "FAILED";
  }
  
  if (result.text.length()){
    answer += " " + result.text;
  }
  
  int answerFifo;
 
  char answerFifoName[1024];
  snprintf(answerFifoName, 1024, "/tmp/answer_%d_%s", pid, ANSWER_FIFO_KEY);
 
  if ((answerFifo = open(answerFifoName, O_WRONLY | O_NONBLOCK)) < 0){
    debug_printf(1, "open write fifo %s error\n", answerFifoName);
  }
 
  int n = 0;
  if((n = write(answerFifo, answer.c_str(), answer.length())) == -1){
    debug_printf(1, "write fifo %s error\n", answerFifoName);
  }
  
  close(answerFifo);
  
  return 0;
}
