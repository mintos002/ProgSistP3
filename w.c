#include <stdio.h>
#include <stdlib.h>

int NPROCESOS = 5;

int main (void) {
 pid_t pid;
 int i, retorno;
 printf("\n");
 for(i=0; i<NPROCESOS; i++){
  pid=fork();
  if(pid != 0) { // padre
   printf("Soy el padre con valor de i: %d con PID: %ld y he creado a mi hijo con PID: %ld\n", i, (long)getpid(), (long)pid );
   sleep(2);
   break;
  }//if1
 else { printf("PATATA %d\n", i); }
 }//for

 if(i<NPROCESOS){
  retorno=wait();
  printf("Soy el padre con PID: %ld y el valor de retorno de mi hijo es: %ld\n", (long)getpid(), (long)WEXITSTATUS(retorno) );
  sleep(2);
  exit(0);
  return i;
 }
}
