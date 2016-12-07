/**
* Para compilar teclea: gcc x.c -lpthread -o x
*/
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include "buffercircular.c"

#define INTPROD 11
#define INTCONS 11
#define NP 9

void *Productor( void *arg ) // Funcion productor
{
 struct Buffer_Circ *buffer;
 buffer  = (struct Buffer_Circ*)arg;
 
 int w, err;
 for(w=0; w < INTPROD; w++){
  err = put_item(w,buffer);
  if(err == -1){
   printf("Error al insertar %d\n", w);
  }

  else {
   printf("Se ha insertado el numero: %d\n--- --- --- --- --- ---\n", w);
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
 int *val;
 for(w=0; w < INTCONS; w++){
  err = get_item(val,buffer);
  if(err == -1){
   printf("Error al obtener %d\n", *val);
  }

  else {
  printf("Se ha extraido el numero: %d\n--- --- --- --- --- ---\n", *val);
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
// pthread_create( &t_consumidor, &atrib, Consumidor, pbc);

 pthread_join( t_productor, NULL);
// pthread_join( t_consumidor, NULL);

 printf("FIN DE LA APLICACIÓN");
 return 0;
}
