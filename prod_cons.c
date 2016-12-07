/**
* Para compilar teclea: gcc hola.c -lpthread -o hola
**/

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include "buffercircular.c"

void *Imprime( void *ptr )
{
 char *men;
 men=(char*)ptr;

 write(1,men,strlen(men));
}

int main()
{
 int x;
 int *xx;
 struct Buffer_Circ bc;  // Crear puntero buff y buff
 struct Buffer_Circ *pbc;

 pbc = &bc;              // Apuntar a buff
 initbuffer(pbc);        // Iniciar buffer
 print(pbc);

 pthread_attr_t atrib;
 pthread_t productor, consumidor;

 pthread_attr_init( &atrib );

 pthread_create( &productor, &atrib, put_item, pbc);
 pthread_create( &consumidor, &atrib, get_item, pbc);

 pthread_join( productor, NULL);
 pthread_join( consumidor, NULL);
 printf("fin aplicación");
}
