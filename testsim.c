#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

//usage: testsim int1 int2. int1 is sleep time and int2 is repeat factor

int main(int argc, char* argv[]){
  int time = atoi(argv[1]);
  int num = atoi(argv[2]);
  int i;
  
  pid_t pid = getpid();
  
  for(i=0; i < num; i++){
   
    //sleep specified amount of time 
    fprintf(stderr, "waiting %d seconds\n", time); 
    sleep(time);
    
    //print proccesses pid to stderror
    fprintf(stderr, "loop number: %d in process ID:%ld\n",
    i+1, pid);
  }
  return 0;

}