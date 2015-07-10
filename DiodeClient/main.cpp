#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "define.h"

// установка флагов
void clr_fl(int fd, int flags){
  int val;

  if ((val = fcntl(fd, F_GETFL, 0)) < 0)
    printf("fcntl F_GETFL error");    

  val &= ~flags;

  if (fcntl(fd, F_SETFL, val) < 0)
    printf("fcntl F_SETFL error");
}

int main(int argc, char **argv) {
  int fifo;
  int answerFifoRead, answerFifoWrite;
  int pid = getpid();
  
  if ((fifo = open(FIFO, O_WRONLY | O_NONBLOCK)) < 0){
    printf("Unable to open fifo. Check the Controller's state.\n");
    exit(1);
  }
  
  char answerFifoName[1024];
  snprintf(answerFifoName, 1024, "/tmp/answer_%d_%s", pid, ANSWER_FIFO_KEY);
  unlink(answerFifoName);
  
  // откроем ответный пайп на чтение и запись  
  if (mkfifo(answerFifoName, O_CREAT | S_IRWXU) < 0){
    printf("Unable to create temp answer fifo\n");
    exit(2);
  }
  
  if ((answerFifoRead = open(answerFifoName, O_RDONLY | O_NONBLOCK)) < 0){
    printf("open read fifo error\n");
    exit(3);
  }
  
  if ((answerFifoWrite = open(answerFifoName, O_WRONLY)) < 0){
   printf("open write fifo error\n");
   exit(3);
  }
  
  clr_fl(answerFifoRead, O_NONBLOCK);
    
  std::string command;
  std::cout << "Enter your command here: \n";
  
  while(std::cin.good()){
    std::getline (std::cin, command);
    
    if (command.length() > 490) {
      command = command.substr(0, 490);
    }
    
    char buf[512];    
    snprintf(buf, 512, "%d;%s", pid, command.c_str());
    
    int n = 0;

    if((n = write(fifo, buf, strlen(buf))) == -1){
      printf("send command error\n");
    }
    
    n = 0;
    char buf2[512];
    buf2[0] = '\0';
    
    if((n = read(answerFifoRead, &buf2, sizeof(buf))) == -1){
      printf("read answer err\n");
    }
    else {
      buf2[n] = '\0';
      
      std::cout << command << " -> " << buf2 << std::endl;
    }
  }
  
  close(answerFifoRead);
  close(answerFifoWrite);
  
  close(fifo); 
  
  return 0;
}
