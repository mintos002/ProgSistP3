#include <stdio.h>
#include <stdlib.h>

int NPROCESOS = 5;

int main (int argc, char *argv[]) {
 pid_t pid[NPROCESOS];
 int i, status;

 for(i=0; i<NPROCESOS; i++){
  pid[i]=fork();
  if(pid[i] == 0) { // hijo
   printf("Soy el proceso %ld y mi padre es %ld\n", (long)getpid(), (long)getppid() );
   sleep(20);
   exit(0);
  }
 }

 sleep(10); // padre
 return 0;
}
