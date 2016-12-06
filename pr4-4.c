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
   sleep(2);
   exit(0);
  }
 }
 if(waitpid(pid[NPROCESOS-1],&status,0)==pid[NPROCESOS-1]){
  printf("El ustimo proceso ha terminado\n");
  return 0;
 }
}
