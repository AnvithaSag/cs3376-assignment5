#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc, char **argv){
int status;
int childpid1;
int childpid2;
int childpid3;
char *cat_args[] = {"ls", "-ltr", NULL};
char *grep_args[] = {"grep", "3376", NULL};
char *wc_args[] = {"wc","-l", NULL};
// // create one pipe to send the output of "ls" process to "grep" process i
int pipes1[2],pipes2[2];
pipe(pipes1);
pipe(pipes2);
// // // fork the first child (to execute cat) 
 if((childpid1 = fork()) == -1){
 perror("Error creating a child process"); exit(1);
  }
  if (childpid1 == 0) {
  if(pipe(pipes2) == -1){
          perror("Error");
                  exit(0);
                  }
                  childpid2 = fork();
                  if(childpid2 == -1){
                  perror("Error creating fork 2");
                  exit(0);
                  }
                  if(childpid2 == 0){
		  childpid3 =fork();
		  if(childpid3 == -1){
		  perror("Error creating child");
		  exit(0);
		  }
		  if(childpid3 == 0){
                  close(pipes1[1]);
                  close(pipes1[0]);
                  close(pipes2[1]);
                  dup2(pipes2[0],0);
                  close(pipes2[0]);
                  execvp(*wc_args, wc_args);
                  }
                  else if(childpid3 ==1){
                  close(pipes1[1]);
                  dup2(pipes1[0], 0);
//                  // // close all pipes (very important!); end we're using was safely copied
                  close(pipes1[0]);
//                  //  
//                  //   
                  close(pipes1[1]);
                  execvp(*cat_args, cat_args);
                  exit(0);
                  
		}
		else{
		close(pipes1[0]);
		dup2(pipes1[1], 1);
		close(pipes1[1]);
		execvp(*grep_args, grep_args); }
		}}
                     
                       else {
exit(0);}
return(0);
                       }
