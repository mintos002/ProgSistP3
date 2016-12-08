/**
* Para compilar teclea: gcc x.c -lpthread -o x
*/
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include "buffercircular.c"

#define INTPROD 20
#define INTCONS 20

void *Productor( void *arg ) // Funcion productor
{
 struct Buffer_Circ *buffer;
 buffer  = (struct Buffer_Circ*)arg;
 
 int w, ins, err;
 for(w=0; w < INTPROD; w++){
  ins = w+100;
  err = put_item(ins,buffer);
  if(err == -1){
   printf("OP: %d. Error al insertar %d\n", w, ins);
   printf("------------------------------------------------------------\n");

  }

  else {
   printf("OP: %d. Se ha INSERTADO el numero: %d\n --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- \n", w, ins);
   print(buffer);
  }
  usleep(1000000); // Retraso 2seg
 }
}

void *Consumidor( void *arg )  // Funcion consumidor
{
 struct Buffer_Circ *buffer;
 buffer  = (struct Buffer_Circ*)arg;

 int w, err;
 int val;
 for(w=0; w < INTCONS; w++){
  err = get_item(&val,buffer);
  if(err == -1){
   printf("OP: %d. Error al obtener %d\n", w, val);
   printf("------------------------------------------------------------\n");
  }

  else {
  printf("OP: %d. Se ha EXTRAIDO el numero: %d\n --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- \n", w, val);
   print(buffer);
  }
  usleep(4000000); // Retraso 4 seg
 }
}

int main()
{
 int x;
 int *xx;
 struct Buffer_Circ bc;  // Crear puntero buff y buff
 struct Buffer_Circ *pbc;

 pbc = &bc;              // Apuntar a buff
 initbuffer(pbc);        // Iniciar buffer

 pthread_attr_t atrib;
 pthread_t t_productor, t_consumidor;

 pthread_attr_init( &atrib );

 pthread_create( &t_productor, &atrib, Productor, pbc);
 pthread_create( &t_consumidor, &atrib, Consumidor, pbc);

 pthread_join( t_productor, NULL);
 pthread_join( t_consumidor, NULL);

 printf("FIN DE LA APLICACIÓN\n");
 return 0;
}
