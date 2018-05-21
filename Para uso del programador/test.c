#include <stdio.h>

int cuadrado(int max, int flag)
{
  /*
    notas de cuadrado:
                        1- para iniciar
                        0- para cerrar
                        2- solo linea
                        3- un cuadro sin salto de linea y sin espacio
                        nunca agregar \n
  */
  int i;
  switch (flag)
  {
    case 1:
            for (i=0;i<max+4;i++)
              printf("%c",219);
            printf("\n");
            printf("%c ",219);
            break;

    case 0:
            printf(" %c ",219);
            printf("\n");
            for (i=0;i<max+4;i++)
              printf("%c",219);
            printf("\n");
            break;

    case 2:
            for (i=0;i<max;i++)
              printf("%c",219);
            printf("\n");
            break;
    case 3:
            for (i=0;i<max;i++)
              printf("%c",219);
            break;

    default:
            for (i=0;i<3;i++)
              printf("%c",219);
            printf("Error");
            for (i=0;i<3;i++)
              printf("%c",219);
            break;
  }
}
int main ()
{
  cuadrado(34,1);
  printf("Este es un texto en pseudo-ventana");
  cuadrado(34,0);

  printf("Debajo de este texto se encuentra una raya de estos caracteres\n");
  cuadrado(62,2);

  printf("En exte texto se encuenta solo el caracter ascii repetido 4 veces");
  cuadrado(4,3);
}
