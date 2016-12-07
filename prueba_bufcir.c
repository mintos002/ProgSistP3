#include <stdio.h>
#include "buffercircular.c"

// Main
main () {
 int i, c, *x;
 struct Buffer_Circ bf;
 struct Buffer_Circ *p;
 char * akan;

 p = &bf;
 initbuffer(p);
 // print
 print(p);
 // prueba metodos ---
 akan = bc_vacio(p);
 printf("Bucle vacio?: %s\n", akan); 
 akan = bc_lleno(p);
 printf("Bucle lleno?: %s\n", akan);
 c = num_elementos(p);
 printf("Numero de elementos: %d\n" ,c);
 printf("------------------------------\n");

 // 5 inserciones de datos
 ok = put_item( 11, p );
 ok = put_item( 22, p );
 ok = put_item( 33, p );
 ok = put_item( 44, p );
 ok = put_item( 55, p );
 printf("5 inserciones.\n");
 print(p);
 // 5 extracciones de datos
 ok = get_item( x, p );
 ok = get_item( x, p );
 ok = get_item( x, p );
 ok = get_item( x, p );
 ok = get_item( x, p );
 printf("5 extracciones.\n");
 print(p);
 // 5 inserciones de datos
 ok = put_item( 66, p );
 ok = put_item( 77, p );
 ok = put_item( 88, p );
 ok = put_item( 99, p );
 ok = put_item( 1010, p );
 printf("5 inserciones.\n");
 print(p);

 // prueba metodos ---
 akan = bc_vacio(p);
 printf("Bucle vacio?: %s\n", akan);
 akan = bc_lleno(p);
 printf("Bucle lleno?: %s\n", akan);
 c = num_elementos(p);
 printf("Numero de elementos: %d\n",c);
 printf("------------------------------\n");

 // 2 extracciones de datos
 ok = get_item( x, p );
 ok = get_item( x, p );
 printf("2 extracciones.\n");
 print(p);

 // 1 inserciones de datos
 ok = put_item( 1111, p );
 printf("1 insercion.\n");
 print(p);

 // 1 extracciones de datos
 ok = get_item( x, p );
 printf("1 extracción.\n");
 print(p);
 
}

