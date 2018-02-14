#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

//prototypes
int makeargv(char *s, char *delimiters, char ***argvp);


int main  (int argc, char* argv[]){
  pid_t childpid = 0;
  int i, pr_limit;
  
  int pr_count = 0;
  
  //check for correct command line arguments 
  if (argc !=2){
    fprintf(stderr, "Usage: %s processes\n", argv[0]);
    return 1;
  }
  //max number of children
  pr_limit = atoi(argv[1]);
  
  
  while(fgets != NULL){
    if(pr_count == pr_limit){
      wait(NULL);
      pr_count--;
    }
      
  }
  //for (i = 1; i < n; i++)
    //if ((childpid = fork()) <=0)
      //break;
  
  fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
    i, (long)getpid(), (long)getpid(), (long)childpid);
  return 0;

}
/*
*  Make argv array (*arvp) for tokens in s which are separated by
*  delimiters.   Return -1 on error or the number of tokens otherwise.
*/
int makeargv(char *s, char *delimiters, char ***argvp){
  char *t;
  char *snew;
  int numtokens;
  int i;
    /* snew is real start of string after skipping leading delimiters */
  snew = s + strspn(s, delimiters);
		  /* create space for a copy of snew in t */
  if ((t = calloc(strlen(snew) + 1, sizeof(char))) == NULL) {
    *  argvp = NULL;
    numtokens = -1;
  } else {                     /* count the number of tokens in snew */
    strcpy(t, snew);
    if (strtok(t, delimiters) == NULL)
      numtokens = 0;
    else
      for (numtokens = 1; strtok(NULL, delimiters) != NULL;
	numtokens++)
	;
	  /* create an argument array to contain ptrs to tokens */
    if ((*argvp = calloc(numtokens + 1, sizeof(char *))) == NULL) {
     free(t);
     numtokens = -1;
    } else {            /* insert pointers to tokens into the array */
      if (numtokens > 0) {
	strcpy(t, snew);
	**argvp = strtok(t, delimiters);
	for (i = 1; i < numtokens + 1; i++)
	  *((*argvp) + i) = strtok(NULL, delimiters);
      } else {
	**argvp = NULL;
	free(t);
      }
    }
  }
  return numtokens;
}